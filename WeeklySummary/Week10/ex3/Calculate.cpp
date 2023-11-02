#include <iostream> 
#include "Calculate.h"
using namespace std;

void Calculate::func(double value, char op){
    if(idx == 5){
        for(int i = 0; i < 4; i++){
            a_value[i] = a_value[i+1];
            a_op[i] = a_op[i+1]; 
        }
        idx--;
    }
    a_value[idx] = value;
    a_op[idx] = op;
    idx++;
}

double Calculate::getValue(){
    return m_value;
}
double Calculate::add(double value){
    m_value += value;
    func(value, '+');
    return m_value;
}
double Calculate::substract(double value){
    m_value -= value;
    func(value, '-');
    return m_value;
}
double Calculate::multiply(double value){
    m_value *= value;
    func(value, '*');
    return m_value;
}
double Calculate::divide(double value){
    m_value /= value;
    func(value, '/');
    return m_value;
}
void Calculate::undo(){
    if(idx>=0){
        idx--;
        switch(a_op[idx]){
            case '+':
                m_value -= a_value[idx];
                break;
            case '-':
                m_value += a_value[idx];
                break;
            case '*':
                m_value /= a_value[idx];
                break;
            case '/':
                m_value *= a_value[idx];
                break;
            }   
    }
}
bool Calculate::lastOperation(char& op, double& value){
    if(idx==0) return false;
    else{
        op = a_op[idx-1];
        value = a_value[idx-1];
        return true;
    }
}
