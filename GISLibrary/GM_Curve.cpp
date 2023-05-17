#include "stdafx.h"
#include "GM_Curve.h"

namespace GM
{
	Curve::Curve()
	{
		segment.push_back(CurveSegment());
	}

	Curve::~Curve()
	{

	}

	GeometryType Curve::GetType()
	{
		return GeometryType::Curve;
	}

	void Curve::Add(double x, double y)
	{
		segment.front().controlPoints.push_back(DirectPosition(x, y));
	}
}