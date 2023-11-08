#include <iostream>
#include "Fruit.h"

using namespace std;

class Apple : public Fruit{
public:
    Apple(string color) : Fruit{"apple", color} {}
};
class Banana : public Fruit{
public:
    Banana(string name="banana", string color="yellow") : Fruit{name, color} {}
};

int main(){
    Apple a{"red"};
    Banana b;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;
}