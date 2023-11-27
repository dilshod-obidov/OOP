#include <iostream>

using namespace std;

const int SIZE = 8;

class IntList{
private: 
    int m_list[SIZE];

public:
    int& operator[](int);
};

int& IntList::operator[](int index){
    return m_list[index];
}

int main(){
    IntList list;
    for(int i = 0; i < SIZE; ++i) list[i] = i * 3;

    for(int i = 0; i < SIZE; ++i) cout << list[i] << " ";

}