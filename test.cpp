#include <iostream>
#include "src/geometry.h"

using namespace Geometry;

#define MES_ERROR 0.00001

bool compareDoubles(double a, double b) {
    if (a + MES_ERROR > b && a - MES_ERROR < b)
        return true;
    else
        return false;
    
}

void lineTestLength() {
    Line line(2.0, 2.0, 4.0, 4.0);
    double len = line.calcLength();
    cout<<len<<endl;
    cout<< "Line test for lenght: "<< compareDoubles(len, 2.828437)<<endl;
}
void lineTestCrossPoint() {
    Line line1(2.0, 2.0, 4.0, 4.0);
    Line line2(4.0, 2.0, 2.0, 4.0);
    Vertex pointT(3.0, 3.0);
    Vertex pointCalc = line1.calcCrosspoint(line2);
    cout << "Line test for Cross Point: " << ((pointCalc.getX()==pointT.getX()) && (pointCalc.getY() == pointT.getY())) << endl;
}
void lineTestVertexOnLine() {
    Line line(2.0, 2.0, 4.0, 4.0);
    Vertex point(3.0, 3.0);
    cout << "Line test for Vertex On Line: " << line.vertexOnLine(point) << endl;

}

int main(int argc, char const *argv[])
{
    lineTestLength();
    lineTestCrossPoint();
    lineTestVertexOnLine();
    return 0;
}
