#include <iostream>
#include "Book.h"
using namespace std;

void Book::ShowBookInfo() const{
    cout << "Title: " << m_title << endl;
    cout << "ISBN: " << m_isbn << endl;
    cout << "Price(USD): " << m_price << endl;
}