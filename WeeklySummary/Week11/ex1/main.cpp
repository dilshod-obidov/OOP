#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

class IntArray{
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    IntArray(int len) : m_len{ len } {
        m_data = new int[m_len];
    }

    friend class IntArrayHandler;

    ~IntArray() {
        if (m_data) delete[] m_data;
    }
};

class IntArrayHandler{
    IntArray* m_arr;

public:
    IntArrayHandler(IntArray* arr) : m_arr{arr} {}

    void setArray(int* data, int arSize){
        for(int i=0; i<arSize; i++){
            m_arr -> m_data[i] = data[i];
        }
    }

    void displayArray(){
        for(int i=0; i < m_arr->m_len; i++){
            cout << "[" << i << "] " << m_arr->m_data[i] << endl;
        }
    }
    void stat(){
        int sum=0;
        for(int i=0; i<m_arr->m_len; i++){
            sum+=m_arr->m_data[i];
        }
        cout << "# of elements: " << m_arr->m_len << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum*1.0/m_arr->m_len << endl;
    }
    void setIntArray(IntArray* arr){
        m_arr = arr;
    }
};

const int arSize = 20;

int main() {
    int i;
    int data1[arSize], data2[arSize];
    IntArray ar1{ arSize }, ar2{ arSize };
    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) {
        data1[i] = rand() % 100;
        data2[i] = rand() % 100;
    }
    IntArrayHandler handler{ &ar1 };
    handler.setArray(data1, arSize);
    cout << "== ar1: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar1: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;
    handler.setIntArray(&ar2);
    handler.setArray(data2, arSize);
    cout << endl << "== ar2: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar2: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;
    return 0;
}
