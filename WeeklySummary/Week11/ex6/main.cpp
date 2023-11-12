#include <iostream>
#include "Book.h"
#include "EBook.h"
#include "EBookLibrary.h"

using namespace std;

int main() {
    EBookLibrary elib;
    elib.AddBook(new EBook{ "Book1", "1234567890", 10.99, "AAAAAA", "ePub" });
    elib.AddBook(new EBook{ "Book2", "2345678901", 20.99, "BBBBBB" });
    elib.AddBook(new EBook{ "Book3", "3456789012", 30.99, "CCCCCC", "ePub"});
    elib.AddBook(new EBook{ "Book4", "4567890123", 40.99, "DDDDDD" });
    elib.ShowAllBooks();

    return 0;
}

