#include "geometry.h"
namespace Geometry
{
    Ellipse::Ellipse(Vertex c, double a, double b)
    {
        A = 0;
        B = 0;
        if (a <= 0 || b <=0)
        {
            cerr << "Radius needs to be ";
            return;
        }
        center = c;
        if (a>b)
        {
            this->A = a;
            this->B = b;
        }
        else
        {
            this->A = b;
            this->B = a;
        }
    }
    
    double Ellipse::calcArea()
	{
		double area = M_PI * A * B;
		return  area;
	}
	double Ellipse::calcCircumferenceLength()
	{
        double h = pow(A - B, 2) / pow(A + B, 2);
        double Circumference = M_PI * (A + B) * (1 + ((3 * h) / (10 + sqrt(4 - 3 * h))));
		return Circumference;
	}

    bool Ellipse::vertexIn(Vertex v)
    {
        //x^2 / a^2 + y^2 / b^2 = 1
        double value = (pow(v.getX() - center.getX(), 2) / pow(A, 2)) + (pow(v.getY() - center.getY(), 2) / pow(B, 2));
        if (value<=1)
            return true;
        return false;
    }

    bool Ellipse::vertexOn(Vertex v)
    {
        //x^2 / a^2 + y^2 / b^2 = 1
        double value = (pow(v.getX()-center.getX(), 2) / pow(A, 2)) + (pow(v.getY() - center.getY(), 2) / pow(B, 2));
        if (value == 1)
            return true;
        return false;
    }

    double Ellipse::circumferenceOfArc(double angle)
    {
        return ((angle / 360) * calcCircumferenceLength());
    }

    double Ellipse::areaOfArc(double angle)
    {
        return ((angle / 360) * calcArea());
    }

    std::ostream& operator<<(std::ostream& stream, const Ellipse& ellipse)
    {
        stream << ellipse.center << " " << ellipse.A << " " << ellipse.B << endl;
        return stream;
    }
}