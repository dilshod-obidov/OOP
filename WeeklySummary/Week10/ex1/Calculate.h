#ifndef _CALCULATE_H_
#define _CALCULATE_H_

class Calculate{
    double m_value;
public:
    Calculate(double value = 0) : m_value{value}{}
    double getValue();
    double add(double);
    double substract(double);
    double multiply(double);
    double divide(double);

};

#endif 