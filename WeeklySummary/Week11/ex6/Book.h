#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
using namespace std;

class Book{
    string m_title;
    string m_isbn;
    float m_price;
public:
    Book(string title, string isbn, float price) : m_title{title}, m_isbn{isbn}, m_price{price} {}
    void ShowBookInfo() const;

};

#endif