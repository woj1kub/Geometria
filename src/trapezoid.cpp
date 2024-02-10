#include <vector>
#include <iostream>
#include <cmath>
#include "geometry.h"
namespace Geometry
{
    Trapezoid::Trapezoid(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
        if (len != 4) {
            throw std::invalid_argument("Trapez musi sk³adaæ siê dok³adnie z 4 punktów.");
        }
    }

    // Metoda obliczaj¹ca d³ugoœæ œrodkowej trapezu
    double Trapezoid::calcMedianLength() const {
        double a = distance(vertices[0], vertices[1]);
        double b = distance(vertices[2], vertices[3]);
        return (a + b) / 2.0;
    }

    double Trapezoid::calcHeight() {
        double base1 = distance(vertices[0], vertices[1]);
        double base2 = distance(vertices[2], vertices[3]);
        double area = calcArea();

        // Obliczenie wysokoœci na podstawie pola i podstaw
        return (2 * area) / (base1 + base2);
    }

    bool Trapezoid::areEqual(double a, double b, double tolerance = 1e-6) {
        return std::fabs(a - b) < tolerance;
    }

    double Trapezoid::calcSlope(const Vertex& v1, const Vertex& v2) {
        // Aby unikn¹æ dzielenia przez zero, sprawdzenie, czy x1 == x2
        if (std::fabs(v1.getX() - v2.getX()) < std::numeric_limits<double>::epsilon()) {
            return std::numeric_limits<double>::infinity(); // Pionowa linia
        }
        return (v2.getY() - v1.getY()) / (v2.getX() - v1.getX());
    }

    bool Trapezoid::isTrapezoid() const {
        // Oblicz nachylenie dla ka¿dego z boków
        double slope1 = calcSlope(vertices[0], vertices[1]);
        double slope2 = calcSlope(vertices[1], vertices[2]);
        double slope3 = calcSlope(vertices[2], vertices[3]);
        double slope4 = calcSlope(vertices[3], vertices[0]);

        // SprawdŸ, czy co najmniej jedna para przeciwleg³ych boków jest równoleg³a
        bool parallelSides = (areEqual(slope1, slope3) || areEqual(slope2, slope4));
        return parallelSides;
    }
}