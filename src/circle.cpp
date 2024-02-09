#include "geometry.h"
namespace Geometry
{
	double Circle::calcCircumferenceLength()
	{
		double C = 2 * M_PI * Ellipse::getA();
		return C;
	}
	bool Circle::vertexIn(Vertex v)
	{
		return false;
	}
	bool Circle::vertexOn(Vertex v)
	{
		return false;
	}
}
