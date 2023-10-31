#include <iostream> 
#include "Calculate.h"
using namespace std;

void Calculate::func(double value){
    idx++;
    idx%=5;
    a_value[idx] = value;
}

double Calculate::getValue(){
    return m_value;
}
double Calculate::add(double value){
    m_value += value;
    a_op[idx] = '+';
    func(value);
    return m_value;
}
double Calculate::substract(double value){
    m_value -= value;
    a_op[idx] = '-';
    func(value);
    return m_value;
}
double Calculate::multiply(double value){
    m_value *= value;
    a_op[idx] = '*';
    func(value);
    return m_value;
}
double Calculate::divide(double value){
    m_value /= value;
    a_op[idx] = '/';
    func(value);
    return m_value;
}
void Calculate::undo(){
    idx_check++;
    if(idx<1) idx+=5;
    switch(a_op[idx-1]){
    case '+':
        m_value -= a_value[idx-1];
        break;
    case '-':
        m_value += a_value[idx-1];
        break;
    case '*':
        m_value /= a_value[idx-1];
        break;
    case '/':
        m_value *= a_value[idx-1];
        break;
    }
}
bool Calculate::lastOperation(char& op, double& value){
    if(idx_check>=5) return false;
    value = a_value[idx];
    idx--;
    op = a_op[idx];
    return true;
}
