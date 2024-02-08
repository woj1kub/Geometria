#include "geometry.h"

namespace Geometry 
{
    std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
        stream << "X: " << vertex.x << ", Y: " << vertex.y;
        return stream;
    }
}