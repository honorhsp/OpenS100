-- Converter Version: 0.99
-- Feature Catalogue Version: 1.0.0 (2019/4/9)

-- Referenced portrayal rules.
require 'RESTRN01'

-- Traffic separation scheme roundabout main entry point.
function TrafficSeparationSchemeRoundabout(feature, featurePortrayal, contextParameters)
	if feature.PrimitiveType == PrimitiveType.Surface and contextParameters.PlainBoundaries then
		featurePortrayal:AddInstructions('ViewingGroup:25010;DrawingPriority:18;DisplayPlane:UnderRADAR')
		featurePortrayal:AddInstructions('PointInstruction:TSSRON51')
		RESTRN01(feature, featurePortrayal, contextParameters)
	elseif feature.PrimitiveType == PrimitiveType.Surface then
		featurePortrayal:AddInstructions('ViewingGroup:25010;DrawingPriority:18;DisplayPlane:UnderRADAR')
		featurePortrayal:AddInstructions('AreaFillReference:TSSJCT02')
		featurePortrayal:AddInstructions('PointInstruction:TSSRON51')
		RESTRN01(feature, featurePortrayal, contextParameters)
	else
		error('Invalid primitive type or mariner settings passed to portrayal')
	end
end
