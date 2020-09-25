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

  // r.Shrink();
  // REQUIRE(r.get_p1().x ==  1);
  // REQUIRE(r.get_p1().y ==  1);
  // REQUIRE(r.get_p2().x ==  1);
  // REQUIRE(r.get_p2().y ==  0);
}



