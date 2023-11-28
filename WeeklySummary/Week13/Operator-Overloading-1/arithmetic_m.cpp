/* Arithmetic Operators Overloading as member functions */

#include <iostream>

using namespace std;

class Point{
private:
    double m_x;
    double m_y;

public:
    Point(double x = 0, double y = 0) : m_x{x}, m_y{y} {}  

    Point operator+(const Point);
    Point operator-(const Point);
    Point operator*(const Point);
    Point operator/(const Point);

    friend ostream& operator<<(ostream& out, const Point);
};

Point Point::operator+(const Point p){
    return Point{(m_x + p.m_x), (m_y + p.m_y)};
}
Point Point::operator-(const Point p){
    return Point((m_x - p.m_x), (m_y - p.m_y));
}
Point Point::operator*(const Point p){
    return Point{(m_x * p.m_x), (m_y * p.m_y)};
}
Point Point::operator/(const Point p){
    return Point{(m_x / p.m_x), (m_y / p.m_y)};
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