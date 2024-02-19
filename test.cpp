#include <iostream>
#include "src/geometry.h"

using namespace Geometry;

#define MES_ERROR 0.00001

bool compareDoubles(double a, double b)
{
    if (a + MES_ERROR > b && a - MES_ERROR < b)
        return true;
    else
        return false;
}

void printTest(string description, bool result, double value, double expval)
{
    if (result)
    {
        cout << "PASS - ";
    }
    else
    {
        cout << "FAIL - ";
    }
    cout << description;

    cout << " - expected: " << expval;
    cout << " - given: " << value << '\n';
}

void lineTestLength()
{
    Line line(2.0, 2.0, 4.0, 4.0);
    double len = line.calcLength();
    printTest("Line test for lenght", compareDoubles(len, 2.828437), len, 2.828437);
}

void lineTestCrossPoint()
{
    Line line1(2.0, 2.0, 4.0, 4.0);
    Line line2(4.0, 2.0, 2.0, 4.0);
    Vertex pointT(3.0, 3.0);
    Vertex pointCalc = line1.calcCrosspoint(line2);
    // cout << "Line test for Cross Point: " << ((pointCalc.getX()==pointT.getX()) && (pointCalc.getY() == pointT.getY())) << endl;
    printTest("Line test for Cross Point", ((pointCalc.getX() == pointT.getX()) && (pointCalc.getY() == pointT.getY())), 1, 1);
}

void lineTestVertexOnLine()
{
    Line line(2.0, 2.0, 4.0, 4.0);
    Vertex point(3.0, 3.0);
    // cout << "Line test for Vertex On Line: " << line.vertexOnLine(point) << endl;
    printTest("Line test for Vertex On Line", line.vertexOnLine(point), line.vertexOnLine(point), 1);
}

void testEllipse()
{
    Vertex V(2.5, 3.12);
    Ellipse E(V, 2.12, 5.12);
    {
        double exp = 34.1001032;
        double cal = E.calcArea();
        bool result = compareDoubles(exp, cal);
        printTest("Ellipse test for area", result, cal, exp);
        {
            double expARC = exp * (60.9 / 360.0);
            double calARC = E.areaOfArc(60.9);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Ellipse test for area length - arc", resultARC, calARC, expARC);
        }
    }

    {
        double exp = 23.73241414;
        double cal = E.calcCircumferenceLength();
        bool result = compareDoubles(exp, cal);
        printTest("Ellipse test for circumference length", result, cal, exp);
        {
            double expARC = exp * (60.9 / 360.0);
            double calARC = E.circumferenceOfArc(60.9);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Ellipse test for circumference length - arc", resultARC, calARC, expARC);
        }
    }

    {
        Vertex In(3, 4);
        Vertex Out(30, 45);
        bool result = E.vertexIn(In);
        printTest("Ellipse test for vertex in - true", result == 1, result, 1);
        result = E.vertexIn(Out);
        printTest("Ellipse test for vertex in - false", result == 0, result, 0);
    }

    {
        Vertex On(V.getX() + E.getA(), V.getY());
        Vertex Out(30, 45);
        bool result = E.vertexOn(On);
        printTest("Ellipse test for vertex in - true", result == 1, result, 1);
        result = E.vertexIn(Out);
        printTest("Ellipse test for vertex in - false", result == 0, result, 0);
    }
}

void testCircle()
{
    Vertex V(2.5, 3.12);
    Circle C(V, 5.12);
    {
        double exp = 82.35496646;
        double cal = C.calcArea();
        bool result = compareDoubles(exp, cal);
        printTest("Circle test for area", result, cal, exp);
        {
            double expARC = exp * (60.9 / 360.0);
            double calARC = C.areaOfArc(60.9);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Circle test for area length - arc", resultARC, calARC, expARC);
        }
    }

    {
        double exp = 32.16990877;
        double cal = C.calcCircumferenceLength();
        bool result = compareDoubles(exp, cal);
        printTest("Circle test for circumference length", result, cal, exp);
        {
            double expARC = exp * (60.9 / 360.0);
            double calARC = C.circumferenceOfArc(60.9);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Circle test for circumference length - arc", resultARC, calARC, expARC);
        }
    }

    {
        Vertex In(3, 4);
        Vertex Out(30, 45);
        bool result = C.vertexIn(In);
        printTest("Circle test for vertex in - true", result == 1, result, 1);
        result = C.vertexIn(Out);
        printTest("Circle test for vertex in - false", result == 0, result, 0);
    }

    {
        Vertex On(V.getX() + C.getA(), V.getY());
        Vertex Out(30, 45);
        bool result = C.vertexOn(On);
        printTest("Circle test for vertex in - true", result == 1, result, 1);
        result = C.vertexOn(Out);
        printTest("Circle test for vertex in - false", result == 0, result, 0);
    }
}

void triangleTestIsTraingle()
{
    Vertex v[] = {Vertex(1, 0), Vertex(2, 0), Vertex(3, 0)};
    Triangle t(v, 3);
    printTest("Triangle test is Triangle - not triangle", t.isTriangle() == false ? true : false, t.isTriangle(), 0);
    Vertex v2[] = {Vertex(0, 0), Vertex(2, 0), Vertex(0, 2)};
    Triangle t2(v2, 3);
    printTest("Triangle test is Triangle - is triangle", t2.isTriangle() == true ? true : false, t2.isTriangle(), 1);
}

void triangleTestArea()
{
    Vertex v[] = {Vertex(0, 0), Vertex(2, 0), Vertex(0, 2)};
    Triangle t(v, 3);
    printTest("Triangle test area", compareDoubles(t.calcArea(), 2.0), t.calcArea(), 2.0);
}

void squareTest()
{
    Vertex v[] = {Vertex(0, 0), Vertex(2, 0), Vertex(2, 2), Vertex(0, 2)};
    Square s(v, 4);
    bool boolResult = s.isSquare();
    printTest("Square test is Square - is Square", boolResult == 1, boolResult, 1);
    Vertex v2[] = {Vertex(0, 0), Vertex(4, 0), Vertex(2, 2), Vertex(0, 2)};
    Square s2(v2, 4);
    boolResult = s2.isSquare();
    printTest("Square test is Square - not Square", boolResult == 0, boolResult, 0);
    double doubleResult = s.calcArea();
    printTest("Square test for calc area", doubleResult == 4, doubleResult, 4);
    doubleResult = s.calcCircumferenceLength();
    printTest("Square test for calc circumference", doubleResult == 8, doubleResult, 8);
    // Vertex vertexResult = s.calcCenter();
    // printTest("Square test fo calc center", vertexResult == (1, 1), vertexResult, 8);
    doubleResult = s.calcCircumscribedCircleRadius();
    printTest("Square test for calc circumscribed circle radius", compareDoubles(1.41421, doubleResult), doubleResult, 1.41421);
    doubleResult = s.calcInscribedCircleRadius();
    printTest("Square test for calc inscribed circle radius", compareDoubles(1, doubleResult), doubleResult, 1);
    doubleResult = s.calcDiagonalLength();
    printTest("Square test for calc diagonal lenght", compareDoubles(2.828427, doubleResult), doubleResult, 2.828427);
}

void rhombTest()
{
    Vertex v[] = {Vertex(0, 0), Vertex(3, 4), Vertex(5, 0), Vertex(8, 4)};
    Rhombus r(v, 4);
    bool boolResult = r.isRhombus();
    printTest("Rhombus test is Rhombus - is Rhombus", boolResult == 1, boolResult, 1);
    Vertex v2[] = {Vertex(0, 0), Vertex(2, 0), Vertex(3, 2), Vertex(1, 2)};
    Rhombus r2(v2, 4);
    boolResult = r2.isRhombus();
    printTest("Rhombus test is Rhombus - not Rhombus", boolResult == 0, boolResult, 0);
    double doubleResult = r.calcArea();
    printTest("Rhombus test for calc area", compareDoubles(20, doubleResult), doubleResult, 20);
    doubleResult = r.calcCircumferenceLength();
    printTest("Rhombus test for calc circumference lenght", compareDoubles(20, doubleResult), doubleResult, 20);
    doubleResult = r.calcDiagonalsRatio();
    printTest("Rhombus test for calc diagonal ratio", compareDoubles(2, doubleResult), doubleResult, 2);
}

void trapezoidTest()
{
    Vertex v[] = {Vertex(0, 0), Vertex(1, 2), Vertex(4, 0), Vertex(3, 2)};
    Trapezoid t(v, 4);
    bool boolResult = t.isTrapezoid();
    printTest("Trapezoid test is Trapezoid - is Trapezoid", boolResult == 1, boolResult, 1);
    Vertex v2[] = {Vertex(0, 0), Vertex(1, 2), Vertex(4, 0), Vertex(4, 3)};
    Trapezoid t2(v2, 4);
    boolResult = t2.isTrapezoid();
    printTest("Trapezoid test is Trapezoid - not Trapezoid", boolResult == 0, boolResult, 0);
    double doubleResult = t.calcArea();
    printTest("Trapezoid test for calc area", compareDoubles(6, doubleResult), doubleResult, 6);
    doubleResult = t.calcHeight();
    printTest("Trapezoid test for height", compareDoubles(2, doubleResult), doubleResult, 2);
    doubleResult = t.calcCircumferenceLength();
    printTest("Trapezoid test for circumference lenght", compareDoubles(10.47214, doubleResult), doubleResult, 10.47214);
    doubleResult = t.calcMedianLength();
    printTest("Trapezoid test for median lenght", compareDoubles(3, doubleResult), doubleResult, 3);
}

void rectangleTestIsRectangle()
{
    Vertex v[] = {Vertex(0, 0), Vertex(3, 0), Vertex(0, 2), Vertex(5, 2)};
    Rectangle r(v, 4);
    printTest("Rectangle test is Rectangle - not Rectangle", r.isRectangle() == false ? true : false, r.isRectangle(), 0);
    Vertex v2[] = {Vertex(0, 0), Vertex(3, 0), Vertex(0, 2), Vertex(3, 2)};
    Rectangle r2(v2, 4);
    printTest("Rectangle test is Rectangle - is Rectangle", r2.isRectangle() == true ? true : false, r2.isRectangle(), 1);
}

void rectangleTestArea()
{
    Vertex v[] = {Vertex(0, 0), Vertex(3, 0), Vertex(0, 2), Vertex(3, 2)};
    Rectangle r(v, 4);
    printTest("Rectangle test area", compareDoubles(r.calcArea(), 6.0), r.calcArea(), 6.0);
}

void rectangleTestDiagonalLength()
{
    Vertex v[] = {Vertex(0, 0), Vertex(3, 0), Vertex(0, 2), Vertex(3, 2)};
    Rectangle r(v, 4);
    printTest("Rectangle diagonal length", compareDoubles(r.calcDiagonalLength(), sqrt(13)), r.calcDiagonalLength(), sqrt(13));
}

void rectangleTestCenterpoint()
{
    Vertex v[] = {Vertex(0, 0), Vertex(4, 0), Vertex(0, 2), Vertex(4, 2)};
    Vertex c(2, 1);
    Rectangle r(v, 4);
    Vertex wvertex = r.calcCenter();
    bool w = compareDoubles(wvertex.getX(), c.getX()) && compareDoubles(wvertex.getY(), c.getY());
    printTest("Rectangle center point", w, w, 1);
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

    // Ellips tests
    testEllipse();
    testCircle();

    squareTest();

    rhombTest();

    trapezoidTest();

    // Rectangle tests
    rectangleTestIsRectangle();
    rectangleTestArea();
    rectangleTestDiagonalLength();
    rectangleTestCenterpoint();
    return 0;
}
