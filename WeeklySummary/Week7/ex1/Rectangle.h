#include <iostream>
using namespace std;

class Rectangle{
    double m_width{0};
    double m_height{0};
public:
    Rectangle& setWidth(int);
    Rectangle& setHeight(int);
    Rectangle& Display();
};