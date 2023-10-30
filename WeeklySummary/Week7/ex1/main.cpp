#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    Rectangle rect;
    rect.Display();
    rect.setWidth(10).setHeight(20).Display();
    
    return 0;
}