#include "geometry.h"
namespace Geometry
{
	double Ellipse::calcArea()
	{
		double area = M_PIA * pow(radius, 2);
		return  area;
	}
	double Ellipse::calcCircumferenceLength()
	{
		double C = 2 * M_PIA * radius;
		return C;
	}
}