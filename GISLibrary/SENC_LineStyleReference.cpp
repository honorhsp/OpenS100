#include "stdafx.h"
#include "SENC_LineStyleReference.h"

#include "..\\PortrayalCatalogue\\S100_LineStyleReference.h"
#include "..\\PortrayalCatalogue\\PortrayalCatalogue.h"
#include "..\\S100Geometry\\SCurveHasOrient.h"
#include "..\\S100Geometry\\SCurve.h"
#include "..\\GeoMetryLibrary\\Scaler.h"

SENC_LineStyleReference::SENC_LineStyleReference()
{
	type = 2;
}

SENC_LineStyleReference::~SENC_LineStyleReference()
{

}

void SENC_LineStyleReference::GetStyleFromS100(S100_LineStyleReference* lineStyle, S100_SVG_D2D1_DLL::SVGManager *svgMgr)
{
	SetReference(lineStyle->GetReference());
}

void SENC_LineStyleReference::SetReference(std::wstring& value)
{
	reference = value;
}

std::wstring SENC_LineStyleReference::GetReference()
{
	return reference;
}

void SENC_LineStyleReference::DrawInstruction(
	SCurveHasOrient* curveHasOrient,
	ID2D1DCRenderTarget* rt,
	ID2D1Factory1* pDirect2dFactory,
	ID2D1SolidColorBrush* brush,
	std::vector<ID2D1StrokeStyle1*>* strokeGroup,
	Scaler *scaler,
	PortrayalCatalogue* pc)
{
	auto curve = curveHasOrient->GetCurve();

	auto numPoints = curve->GetNumPoints();

	auto d2Points = new D2D1_POINT_2F[numPoints];

	for (int pi = 0; pi < numPoints; pi++)
	{
		scaler->WorldToDevice_F(
			curve->GetX(pi),
			curve->GetY(pi),
			&d2Points[pi].x,
			&d2Points[pi].y);
	}

	auto s100PCManager = pc->GetS100PCManager();

	if (s100PCManager)
	{
		IWICBitmap* pIWICBitmap = s100PCManager->GetLineImage(GetReference() + _T(".xml"));
		if (pIWICBitmap)
		{
			ID2D1Bitmap* pBitmap = nullptr;
			HRESULT hr = rt->CreateBitmapFromWicBitmap(pIWICBitmap, &pBitmap);

			if (!SUCCEEDED(hr))
			{
				OutputDebugString(_T("Failed to create bitmap\n"));
			}
			else
			{
				pc->GetS100Render().DrawBitmapOnPolyline(rt, d2Points, numPoints, pBitmap, scaler->GetD2Rect());
				SafeRelease(&pBitmap);
			}
		}
	}

	delete[] d2Points;
	d2Points = nullptr;
}