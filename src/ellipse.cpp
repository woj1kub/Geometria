#include "geometry.h"
namespace Geometry
{
    Ellipse::Ellipse(Vertex c, double a, double b)
        : GeometricFigure(&c, 1)
    {
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
		double Circumference = M_PI * a * b;
		Circumference += pow(a - b, 2);
		Circumference /= a + b;
		Circumference *= 4;
		return Circumference;
	}
}