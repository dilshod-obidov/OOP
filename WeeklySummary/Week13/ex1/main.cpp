#include <iostream>

#define MIN(p, q) ((p > q) ? p : q)
#define POSITIVE(n) ((n < 0) ? -n : n)

using namespace std;

class Fraction{
private:
    int m_numerator;
    int m_denominator;
    
public:
    Fraction(int numerator = 0, int denominator = 1){
        // Negative values handler
        if(denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
        
        // Simplifier
        for(int i = MIN(POSITIVE(numerator), denominator); i > 1; i--){
            if(numerator % i == 0 && denominator % i == 0){
                numerator /= i;
                denominator /= i;
                break;
            }
        }

        m_numerator = numerator;
        m_denominator = denominator; 
    }
    
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