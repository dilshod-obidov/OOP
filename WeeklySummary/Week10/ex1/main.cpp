#include <iostream>
#include "Calculate.h"

using namespace std;

int main(void) {
    Calculate cc;
    int i;
    char op;
    double value;
    for (i = 0; i < 10; ++i) {
        cout << "Select math operator(+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;

        switch (op) {
        case '+':
            cout << cc.getValue() << " + " << value;
            cout << " = " << cc.add(value) << endl;
            break;
        case '-':
            cout << cc.getValue() << " - " << value;
            cout << " = " << cc.substract(value) << endl;
            break;
        case '*':
            cout << cc.getValue() << " * " << value;
            cout << " = " << cc.multiply(value) << endl;
            break;
        case '/':
            cout << cc.getValue() << " / " << value;
            cout << " = " << cc.divide(value) << endl;
            break;
        }
    }
    return 0;
}
