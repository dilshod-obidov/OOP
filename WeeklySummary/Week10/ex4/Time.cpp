#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

void Time::printTime(){
    cout << setfill('0') << setw(2) << m_hour << ":";
    cout << setfill('0') << setw(2) << m_min << ":";
    cout << setfill('0') << setw(2) << m_sec << endl;
}

void Time::printTime() const{
    cout << setfill('0') << setw(2) << m_hour%12 << ":";
    cout << setfill('0') << setw(2) << m_min << ":";
    cout << setfill('0') << setw(2) << m_sec << ((m_hour<12) ? " AM" : " PM") << endl;
}