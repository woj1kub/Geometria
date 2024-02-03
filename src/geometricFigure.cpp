#include "geometry.h"

namespace Geometry
{
    void GeometricFigure::arangeVertices()
    {
    }

    void GeometricFigure::deleteDuplicateVertices()
    {
        bool first = false;
        int index = 0;
        for (Vertex v : vertices)
        {
            for (Vertex d : vertices)
            {
                if (v.getX() == d.getX() &&v.getY() == d.getY())
                {
                    first == true;
                    if (first)
                        vertices.erase(vertices.begin() + indexToRemove);
                }
                index++;
            }
            first = false;
            index = 0;
        }
    }

    GeometricFigure::GeometricFigure(Vertex vertices[], int len)
    {
    }

    GeometricFigure::GeometricFigure(double** arr, int len)
    {
    }

    double GeometricFigure::calcArea()
    {
        int nextIndex = 0;
        double area = 0;
        for (Vertex v : vertices)
        {
            nextIndex++;
            nextIndex %= vertices.size();
            area += (v.getX() * vertices.at(nextIndex).getY()) - (v.getY() * vertices.at(nextIndex).getX());
        }
        return abs(area)/2;
    }

    double GeometricFigure::calcCircumferenceLength()
    {
        int nextIndex = 0;
        double Circumference = 0;
        for (Vertex v : vertices)
        {
            nextIndex++;
            nextIndex %= vertices.size();
            double dx = vertices.at(nextIndex).getX() - v.getX();
            double dy = vertices.at(nextIndex).getY() - v.getY();
            Circumference += sqrt(dx^2 + dy^2);
        }
        return Circumference;
    }

    int GeometricFigure::numberOfVertices()
    {
        return vertices.size();
    }

} // namespace Geometry
