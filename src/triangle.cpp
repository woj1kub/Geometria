#include <vector>
#include <iostream>
#include <cmath>
#include "geometry.h"
namespace Geometry
{
    Triangle::Triangle(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
        if (len != 3) {
            throw std::invalid_argument("Trójk¹t musi sk³adaæ siê dok³adnie z 3 punktów.");
        }
    }

    bool Triangle::isTriangle() const {
        if (vertices.size() != 3) {
            return false;
        }

        double orientation = (vertices[1].getY() - vertices[0].getY()) * (vertices[2].getX() - vertices[1].getX()) -
            (vertices[1].getX() - vertices[0].getX()) * (vertices[2].getY() - vertices[1].getY());

        return fabs(orientation) > std::numeric_limits<double>::epsilon(); // Zwraca false, jeœli orientacja jest bliska zero (punkty wspó³liniowe)
    }

    double Triangle::calcCircumscribedCircleRadius() {
        double a = distance(vertices[0], vertices[1]);
        double b = distance(vertices[1], vertices[2]);
        double c = distance(vertices[2], vertices[0]);
        double s = calcCircumferenceLength() / 2.0;
        double area = calcArea();
        return (a * b * c) / (4.0 * area);
    }

    double Triangle::calcInscribedCircleRadius() {
        double area = calcArea();
        double s = calcCircumferenceLength() / 2.0;
        return area / s;
    }

    Vertex Triangle::calcCentroid() const {
        double x = (vertices[0].getX() + vertices[1].getX() + vertices[2].getX()) / 3.0;
        double y = (vertices[0].getY() + vertices[1].getY() + vertices[2].getY()) / 3.0;
        return Vertex(x, y);
    }

    double Triangle::calcHeightRelativeToSideAB() {
        double baseLength = distance(vertices[1], vertices[2]);
        double area = calcArea();
        double height = (2 * area) / baseLength; // Obliczenie wysokoœci z wzoru na pole trójk¹ta: P = 1/2 * base * height
        return height;
    }
}