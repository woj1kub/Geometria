#include <vector>
#include <iostream>
#include <cmath>
#include "geometry.h"
namespace Geometry
{
    Square::Square(Vertex* vertices, int len) : Rectangle(vertices, len) {
        if (len != 4) {
            throw std::invalid_argument("Kwadrat musi sk³adaæ siê dok³adnie z 4 punktów.");
        }
    }

    bool Square::isSquare() const {
        
        if (vertices.size() != 4) {
            return false;
        }
        
        std::vector<double> sides(4);
        std::vector<double> diagonals(2);

        for (int i = 0; i < 4; ++i) {
            sides[i] = distance(vertices[i], vertices[(i + 1) % 4]);
        }

        diagonals[0] = distance(vertices[0], vertices[2]);
        diagonals[1] = distance(vertices[1], vertices[3]);

        if (!(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])) {
            return false;
        }

        if (diagonals[0] != diagonals[1]) {
            return false;
        }

        return true;
    }

    

    // Metoda obliczaj¹ca promieñ okrêgu opisanego na kwadracie
    double Square::calcCircumscribedCircleRadius() const {
        return distance(vertices[0], vertices[2]) / 2.0;
    }

    // Metoda obliczaj¹ca promieñ okrêgu wpisanego w kwadrat
    double Square::calcInscribedCircleRadius() const {
        return distance(vertices[0], vertices[1]) / 2.0;
    }
}