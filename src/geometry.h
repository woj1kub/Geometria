/**
 * @file geometry.h
 * @author Wojciech Kubowicz, Damian Barczak, Maciej Wielgosz
 * @brief
 * @version 1.0
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <vector>
#include <iostream>
#include <cmath>
// constexpr auto M_PI = 3.141592;

using namespace std;
namespace Geometry
{
    class Vertex
    {
    private:
        double x, y;

    public:
        Vertex() : x(0.0), y(0.0) {}
        Vertex(double x, double y) : x(x), y(y) {}
        double getX() const { return x; };
        double getY() const { return y; };
        friend std::ostream &operator<<(std::ostream &stream, const Vertex &vertex);
    };

    class Line
    {
    private:
        Vertex start_point, end_point;

    public:
        Line(Vertex st_pt, Vertex end_pt) : start_point(st_pt), end_point(end_pt) {}
        Line(double x1, double y1, double x2, double y2);
        Vertex getStart() const { return start_point; };
        Vertex getEnd() const { return end_point; };
        double calcLength();
        Vertex calcCrosspoint(Line &secondLine);
        bool vertexOnLine(Vertex &vertex);
        friend std::ostream &operator<<(std::ostream &stream, const Line &line);
    };

    class GeometricFigure
    {
    protected:
        std::vector<Vertex> vertices;

    private:
        void arangeVertices();
        void deleteDuplicateVertices();
        int orientation(Vertex p, Vertex q, Vertex r);

    public:
        const vector<Vertex> &getVertices() const { return vertices; }
        GeometricFigure(Vertex *vertices, int len);
        GeometricFigure(double **arr, int len);
        double calcArea();
        double calcCircumferenceLength();
        int numberOfVertices();
        bool addVertex(Vertex vertex);
        bool deleteVertex(int index);
        static double distance(const Vertex &v1, const Vertex &v2) { return sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2)); }
        friend std::ostream &operator<<(std::ostream &stream, const GeometricFigure &figure);
    };
    class Ellipse
    {
    protected:
        double A;
        double B;
        Vertex center;

    public:
        Ellipse(Vertex c, double a, double b);
        double getA() const { return A; };
        double getB() const { return B; };
        Vertex getCenter() const { return center; };
        double calcArea();
        virtual double calcCircumferenceLength();

        bool vertexIn(Vertex v);
        bool vertexOn(Vertex v);
        double circumferenceOfArc(double angle);
        double areaOfArc(double angle);
        friend std::ostream &operator<<(std::ostream &stream, const Ellipse &figure);
    };
    class Circle : public Ellipse
    {
    public:
        Circle(Vertex c, double r)
            : Ellipse(c, r, r)
        {
        }
        double getRadius() const { return A; };
        double calcCircumferenceLength();
    };

    class Rectangle : public GeometricFigure
    {
    public:
        Rectangle(Vertex *vertices, int len);
        bool isRectangle() const;
        double calcDiagonalLength() const;
        Vertex calcCenter() const;

    private:
        double dotProduct(const Vertex &a1, const Vertex &a2, const Vertex &b1, const Vertex &b2) const;
    };

    class Square : public Rectangle
    {
    private:
    public:
        Square(Vertex *vertices, int len);
        bool isSquare() const;
        double calcCircumscribedCircleRadius() const;
        double calcInscribedCircleRadius() const;
    };

    class Triangle : public GeometricFigure
    {
    private:
    public:
        Triangle(Vertex *vertices, int len);
        bool isTriangle() const;
        double calcCircumscribedCircleRadius();
        double calcInscribedCircleRadius();
        Vertex calcCentroid() const;
        double calcHeightRelativeToSideAB();
    };

    class Rhombus : public GeometricFigure
    {
    private:
        static double calcSlope(const Vertex &v1, const Vertex &v2);
        static bool areEqual(double a, double b, double tolerance = 1e-6);

    public:
        Rhombus(Vertex *vertices, int len);
        bool isRhombus() const;
        double calcDiagonalsRatio() const;
    };

    class Trapezoid : public GeometricFigure
    {
    private:
        // Funkcja pomocnicza do obliczania nachylenia mi�dzy dwoma punktami
        static double calcSlope(const Vertex &v1, const Vertex &v2);
        // Funkcja do sprawdzania r�wno�ci dw�ch nachyle� z pewn� tolerancj�
        static bool areEqual(double a, double b, double tolerance = 1e-6);

    public:
        Trapezoid(Vertex *vertices, int len);
        bool isTrapezoid() const;
        double calcMedianLength() const;
        double calcHeight();
    };

} // namespace Geometry