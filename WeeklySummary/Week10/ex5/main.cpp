#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
using namespace std;
class IntArray
{
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len];
    }
    friend void setArray(IntArray&, int*, int);
    friend void displayArray(const IntArray&);

    ~IntArray() {
        if (m_data) delete[] m_data;
    }
};
void setArray(IntArray& ar, int* data, int arSize){
    for(int i=0; i<arSize; i++){
        ar.m_data[i] = data[i];
    }
}

void displayArray(const IntArray& ar){
    for(int i=0; i<ar.m_len; i++){
        cout << "[" << i << "] " << ar.m_data[i] << endl;
    }
}

const int arSize = 20;

int main() {
    int i;
    int data[arSize];
    IntArray ar{ arSize };

    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) data[i] = rand() % 100;

    setArray(ar, data, arSize);
    displayArray(ar);

    return 0;
}
