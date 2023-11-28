# Operator Overloading

- In C++, operators are implemented as functions.
- By using function overloading on the operator functions, we can define our own versions of the operators that work with different data types (including user-defined classes).
- Using function overloading to overload operators is called operator overloading.

---

## Resolving Overloaded Operators

- If all the operands are fundamental data types:
    - The compiler will call a built-in routine if one exists.
    - If one does not exist, the compiler will produce a compile error.

- If any of the operands are user data types:
    - The compiler checks if the type has a matching overloaded operator function it can call.
    - If it can’t find one, it will try to convert one or more of the user-defined type operands into fundamental data types so it can use a matching built-in operator.
    - If this fails, then it will produce a compile error.

---

## Limitations on Operator Overloading

- Operators that cannot be overloaded: 
  - conditional (?:)
  - sizeof
  - scope (::)
  - member selector (.)
  - member pointer selector (.*)
  - typeid
  - the casting operators
- Can only overload the operators that exist. Cannot create new operators or rename existing operators
- At least one of the operands in an overloaded operator must be a user-defined type
- Not possible to change the number of operands an operator supports
- All operators keep their default precedence and associativity

---

**Recommendations:**

- Keep the function of the operators as close to the original intent of the operators as possible.
- If the meaning of an operator is not clear and intuitive, use a named function instead.

--- 


### Associativity 
- how operators of the same precedence are grouped in the absence of parentheses
> **C++ operators with precedence and associativity**
  
| Precedence | Category | Operator | Associativity |
| --- | --- | --- | --- |
| High | Postfix | () [] -> . ++ - - | Left to right |
|  | Unary | + - ! ~ ++ -- (type)* & sizeof | Right to left |
|  | Multiplicative | * / % | Left to right |
|  | Additive | + - | Left to right |
|  | Shift | << >> | Left to right |
|  | Relational | < <= > >= | Left to right |
|  | Equality | == != | Left to right |
|  | Bitwise AND | & | Left to right |
|  | Bitwise XOR | ^ | Left to right |
|  | Bitwise OR | \| | Left to right |
|  | Logical AND | && | Left to right |
|  | Logical OR | \|\| | Left to right |
|  | Conditional | ?: | Right to left |
|  | Assignment | = += -= *= /= %= >>= <<= &= ^= \|= | Right to left |
| Low | Comma | , | Left to right |

---

## Overloading arithmetic operators

**Binary operators:**
- takes two operands, one on each side of the operator

**Arithmetic operators** (subset of binary operators):
- +, -, *, /
   
> *pos1* **+** *pos2* - (*operand* **operator** *operand*)
>
> **operator+**(*pos1*, *pos2*) 

### Three different implementations for operator overloading:
- As a member function
- As a [friend function](https://github.com/dilshod-obidov/OOP/blob/main/WeeklySummary/Week13/Operator-Overloading-1/arithmetic_f.cpp)
- As a [normal function](https://github.com/dilshod-obidov/OOP/blob/main/WeeklySummary/Week13/Operator-Overloading-1/arithmetic_n.cpp)

---

## Overloading the I/O operators

### Overloading operator<<

Binary operator:   
- The **left operand** is the std::cout object, and the **right operand** is user defined class   

> std::cout is an object of std::ostream

```cpp
Point point{2, 3};
std::cout << point;
```
---
### Overloading operator>>

Binary operator:   
- The **left operand** is the std::cin object, and the **right operand** is user defined class   

> std::cin is an object of std::istream

```cpp
Point point{};
std::cin >> point;
```
---



