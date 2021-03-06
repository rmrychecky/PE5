#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"


TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
}

TEST_CASE ( "Rectangle Constructor", "[Rectangle]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 0;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  REQUIRE( r.get_p1().x == p1.x );
  REQUIRE( r.get_p2().x == p2.x );
  REQUIRE( r.get_p1().y == p1.y );
  REQUIRE( r.get_p2().y == p2.y );
  REQUIRE( r.get_p1().x <= r.get_p2().x );
  REQUIRE( r.get_p1().y <= r.get_p2().y );
}

TEST_CASE ( "Get the width of the rectangle between p1.x and p2.x", "[GetWidth]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 2;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  REQUIRE(r.GetWidth() ==  2);

  Point p3;
  p3.x = -5;
  p3.y = -5;

  Point p4;
  p4.x = -1;
  p4.y = -2;
  Rectangle r1 = Rectangle(p3, p4);
  REQUIRE(r1.GetWidth() ==  4);

  Point p5;
  p5.x = -2;
  p5.y = -2;

  Point p6;
  p6.x = 1;
  p6.y = 1;
  Rectangle r2 = Rectangle(p5, p6);
  REQUIRE(r2.GetWidth() ==  3);
}

TEST_CASE ( "Get the height of the rectangle between p1.x and p2.x", "[GetHeight]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 2;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  REQUIRE(r.GetHeight() ==  1);

  Point p3;
  p3.x = -5;
  p3.y = -5;

  Point p4;
  p4.x = -1;
  p4.y = -2;
  Rectangle r1 = Rectangle(p3, p4);
  REQUIRE(r1.GetHeight() ==  3);

  Point p5;
  p5.x = -2;
  p5.y = -2;

  Point p6;
  p6.x = 1;
  p6.y = 1;
  Rectangle r2 = Rectangle(p5, p6);
  REQUIRE(r2.GetHeight() ==  3);
}

TEST_CASE ( "Get Point p1", "[get_p1]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 2;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  REQUIRE(r.get_p1().x ==  p1.x);
  REQUIRE(r.get_p1().y ==  p1.y);
}

TEST_CASE ( "Get Point p2", "[get_p2]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 2;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  REQUIRE(r.get_p2().x ==  p2.x);
  REQUIRE(r.get_p2().y ==  p2.y);
}

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

TEST_CASE ( "Overlaps are determined", "[Overlaps]"){
  //create two overlapping rectangles
  Point one;
  one.x = 0;
  one.y = 0;
  Point two;
  two.x = 2;
  two.y = 4;
  Rectangle r (one, two);
  Point oneTwo;
  oneTwo.x = 1;
  oneTwo.y = 1;
  Point twoTwo;
  twoTwo.x = 5;
  twoTwo.y =5;
  Rectangle t (oneTwo, twoTwo);
  REQUIRE( r.Overlaps(t) == true);
  REQUIRE( t.Overlaps(r) == true);
  //Change points and create new rectangle so they do not overlap
  oneTwo.x = 5;
  oneTwo.y = 1;
  twoTwo.x = 10;
  twoTwo.y = 5;
  Rectangle z (oneTwo, twoTwo);
  Rectangle h (one, two);
  REQUIRE( z.Overlaps(h) == false);
  //Check to make sure two rectangles sharing a side are considered overlapping
  one.x = 0;
  one.y = 0;
  two.x = 2;
  two.y = 2;
  oneTwo.x = 2;
  oneTwo.y = 0;
  twoTwo.x = 4;
  twoTwo.y = 2;
  Rectangle p (oneTwo, twoTwo);
  Rectangle q (one, two);
  REQUIRE( p.Overlaps(q) == true);
}

TEST_CASE ( "Area of rectangle is calculated", "[CalculateArea]"){
  //create a rectangles with area of 0
  Point one;
  one.x = 0;
  one.y = 0;
  Point two;
  two.x = 0;
  two.y = 0;
  Rectangle r (one, two);
  REQUIRE( r.CalculateArea() == 0);
  //change expected area to 4
  one.x = 0;
  one.y = 0;
  two.x = 2;
  two.y = 2;
  Rectangle t(one, two);
  REQUIRE( t.CalculateArea() == 4);
  //change expected area to 4, but rectangle is made of points with negative dimensions
  one.x = 0;
  one.y = 0;
  two.x = -2;
  two.y = -2;
  Rectangle z(two, one);
  REQUIRE( z.CalculateArea() == 4);
  //make a line and check Area
  one.x = 1;
  one.y = 1;
  two.x = 5;
  two.y = 1;
  Rectangle k(one, two);
  REQUIRE( k.CalculateArea() == 0);
}

TEST_CASE ( "Moves the bottom left coordinate down one and to the left one and moves the upper right coordinate up one and to the right one", "[Expand]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 2;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  r.Expand();
  REQUIRE(r.get_p1().x ==  -1);
  REQUIRE(r.get_p1().y ==  -1);
  REQUIRE(r.get_p2().x ==  3);
  REQUIRE(r.get_p2().y ==  2);
}

TEST_CASE ( "Moves the bottom left coordinate up one and to the right one and moves the upper right coordinate down one and to the left one", "[Shrink]") {
  Point p1;
  p1.x = 0;
  p1.y = 0;

  Point p2;
  p2.x = 2;
  p2.y = 1;
  Rectangle r = Rectangle(p1, p2);
  r.Shrink();
  REQUIRE(r.get_p1().x ==  1);
  REQUIRE(r.get_p1().y ==  1);
  REQUIRE(r.get_p2().x ==  1);
  REQUIRE(r.get_p2().y ==  0);

  Point p3;
  p3.x = 0;
  p3.y = 0;

  Point p4;
  p4.x = 0;
  p4.y = 0;
  Rectangle r1 = Rectangle(p3, p4);
  r1.Shrink();
  REQUIRE(r1.get_p1().x ==  0);
  REQUIRE(r1.get_p1().y ==  0);
  REQUIRE(r1.get_p2().x ==  0);
  REQUIRE(r1.get_p2().y ==  0);
}



