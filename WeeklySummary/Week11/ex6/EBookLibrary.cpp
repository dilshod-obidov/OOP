#include <iostream>
#include "EBook.h"
#include "EBookLibrary.h"

using namespace std;

void EBookLibrary::AddBook(EBook* ebook){
    if(m_cnt<MAX_BOOK){
        m_ebooks[m_cnt] = ebook;
        m_cnt++;
    }
    else cout << "EBookLibrary is full" << endl;
}

void EBookLibrary::ShowAllBooks(){
    for(int i=0; i<m_cnt; i++){
        m_ebooks[i]->ShowEBookInfo();
        cout << endl;
    }
}