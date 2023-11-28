/* Arithmetic Operators Overloading as friend functions */

#include <iostream>

using namespace std;

class Point{
private:
    double m_x;
    double m_y;

public:
    Point(double x = 0, double y = 0) : m_x{x}, m_y{y} {}
    
    friend istream& operator>>(istream&, Point&); // reference to object
    friend ostream& operator<<(ostream&, const Point&);
};

istream& operator>>(istream& in, Point& p){
    in >> p.m_x >> p.m_y;
    return in;
}
ostream& operator<<(ostream& out, const Point& p){
    out << "[" << p.m_x << "," << p.m_y << "]";
    return out;
}

int main(){
    Point p1, p2;
    cin >> p1;
    cout << p1 << endl;
    cin >> p2;
    cout << p2 << endl;
}