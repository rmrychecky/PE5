#include <iostream>
#include "Rectangle.h"

int main(){
Point p;
p.x = 0;
p.y = 0;
Point p2;
p2.x = 2;
p2.y = 2;
Point pTwo;
p.x = 1;
p.y = 1;
Point pTwo2;
p2.x = 3;
p2.y = 3;

Rectangle r(p,p2);
Rectangle z(pTwo, pTwo2);

std::cout << r.Overlaps(z) << endl;
}