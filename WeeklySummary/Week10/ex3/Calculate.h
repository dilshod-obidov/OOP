#ifndef _CALCULATE_H_
#define _CALCULATE_H_

class Calculate{
    double m_value;
    double a_value[5];
    char a_op[5];
    int idx = 0;
    void func(double, char);
public:
    Calculate(double value = 0) : m_value{value}{}
    Calculate(const Calculate& copy){
        m_value = copy.m_value;
    }
    double getValue();
    double add(double);
    double substract(double);
    double multiply(double);
    double divide(double);
    void undo();
    bool lastOperation(char&, double&);
};

#endif 