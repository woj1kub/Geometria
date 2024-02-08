/**
 * @file geometry.h
 * @author Wojciech Kubowicz, Damian Barczak, Maciej Wielgosz
 * @brief
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;
namespace Geometry {
    /**
     * @class Vertex
     * @brief Base for all geometric figures
     *
     * This class represents singular point in 2d geometric figure
     */
    class Vertex {
        private:
            double x, y;
        public:
            Vertex() : x(0.0), y(0.0) {}
            Vertex(double x, double y) : x(x), y(y) {}
            double getX(){ return x; };
            double getY(){ return y; };
    };

    class Line {
        private:
            Vertex start_point, end_point;
        public:
            Line(Vertex st_pt, Vertex end_pt) : start_point(st_pt), end_point(end_pt) {}
            Line(double x1, double y1, double x2, double y2);
            Vertex getStart() { return start_point; };
            Vertex getEnd() { return end_point; };
            double calcLength();
            Vertex calcCrosspoint(Line &secondLine);
            bool vertexOnLine(Vertex &vertex);

    };

    class GeometricFigure {
        private:
            std::vector<Vertex> vertices;
            void arangeVertices();
            void deleteDuplicateVertices();
            int orientation(Vertex p, Vertex q, Vertex r);
        public:
            GeometricFigure(Vertex* vertices, int len);
            GeometricFigure(double **arr, int len);
            double calcArea();
            double calcCircumferenceLength();
            int numberOfVertices();
            bool addVertex(Vertex vertex);
            bool deleteVertex(int index);
    };
    class Ellipse
    {
    private:
        double a;
        double b;
        Vertex center;
    public:
        Ellipse(Vertex c, double a, double b);
        double getA() { return a; };
        double getB() { return b; };
        Vertex getCenter() { return center; };
        double calcArea();
        virtual double calcCircumferenceLength();

    };
    class Circle: public Ellipse
    {
    public:
        Circle(Vertex c, double r)
            : Ellipse(c,r, r)
        {}
        double getRadius() { return Ellipse::getA(); };
        Vertex getCenter() { return Ellipse::getCenter(); };
        double calcCircumferenceLength();
    };
    
} // namespace Geometry