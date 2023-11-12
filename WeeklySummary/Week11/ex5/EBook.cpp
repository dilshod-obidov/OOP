#include <iostream>
#include "EBook.h"
using namespace std;

void EBook::ShowEBookInfo() const{
    Book::ShowBookInfo();
    cout << "DRMKey: " << m_drmkey << endl;
    cout << "Format: " << m_format << endl;
}