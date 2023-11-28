/* Arithmetic Operators Overloading as normal functions */

// If no direct access for the private members is required

#include <iostream>

using namespace std;

class Point{
public:
    // public member variables
    double m_x;
    double m_y;

    Point(double x = 0, double y = 0) : m_x{x}, m_y{y} {}  
};

Point operator+(const Point p1, const Point p2){
    return Point{(p1.m_x + p2.m_x), (p1.m_y + p2.m_y)};
}
Point operator-(const Point p1, const Point p2){
    return Point{(p1.m_x - p2.m_x), (p1.m_y - p2.m_y)};
}
Point operator*(const Point p1, const Point p2){
    return Point{(p1.m_x * p2.m_x), (p1.m_y * p2.m_y)};
}
Point operator/(const Point p1, const Point p2){
    return Point{(p1.m_x / p2.m_x), (p1.m_y / p2.m_y)};
}

ostream& operator<<(ostream& out, const Point p){
    out << "[" << p.m_x << "," << p.m_y << "]";
    return out;
}

int main(){
    Point p1{1,2}, p2{3,4};
    cout << p1 << endl;
    cout << p2 << endl;
    cout << "+: " << p1 + p2 << endl;
    cout << "-: " << p1 - p2 << endl;
    cout << "*: " << p1 * p2 << endl;
    cout << "/: " << p1 / p2 << endl;
}