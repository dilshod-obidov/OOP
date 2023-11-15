#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle& Rectangle::setWidth(int w){
    this->m_width = w;
    return *this;
}

Rectangle& Rectangle::setHeight(int h){
    this->m_height = h;
    return *this;
}

Rectangle& Rectangle::Display(){
    cout << "Width = " << this->m_width << " Height = " << this->m_height << endl; 
    return *this;
}