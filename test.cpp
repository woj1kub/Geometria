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
    // cout<<len<<endl;
    // cout<< "Line test for lenght: "<< compareDoubles(len, 2.828437)<<endl;
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
void testEllipse() {
    Vertex V(2.5,3.12);
    Ellipse E(V,2.12,5.12);
    {
        double exp = 34.1001032;
        double cal = E.calcArea();
        bool result = compareDoubles(exp, cal);
        printTest("Ellipse test for area", result, cal, exp);
        {
            double expARC = exp *(60.0/360.0) ;
            double calARC = E.areaOfArc(60);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Ellipse test for area length - arc", result, calARC, expARC);
        }
    }

    {
        double exp = 23.73241414;
        double cal = E.calcCircumferenceLength();
        bool result = compareDoubles(exp, cal);
        printTest("Ellipse test for circumference length", result, cal, exp);
        {
            double expARC = exp * (60.0 / 360.0);
            double calARC = E.circumferenceOfArc(60);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Ellipse test for circumference length - arc", result, calARC, expARC);
        }
    }

    {
        Vertex In(3, 4);
        Vertex Out(30, 45);
        bool result = E.vertexIn(In);
        printTest("Ellipse test for vertex in - true", result==1, result, 1);
        result = E.vertexIn(Out);
        printTest("Ellipse test for vertex in - false", result==0, result, 0);
    }

    {
        Vertex On(V.getX()+E.getA(), V.getY());
        Vertex Out(30, 45);
        bool result = E.vertexOn(On);
        printTest("Ellipse test for vertex in - true", result==1, result, 1);
        result = E.vertexIn(Out);
        printTest("Ellipse test for vertex in - false", result==0, result, 0);
    }
}
void testCircle() {
    Vertex V(2.5, 3.12);
    Circle C(V, 5.12);
    {
        double exp = 82.4;
        double cal = C.calcArea();
        bool result = compareDoubles(exp, cal);
        printTest("Circle test for area", result, cal, exp);
        {
            double expARC = exp * (60.0 / 360.0);
            double calARC = C.areaOfArc(60);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Circle test for area length - arc", result, calARC, expARC);
        }
    }

    {
        double exp = 32.2;
        double cal = C.calcCircumferenceLength();
        bool result = compareDoubles(exp, cal);
        printTest("Circle test for circumference length", result, cal, exp);
        {
            double expARC = exp * (60.0 / 360.0);
            double calARC = C.circumferenceOfArc(60);
            bool resultARC = compareDoubles(expARC, calARC);
            printTest("Circle test for circumference length - arc", result, calARC, expARC);
        }
    }

    {
        Vertex In(3, 4);
        Vertex Out(30, 45);
        bool result = C.vertexIn(In);
        printTest("Circle test for vertex in - true", result==1, result, 1);
        result = C.vertexIn(Out);
        printTest("Circle test for vertex in - false", result==0, result, 0);
    }

    {
        Vertex On(V.getX() + C.getA(), V.getY());
        Vertex Out(30, 45);
        bool result = C.vertexOn(On);
        printTest("Circle test for vertex in - true", result==1, result, 1);
        result = C.vertexOn(Out);
        printTest("Circle test for vertex in - false", result==0, result, 0);
    }
}

int main(int argc, char const *argv[])
{
    /*lineTestLength();
    lineTestCrossPoint();
    lineTestVertexOnLine();*/
    testEllipse();
    return 0;
}
