#include <iostream>
#include "Test.h"
using namespace std;

int Test::s_counter;

int Test::NumOfObjects(){
    return s_counter;
}
int Test::getData() const{
    return m_data;
}
int Test::getID() const{
    return m_id;
}
