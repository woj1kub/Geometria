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
#include <vector>

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
        private:
            Vertex() : x(0.0), y(0.0) {}
            Vertex(double x, double y) : x(x), y(y) {}
    };

    class Line {
        private:
            Vertex start_point, end_point;
        public:
            Line(Vertex st_pt, Vertex end_pt);
            Line(double x1, double y1, double x2, double y2);
            double calcLength();
            Vertex calcCrosspoint(Line &secondLine);
            bool vertexOnLine(Vertex &vertex);
    };

    class GeometricFigure {
        private:
            std::vector<Vertex> vertices;
            void arangeVertices();
        public:
            GeometricFigure(Vertex vertices[], int len);
            GeometricFigure(double **arr, int len);
            double calcArea();
            double calcCircumferenceLength();
    };
} // namespace Geometry