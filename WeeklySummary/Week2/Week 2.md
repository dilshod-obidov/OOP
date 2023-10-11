# Review of IGS1232

## Unions   

Unions allow one portion of memory to be accessed as different data types.
- All member elements occupy the same physical space in memory
- The size of the union is the one of the largest member element.

```cpp
#include <iostream>
using namespace std;

union ip_address {
    unsigned long laddr;
    unsigned char saddr[4];
};

int main() {
    ip_address addr;
    addr.saddr[0] = 1;
    addr.saddr[1] = 0;
    addr.saddr[2] = 0;
    addr.saddr[3] = 127;
    cout << hex << addr.laddr;
    return 0;
}
```
> ### Output
> 1000007F


## Enumeration (enum)

Enumeration (enum) is a user-defined type consisting of a set of enumerators (enumerator-named integer constants).

- Enum type only takes one of the enumerators.

```cpp
#include <iostream>
using namespace std;

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
    week today;
    today = Wednesday;

    if (today == Wednesday) {
        cout << "Today is Wednesday." << endl;
    }

    cout << today << endl;
    return 0;
}
```
> ### Output
> Today is Wednesday.  
> 3


## Scoped Enumeration

- Scoped enumeration
- Prevent implicit conversion with int type

```cpp
#include <iostream>
using namespace std;

enum class week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
    week today;
    today = week::Wednesday; // Scope ‘week’ required

    if (today == week::Wednesday) {
        cout << "Today is Wednesday." << endl;
    }

    cout << int(today) << endl; // Explicit conversion required
    return 0;
}
```
> ### Output
> Today is Wednesday.  
> 3
