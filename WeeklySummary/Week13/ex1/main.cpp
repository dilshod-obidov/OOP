#include <iostream>

using namespace std;

class Fraction{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator = 0, int denominator = 1) 
        : m_numerator{numerator}, m_denominator{denominator} {}
    
    friend ostream& operator<<(ostream&, const Fraction&);
};

ostream& operator<<(ostream& out, const Fraction& fraction){
    out << fraction.m_numerator << "/" << fraction.m_denominator; 
    return out;
}

int main(){
    Fraction f1{ 1,2 }, f2{ 3,4 };
    cout << f1 << ", " << f2 << endl;
    return 0;
}