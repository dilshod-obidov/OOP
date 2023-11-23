#include <iostream>

#define MIN(p, q) ((p > q) ? p : q)
#define POSITIVE(n) ((n < 0) ? -n : n)

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

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
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    Fraction operator-() const;
};

ostream& operator<<(ostream& out, const Fraction& f){
    out << f.m_numerator << "/" << f.m_denominator; 
    return out;
}

Fraction operator*(const Fraction& f1, const Fraction& f2){
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator); 
}

Fraction operator+(const Fraction& f1, const Fraction& f2){
    long lcm = (f1.m_denominator * f2.m_denominator) / gcd(f1.m_denominator, f2.m_denominator);
    long numerator1 = f1.m_numerator * (lcm / f1.m_denominator);
    long numerator2 = f2.m_numerator * (lcm / f2.m_denominator);

    return Fraction(numerator1 + numerator2, lcm);
}

Fraction operator-(const Fraction& f1, const Fraction& f2){
    long lcm = (f1.m_denominator * f2.m_denominator) / gcd(f1.m_denominator, f2.m_denominator);
    long numerator1 = f1.m_numerator * (lcm / f1.m_denominator);
    long numerator2 = f2.m_numerator * (lcm / f2.m_denominator);

    return Fraction(numerator1 - numerator2, lcm);

}

Fraction Fraction::operator-() const{
    return Fraction(-m_numerator, m_denominator);
}


int main() {  
    Fraction f1{1,2}, f2{3,4}; 

    cout << f1 << "," << f2 << endl;  
    cout << -f1 << "," << -f2 << endl;  
    cout << -(-f1) << endl;  

    return 0;  
}