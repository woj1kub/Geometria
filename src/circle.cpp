#include "geometry.h"
namespace Geometry
{
	double Circle::calcArea()
	{
		double area = M_PI * pow(radius, 2);
		return  area;
	}
	double Circle::calcCircumferenceLength()
	{
		double C = 2 * M_PI * radius;
		return C;
	}
}
