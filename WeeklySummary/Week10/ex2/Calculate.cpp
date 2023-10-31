#include <iostream> 
#include "Calculate.h"
using namespace std;

void Calculate::func(double value){
    a_value[idx] = value;
    idx++;
    idx%=5;
}

double Calculate::getValue(){
    return m_value;
}
double Calculate::add(double value){
    a_op[idx] = '+';
    m_value += value;
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
}
bool Calculate::lastOperation(char& op, double& value){
    if(idx_check>=5) return false;
    else{
        idx--;
        if(idx<0) idx+=5;
        op = a_op[idx];
        value = a_value[idx];
        switch(op){
        case '+':
            m_value -= value;
            break;
        case '-':
            m_value += value;
            break;
        case '*':
            m_value /= value;
            break;
        case '/':
            m_value *= value;
            break;
        }
        return true;
    }
}
