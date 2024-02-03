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
        double Length = sqrt(pow(end_point.getX() - start_point.getX(),2) + pow(end_point.getY() - start_point.getY(),2));
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
            cout << "Lini(e są równoległe, brak punktu przecięcia." << endl;
            return Vertex();
        }

        double x_cross= ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        double y_cross = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        cross = Vertex(x_cross, y_cross);
        return cross;
    }

    bool Line::vertexOnLine(Vertex& vertex)
    {
        double a = (end_point.getY() - start_point.getY()) / (end_point.getX() - start_point.getX());
        double b = start_point.getY() - (a * start_point.getX()) ;
        
        if ((a * vertex.getX() + b) == vertex.getY())
            return true;

        const double epsilon = 1e-9;

        // Sprawdź, czy punkt należy do przedziału na osi X
        bool xInRange = (vertex.getX() >= std::min(start_point.getX(), end_point.getX()) - epsilon) &&
            (vertex.getX() <= std::max(start_point.getX(), end_point.getX()) + epsilon);

        // Sprawdź, czy punkt należy do przedziału na osi Y
        bool yInRange = (vertex.getY() >= std::min(start_point.getY(), end_point.getY()) - epsilon) &&
            (vertex.getY() <= std::max(start_point.getY(), end_point.getY()) + epsilon);

        // Sprawdź, czy punkt leży na linii z uwzględnieniem marginesu błędu
        if (xInRange && yInRange && fabs(a * vertex.getX() + b - vertex.getY()) < epsilon)
            return true;

        return false;
    }

} // namespace Geometry

