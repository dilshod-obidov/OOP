#ifndef _TIME_H_
#define _TIME_H_

class Time{
    int m_hour;
    int m_min;
    int m_sec;
public:
    Time(int hour, int min, int sec) :
        m_hour{hour}, m_min{min}, m_sec{sec} {}
    Time(const Time &copy){
        m_hour = copy.m_hour;
        m_min = copy.m_min;
        m_sec = copy.m_sec;
    }
    void printTime();
    void printTime() const; 
};


#endif