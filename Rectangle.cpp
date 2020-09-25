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

Rectangle::Rectangle(Point p1, Point p2){
  this->p1_ = p1;
  this->p2_ = p2;
}

int Rectangle::GetWidth(){
  return abs(this->p2_.x - this->p1_.x);
}

int Rectangle::GetHeight(){
  int height = abs(this->p2_.y - this->p1_.y);
  return height;
}

bool Rectangle::Overlaps(Rectangle& other){
  bool xOver = false;
  bool yOver = false;
  int thisX[this->GetWidth()];
  int thisY[this->GetHeight()];
  int otherX[other.GetWidth()];
  int otherY[other.GetHeight()];
  for (int i = this->p1_.x; i <= this->GetWidth(); i++){
    thisX[i] = i;
  }
  for (int i = this->p1_.y; i <= this->GetHeight(); i++){
    thisY[i] = i;
  }
  for (int i = this->p2_.x; i <= other.GetWidth(); i++){
    otherX[i] = i;
  }
  for (int i = this->p2_.y; i <= other.GetHeight(); i++){
    otherY[i] = i;
  }
  for(int i = 0; i < sizeof(thisX); i++){
    for(int x = 0; x < sizeof(otherX); i++){
      if(otherX[x] == thisX[i]){
        xOver = true;
        break;
      }
      if(xOver == true){
        break;
      }
    }
  }
  for(int i = 0; i < sizeof(thisY); i++){
    for(int x = 0; x < sizeof(otherY); i++){
      if(otherY[x] == thisY[i]){
        yOver = true;
        break;
      }
      if(yOver == true){
        break;
      }
    }
  }

  if(yOver && xOver){
    return true;
  }
  return false;
}

int Rectangle::CalculateArea(){
  return abs(this->GetHeight()*this->GetWidth());
}

void Rectangle::Expand(){
  this->p1_.x = this->p1_.x - 1;
  this->p1_.y = this->p1_.y - 1;
  this->p2_.x = this->p1_.x + 1;
  this->p2_.y = this->p1_.y + 1;
}

void Rectangle::Shrink(){
  if((this->p2_.x - 1 >= this->p1_.x + 1) && (this->p2_.y - 1 >= this->p1_.y + 1)){
    this->p1_.x = this->p1_.x + 1;
    this->p1_.y = this->p1_.y + 1;
    this->p2_.x = this->p2_.x - 1;
    this->p2_.y = this->p2_.y - 1;
  }
}