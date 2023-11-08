#include <iostream>
using namespace std;

class Fruit{
    string m_name;
    string m_color;
public:
    Fruit(string name, string color) : m_name{name}, m_color{color} {}
    string getName();
    string getColor();
};