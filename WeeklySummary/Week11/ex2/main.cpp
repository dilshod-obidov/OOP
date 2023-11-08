#include <iostream>
#include "Test.h"

using namespace std;
int Test::s_IDgenerator = 0;
int main() {
    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;

    Test t1{ 10 }, t2{ 20 }, t3{ 30 }, t4{ 40 };
    cout << "[t1] data: " << t1.getData() << ", id: " << t1.getID() << endl;
    cout << "[t2] data: " << t2.getData() << ", id: " << t2.getID() << endl;
    cout << "[t3] data: " << t3.getData() << ", id: " << t3.getID() << endl;
    cout << "[t4] data: " << t4.getData() << ", id: " << t4.getID() << endl;

    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;
    return 0;
}
