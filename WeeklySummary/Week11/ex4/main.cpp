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
class RedBanana : public Banana{
public:
    RedBanana(string name="red banana", string color="red") : Banana{name, color} {}
};

int main(){
    Apple a{"red"};
    Banana b;
    RedBanana c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}