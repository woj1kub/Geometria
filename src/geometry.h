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
            double getX() const { return x; };
            double getY() const { return y; };
            friend std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);
    };

    class Line {
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
            friend std::ostream& operator<<(std::ostream& stream, const Line& line);

    };

    class GeometricFigure {
        protected:
            std::vector<Vertex> vertices;
        private:
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
            friend std::ostream& operator<<(std::ostream& stream, const GeometricFigure& figure);
    };
    class Ellipse
    {
    private:
        double a;
        double b;
        Vertex center;
    public:
        Ellipse(Vertex c, double a, double b);
        double getA() const { return a; };
        double getB() const { return b; };
        Vertex getCenter() const { return center; };
        double calcArea();
        virtual double calcCircumferenceLength();
        
        bool vertexIn(Vertex v);
        bool vertexOn(Vertex v);
        double circumferenceOfArc(double angle);
        double areaOfArc(double angle);
    };
    class Circle: public Ellipse
    {
    public:
        Circle(Vertex c, double r)
            : Ellipse(c,r, r)
        {}
        double getRadius() const { return Ellipse::getA(); };
        double calcCircumferenceLength();
    };
    

    class Square : public GeometricFigure {
    private:
        static double distance(const Vertex& v1, const Vertex& v2) { return sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2)); }
    public:
        Square(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
            if (len != 4) {
                throw std::invalid_argument("Kwadrat musi sk³adaæ siê dok³adnie z 4 punktów.");
            }
        }
        Square(double** arr, int len) : GeometricFigure(arr, len) {
        }
        bool isSquare() const;
    };

    class Triangle : public GeometricFigure {
    private:
        static double distance(const Vertex& v1, const Vertex& v2) { return sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2)); }
    public:
        /*Triangle(Vertex v1, Vertex v2, Vertex v3) {
            vertices.push_back(v1);
            vertices.push_back(v2);
            vertices.push_back(v3);
        }*/
        Triangle(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
            if (len != 3) {
                throw std::invalid_argument("Trójk¹t musi sk³adaæ siê dok³adnie z 3 punktów.");
            }
        }
        bool isTriangle() const;
    };

    class Rectangle : public GeometricFigure {
    public:
        Rectangle(Vertex* vertices, int len) : GeometricFigure(vertices, len) {
            if (len != 4) {
                throw std::invalid_argument("Prostok¹t musi sk³adaæ siê dok³adnie z 4 punktów.");
            }
        }
        bool isRectangle() const;

    private:
        static double distance(const Vertex& v1, const Vertex& v2) { return sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2)); }
    };

} // namespace Geometry