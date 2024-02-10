#include <vector>
#include <iostream>
#include <cmath>
#include "geometry.h"
namespace Geometry
{
    Rectangle::Rectangle(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
        if (len != 4) {
            throw std::invalid_argument("Prostok¹t musi sk³adaæ siê dok³adnie z 4 punktów.");
        }
    }

    bool Rectangle::isRectangle() const {
        if (vertices.size() != 4) {
            return false; 
        }

        
        double sideLengths[4] = {
            distance(vertices[0], vertices[1]),
            distance(vertices[1], vertices[2]),
            distance(vertices[2], vertices[3]),
            distance(vertices[3], vertices[0])
        };

        // Obliczanie iloczynu skalarnego dla ka¿dej pary s¹siednich boków
        double dotProducts[4] = {
            dotProduct(vertices[0], vertices[1], vertices[1], vertices[2]),
            dotProduct(vertices[1], vertices[2], vertices[2], vertices[3]),
            dotProduct(vertices[2], vertices[3], vertices[3], vertices[0]),
            dotProduct(vertices[3], vertices[0], vertices[0], vertices[1])
        };

        // Sprawdzanie równoœci d³ugoœci przeciwleg³ych boków oraz k¹tów prostych
        bool sidesEqual = sideLengths[0] == sideLengths[2] && sideLengths[1] == sideLengths[3];
        bool rightAngles = dotProducts[0] == 0 && dotProducts[1] == 0 && dotProducts[2] == 0 && dotProducts[3] == 0;

        return sidesEqual && rightAngles;
    }

    double Rectangle::dotProduct(const Vertex& a1, const Vertex& a2, const Vertex& b1, const Vertex& b2) const {
        double vectorA_x = a2.getX() - a1.getX();
        double vectorA_y = a2.getY() - a1.getY();
        double vectorB_x = b2.getX() - b1.getX();
        double vectorB_y = b2.getY() - b1.getY();
        return vectorA_x * vectorB_x + vectorA_y * vectorB_y;
    }

    double Rectangle::calcDiagonalLength() const {
        return distance(vertices[0], vertices[2]);
    }

    Vertex Rectangle::calcCenter() const {
        double centerX = (vertices[0].getX() + vertices[2].getX()) / 2.0;
        double centerY = (vertices[0].getY() + vertices[2].getY()) / 2.0;
        return Vertex(centerX, centerY);
    }
}