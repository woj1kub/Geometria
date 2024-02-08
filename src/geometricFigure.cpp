#include "geometry.h"

namespace Geometry
{
    int GeometricFigure::orientation(Vertex p, Vertex q, Vertex r) {
        double val = (q.getY() - p.getY()) * (r.getX() - q.getX()) - (q.getX() - p.getX()) * (r.getY() - q.getY());
        if (val == 0) return 0; // Kolinearne
        return (val > 0) ? 1 : 2; // Zgodnie lub przeciwnie do ruchu wskazówek zegara
    }
    void GeometricFigure::arangeVertices()
    {
        //Wykorzystujemy algorytm Jarvisa, musimy tak zrobiæ aby obliczaæ pole 
        int n = vertices.size();
        if (n < 3) {
            cerr << "Wielok¹t musi mieæ co najmniej 3 punkty." << endl;
        }

        vector<Vertex> convexHull;

        // ZnajdŸ punkt startowy (o najni¿szej wspó³rzêdnej y)
        int minY = 0;
        for (int i = 1; i < n; i++) {
            if (vertices[i].getY() < vertices[minY].getY() || (vertices[i].getY() == vertices[minY].getY() && vertices[i].getX() < vertices[minY].getX())) {
                minY = i;
            }
        }

        int p = minY, q;
        do {
            convexHull.push_back(vertices[p]);
            q = (p + 1) % n;
            for (int i = 0; i < n; i++) {
                if (orientation(vertices[p], vertices[i], vertices[q]) == 2) {
                    q = i;
                }
            }
            p = q;
        } while (p != minY);

        vertices = convexHull;
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
                    if (first)
                        vertices.erase(vertices.begin() + index);
            						first = true;
    								}
                index++;
            }
            first = false;
            index = 0;
        }
    }

    GeometricFigure::GeometricFigure(Vertex* vertices, int len)
    {
        for (size_t i = 0; i < len; i++)
            this->vertices.push_back(vertices[i]);
        deleteDuplicateVertices();
        arangeVertices();
    }

    GeometricFigure::GeometricFigure(double** arr, int len)
    {
        vertices.resize(len);
        for (int i = 0; i < len; ++i)
            vertices.push_back(Vertex(arr[i][0], arr[i][1]));

        deleteDuplicateVertices();
        arangeVertices();
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
            Circumference += sqrt( pow(dx,2) + pow(dy, 2));
        }
        return Circumference;
    }

    int GeometricFigure::numberOfVertices()
    {
        return vertices.size();
    }

    bool GeometricFigure::addVertex(Vertex v) {
        try
        {
            vertices.push_back(v);
            deleteDuplicateVertices();
            arangeVertices();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        return true;
    }

    bool GeometricFigure::deleteVertex(int index) {
        if (numberOfVertices() < index || index < 0)
        {
            std::cerr << "Index out of range";
            return false;
        }
        vertices.erase(vertices.begin() + index);
        
        return true;
    }

} // namespace Geometry
