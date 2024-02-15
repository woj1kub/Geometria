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

void printTest(string description, bool result, double value, double expval) {
    cout << description << " - ";
    if (result)
    {
        cout << "PASS";
    }
    else{
        cout << "FAIL";
    }
    cout << " - expected: " << expval;
    cout << " - given: " << value << '\n';
}

void lineTestLength() {
    Line line(2.0, 2.0, 4.0, 4.0);
    double len = line.calcLength();
    printTest("Line test for lenght", compareDoubles(len, 2.828437), len, 2.828437);
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

void triangleTestIsTraingle() {
    Vertex v[] = {Vertex(1,0), Vertex(2,0), Vertex(3,0)};
    Triangle t(v, 3);
    printTest("Triangle test is Triangle - not triangle", t.isTriangle() == false ? true : false, 0,0);
    Vertex v2[] = {Vertex(0,0), Vertex(2,0), Vertex(0,2)};
    Triangle t2(v2, 3);
    printTest("Triangle test is Triangle - is triangle", t2.isTriangle() == true ? true : false, 0,0);
}

void triangleTestArea() {
    Vertex v[] = {Vertex(0,0), Vertex(2,0), Vertex(0,2)};
    Triangle t(v, 3);
    printTest("Triangle test area", compareDoubles(t.calcArea(), 2.0), t.calcArea(), 2.0);
}

int main(int argc, char const *argv[])
{
    // Line tests
    lineTestLength();
    lineTestCrossPoint();
    lineTestVertexOnLine();

    // Triangle tests
    triangleTestIsTraingle();
    triangleTestArea();
    return 0;
}
