#include <cmath>
#include "geometry.h"
namespace Geometry
{
    Line::Line(double x1, double y1, double x2, double y2)
    {
        start_point = Vertex(x1, y1);
        end_point = Vertex(x2, y2);
    }
    double Geometry::Line::calcLength()
    {
        //d = √((x_2 - x_1)² + (y_2 - y_1)²)
        double Length = sqrt(pow(end_point.getX() - start_point.getX()) + pow(end_point.getY() - start_point.getY()));
        return Length;
    }

    Vertex Line::calcCrosspoint(Line& secondLine)
    {
        Vertex cross;
        double x1 = start_point.getX(), y1 = start_point.getY();
        double x2 = end_point.getX(), y2 = end_point.getY();
        Vertex secondLineStart = secondLine.getStart();
        Vertex secondLineEnd = secondLine.getEnd();

        double x3 = secondLineStart.getX(), y3 = secondLineStart.getY();
        double x4 = secondLineEnd.getX(), y4 = secondLineEnd.getY();

        // Sprawdź czy linie są równoległe
        if ((x1 - x2) * (y3 - y4) == (y1 - y2) * (x3 - x4)) {
            std::cout << "Linie są równoległe, brak punktu przecięcia." << std::endl;
            return intersection;
        }

        double x_cross= ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        double y_cross = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        cross = Vertex(x_cross, y_cross);
        return cross;
    }

} // namespace Geometry

