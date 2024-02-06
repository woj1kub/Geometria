#include "geometry.h"
namespace Geometry
{
    Ellipse::Ellipse(Vertex c, double a, double b)
    {
        center = c;
        if (a>b)
        {
            this->a = a;
            this->b = b;
        }
        else
        {
            this->a = b;
            this->b = a;
        }
    }
    
    double Ellipse::calcArea()
	{
		double area = M_PI *a*b;
		return  area;
	}
	double Ellipse::calcCircumferenceLength()
	{
        double Circumference = M_PI* (3 * (a + b) / 2 - pow(a * b, 1 / 2));
		return Circumference;
	}
}