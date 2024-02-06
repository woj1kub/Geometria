#include "geometry.h"
namespace Geometry
{
	double Circle::calcCircumferenceLength()
	{
		double C = 2 * M_PI * Ellipse::getA();
		return C;
	}
}
