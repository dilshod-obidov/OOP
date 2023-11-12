#include <iostream>
#include "Book.h"
using namespace std;

class EBook : public Book {
    string m_drmkey;
    string m_format;
public:
    EBook(string title, string isbn, float price, string drmkey, string format="Kindle")
        : Book(title, isbn, price), m_drmkey{drmkey}, m_format{format} {}
    void ShowEBookInfo() const;
};