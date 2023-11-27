#include <iostream>

using namespace std;

const int SIZE = 8;

class IntList{
private: 
    int m_list[SIZE];

public:
    IntList(){
        for(int i = 0; i < SIZE; ++i){
            m_list[i] = i * 2;
        }
    }

    // return a reference
    int& operator[](int);
    // const operator[]
    const int& operator[](int) const;
};

int& IntList::operator[](int index){
    return m_list[index];
}

const int& IntList::operator[](int index) const{
    return m_list[index];
}

int main(){
    IntList list;
    for(int i = 0; i < SIZE; ++i) cout << list[i] << " ";
    cout << endl;
    list[0] = 100; // okay
    for(int i = 0; i < SIZE; ++i) cout << list[i] << " ";
    cout << endl;

    const IntList c_list;
    for(int i = 0; i < SIZE; ++i) cout << c_list[i] << " ";
    // c_list[0] = 99; // illegal

}