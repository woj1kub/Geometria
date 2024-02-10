#include <vector>
#include <iostream>
#include <cmath>
#include "geometry.h"
namespace Geometry
{
	Rhombus::Rhombus(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
		if (len != 4) {
			throw std::invalid_argument("Romb musi sk³adaæ siê dok³adnie z 4 punktów.");
		}
	}

    static double calcSlope(const Vertex& v1, const Vertex& v2) {
        if (fabs(v2.getX() - v1.getX()) < std::numeric_limits<double>::epsilon()) {
            return std::numeric_limits<double>::infinity(); // Pionowa linia
        }
        return (v2.getY() - v1.getY()) / (v2.getX() - v1.getX());
    }

    static bool areEqual(double a, double b, double tolerance = 1e-6) {
        return fabs(a - b) < tolerance;
    }

    bool Rhombus::isRhombus() const {

        double side1 = distance(vertices[0], vertices[1]);
        double side2 = distance(vertices[1], vertices[2]);
        double side3 = distance(vertices[2], vertices[3]);
        double side4 = distance(vertices[3], vertices[0]);

        bool allSidesEqual = areEqual(side1, side2) && areEqual(side2, side3) && areEqual(side3, side4);

        // Obliczenie nachylenia boków, aby sprawdziæ równoleg³oœæ
        double slope1 = calcSlope(vertices[0], vertices[1]);
        double slope2 = calcSlope(vertices[1], vertices[2]);
        double slope3 = calcSlope(vertices[2], vertices[3]);
        double slope4 = calcSlope(vertices[3], vertices[0]);

        // Sprawdzenie, czy przeciwleg³e boki s¹ równoleg³e
        bool oppositeSidesParallel = areEqual(slope1, slope3) && areEqual(slope2, slope4);

        return allSidesEqual && oppositeSidesParallel;
    }

    double Rhombus::calcDiagonalsRatio() const {
        double d1 = distance(vertices[0], vertices[2]);
        double d2 = distance(vertices[1], vertices[3]);
        return d1 / d2;
    }
}