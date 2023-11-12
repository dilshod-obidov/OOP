#include <iostream>
#include "EBook.h"

using namespace std;

const int MAX_BOOK = 100;

class EBookLibrary{
    EBook* m_ebooks[100];
    int m_cnt = 0;
public:
    ~EBookLibrary(){
        for(int i=0; i<m_cnt; i++){
            delete m_ebooks[i];
        }
    }
    void AddBook(EBook*);
    void ShowAllBooks();
};