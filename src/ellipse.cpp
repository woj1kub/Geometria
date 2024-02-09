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

    bool Ellipse::vertexIn(Vertex v)
    {
        //x^2 / a^2 + y^2 / b^2 = 1
        double value = (pow(v.getX() - center.getX(), 2) / pow(a, 2)) - (pow(v.getY() - center.getY(), 2) / pow(b, 2));
        if (value<=1)
            return true;
        return false;
    }

    bool Ellipse::vertexOn(Vertex v)
    {
        //x^2 / a^2 + y^2 / b^2 = 1
        double value = (pow(v.getX()-center.getX(), 2) / pow(a, 2)) - (pow(v.getY() - center.getY(), 2) / pow(b, 2));
        if (value == 1)
            return true;
        return false;
    }

    double Ellipse::arcOfCircumference(double angle)
    {
        return ((angle / 360) * calcCircumferenceLength());
    }

    double Ellipse::arcOfArea(double angle)
    {
        return ((angle / 360) * calcArea());
    }
    
}