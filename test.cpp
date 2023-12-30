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
    std::cout<< "Line test for lenght: "<< compareDoubles(len, 2.8284);
    
}


int main(int argc, char const *argv[])
{
    lineTestLength();
    return 0;
}
