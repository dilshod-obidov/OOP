#include <iostream> 
#include "Calculate.h"

double Calculate::getValue(){
    return m_value;
}
double Calculate::add(double value){
    m_value += value;
    return m_value;
}
double Calculate::substract(double value){
    m_value -= value;
    return m_value;
}
double Calculate::multiply(double value){
    m_value *= value;
    return m_value;
}
double Calculate::divide(double value){
    m_value /= value;
    return m_value;
}