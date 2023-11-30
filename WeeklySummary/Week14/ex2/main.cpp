#include <iostream>
#include <cstring>

using namespace std;

class InhaString{
private:
    char* m_msg;
    int m_len;

public:
    InhaString() : m_msg{nullptr}, m_len{0} {} 
    InhaString(const char* msg){
        m_len = strlen(msg);
        m_msg = new char[m_len];
        strcpy(m_msg, msg);
    }
    InhaString(const InhaString& istr) 
        : m_len{istr.m_len} {
            m_msg = new char[istr.m_len];
            strcpy(m_msg, istr.m_msg);
        }
    InhaString(const char* msg, const int len)
        : m_len{len} {
            m_msg = new char[len];
            strcpy(m_msg, msg);
        }
    ~InhaString(){
        if (m_msg) delete m_msg;
    }   

    InhaString operator+(const InhaString& istr);
    InhaString& operator=(const InhaString& istr);

    InhaString& operator+=(const InhaString& istr);

    friend ostream& operator<<(ostream& out, const InhaString& istr);
    friend istream& operator>>(istream& in, InhaString& istr);
    friend bool operator==(const InhaString& istr1, const InhaString& istr2);
};

InhaString InhaString::operator+(const InhaString& istr){
    int temp_len = m_len + istr.m_len;
    char* temp_msg = new char[temp_len];

    for(int i = 0; i < m_len; ++i)
        temp_msg[i] = m_msg[i];
    for(int i = 0; i < istr.m_len; ++i)
        temp_msg[i + m_len] = istr.m_msg[i];

    InhaString temp_istr{temp_msg, temp_len};
    delete[] temp_msg;
    return temp_istr;
}
InhaString& InhaString::operator=(const InhaString& istr){
    m_msg = istr.m_msg;
    m_len = istr.m_len;
    return *this;
}

InhaString& InhaString::operator+=(const InhaString& istr){
    int temp_len = m_len + istr.m_len;
    char* temp_msg = new char[temp_len];

    for(int i = 0; i < m_len; ++i)
        temp_msg[i] = m_msg[i];
    for(int i = 0; i < istr.m_len; ++i)
        temp_msg[i + m_len] = istr.m_msg[i];

    delete[] m_msg;
    m_msg = temp_msg;
    m_len = temp_len;
    return *this;
}

ostream& operator<<(ostream& out, const InhaString& istr){
    out << istr.m_msg;
    return out;
}
istream& operator>>(istream& in, InhaString& istr){
    char temp[100];
    in >> temp;
    delete[] istr.m_msg;
    istr.m_len = strlen(temp);
    istr.m_msg = new char[istr.m_len + 1];
    strcpy(istr.m_msg, temp);
    return in;
    
}

bool operator==(const InhaString& istr1, const InhaString& istr2){
    return (strcmp(istr1.m_msg, istr2.m_msg) == 0 && istr1.m_len == istr2.m_len);

}

int main(){
    InhaString str1 = "I like ";
    InhaString str2 = "string class";
    InhaString str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    InhaString st{ str3 };

    str1 += str2;
    if(str1 == str3)
        cout << "The two strings are identical" << endl;
    else 
        cout << "The two strings are different" << endl;

    InhaString str4;
    cout << "Enter a string: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;

    return 0;
}