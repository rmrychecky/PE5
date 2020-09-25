#include <iostream>
#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(Point p1, Point p2){
  this->p1_ = p1;
  this->p2_ = p2;
}

int Rectangle::GetWidth(){
  return abs(this->p2_.y) - abs(this->p1_.x);
}

bool Rectangle::Overlaps(Rectangle& other){
  bool xOver = false;
  bool yOver = false;
  int thisX[this->GetWidth()];
  int thisY[this->GetWidth()];
  int otherX[this->GetWidth()];
  int otherY[this->GetWidth()];
  for (int i == this->p1_.x; i <= this->GetWidth(); i++){
    thisX[i] = i;
  }
  for (int i == this->p1_.y; i <= this->GetHeight(); i++){
    thisY[i] = i;
  }
  for (int i == this->p2_.x; i <= this->GetWidth(); i++){
    otherX[i] = i;
  }
  for (int i == this->p2_.y; i <= this->GetHeight(); i++){
    otherY[i] = i;
  }
  for(int i = 0; i < thisX.length(); i++){
    for(int x = 0; x < otherX.length(); i++){
      if(otherX[x] == thisX[i]){
        xOver = true;
        break;
      }
      if(xOver == true){
        break;
      }
    }
  }
  for(int i = 0; i < thisY.length(); i++){
    for(int x = 0; x < otherY.length(); i++){
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
