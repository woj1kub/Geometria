#include <vector>
#include <iostream>
#include <cmath>
#include "geometry.h"
namespace Geometry
{
    bool Triangle::isTriangle() const {
        if (vertices.size() != 3) {
            return false;
        }

        double orientation = (vertices[1].getY() - vertices[0].getY()) * (vertices[2].getX() - vertices[1].getX()) -
            (vertices[1].getX() - vertices[0].getX()) * (vertices[2].getY() - vertices[1].getY());

        return fabs(orientation) > std::numeric_limits<double>::epsilon(); // Zwraca false, jeœli orientacja jest bliska zero (punkty wspó³liniowe)
    }


}