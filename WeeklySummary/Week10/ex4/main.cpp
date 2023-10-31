#include <iostream>
#include "Time.h"

using namespace std;

int main(){
    const Time t0{7,3,5};
    Time t1{13,45,9};
    const Time t2{t1};

    cout << "t0: ";
    t0.printTime();
    cout << "t1: ";
    t1.printTime();
    cout << "t2: ";
    t2.printTime();

    return 0;
}