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
        return 0.0;
    }

    double GeometricFigure::calcCircumferenceLength()
    {
        return 0.0;
    }

    int GeometricFigure::numberOfVertices()
    {
        return 0;
    }

} // namespace Geometry
