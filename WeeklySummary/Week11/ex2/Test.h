#include <iostream>
using namespace std;

class Test{
    int m_id;
    int m_data;
    static int s_counter;
    static int s_IDgenerator;
public:
    Test(int data) : m_data{data}, m_id{s_IDgenerator++} {
        s_counter++;
    }
    static int NumOfObjects();
    int getData() const;
    int getID() const;
};
