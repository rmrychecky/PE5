#include <iostream>
#include "Rectangle.h"
#include <cmath>

unsigned int Factorial( unsigned int number ){
  if(number > 1){
    return number * Factorial(number- 1);
  } else {
    return 1;
  }
}

/**
    Returns nothing. Constructor.

    @param p1 is bottom left point.
    @param p2 is top right point.
*/
Rectangle::Rectangle(Point p1, Point p2){
  this->p1_ = p1;
  this->p2_ = p2;
}

/**
    Returns int

    @param N/A.
    @return the distance betwween the far right point and the far left point.
*/
int Rectangle::GetWidth(){
  return abs(this->p2_.x - this->p1_.x);
}

/**
    Returns int

    @param N/A
    @return the difference between the lowest and highest points of the rectangle.
*/
int Rectangle::GetHeight(){
  int height = abs(this->p2_.y - this->p1_.y);
  return height;
}

/**
    Returns bool

    Overlaps was not functioning properly in the original rectangle.o file.

    @param other is a second rectangle object.
    @return bool that indicates wether or not the two rectangles are overlapping.
*/
bool Rectangle::Overlaps(Rectangle& other){
  if(this->p2_.x < other.get_p1().x){
    return false;
  }else if(this->p1_.x > other.get_p2().x){
    return false;
  }else if(this->p2_.y < other.get_p1().y){
    return false;
  }else if(this->p1_.y > other.get_p2().y){
    return false;
  }
  return true;
}

/**
    Returns int

    @param N/A.
    @return area of rectangle.
*/
int Rectangle::CalculateArea(){
  return abs(this->GetHeight()*this->GetWidth());
}

/**
    Returns void

    @param N/A.
    @return expands rectangle by 1 unit in each direction.
*/
void Rectangle::Expand(){
  this->p1_.x = this->p1_.x - 1;
  this->p1_.y = this->p1_.y - 1;
  this->p2_.x = this->p2_.x + 1;
  this->p2_.y = this->p2_.y + 1;
}

/**
    Returns void

    Shrink could not handle the edge case when both points are on top of
    eachother in the original rectangle.o file

    @param N/A.
    @return shrinks rectangle by 1 unit inward.
*/
void Rectangle::Shrink(){
  if(this->p2_.x - 1 >= this->p1_.x + 1){
    this->p1_.x = this->p1_.x + 1;
    this->p1_.y = this->p1_.y + 1;
    this->p2_.x = this->p2_.x - 1;
    this->p2_.y = this->p2_.y - 1;
  }
}
