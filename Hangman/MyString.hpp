//
//  MyString.hpp
//  CECS2223
//
//  Created by Maria Vargas Aponte on 5/24/16.
//  Copyright © 2016 Maria M. Vargas Aponte. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>
#include <cstring>
#include<iostream>

using namespace std;

const int MAX_LEN = 80;

class MyString {

private:
    char s[MAX_LEN + 1];
    
public:
    MyString(const char *s = "");
    MyString(char ch);
    MyString(const MyString &aMyString);
    ~MyString(void);
    MyString &operator=(const char* s);
    MyString &operator=(char cha);
    MyString &operator =(const MyString &aMyString);
    MyString &operator=(const string &word);
    void setS(const char *s);
    const char* getS()const;
    MyString operator+(const char* s)const;
    MyString operator+(char ch)const;
    MyString operator+(const MyString &aMyString)const;
    friend MyString operator+(const char* s, const MyString &aMyString);
    friend MyString operator+(char ch, const MyString &aMyString);
    bool operator==(const char* s)const;
    bool operator==(const MyString &aMyString)const;
    friend bool operator ==(const char* s, const MyString &aMyString);
    bool operator !=(const char* s)const;
    bool operator !=(const MyString & aMyString)const;
    friend bool operator !=(const char* s, const MyString &aMyString);
    bool operator >(const char* s)const;
    bool operator>(const MyString &aMyString)const;
    friend bool operator>(const char* s, const MyString &aMyString);
    bool operator<(const char* s)const;
    bool operator<(const MyString &aMyString)const;
    friend bool operator<(const char* s, const MyString &aMyString);
    const char &operator[](int index)const;
    char &operator[](int index);
    friend std::istream &operator >> (std::istream &in, MyString &);
    friend std::ostream &operator<<(std::ostream &out, const MyString &);
    MyString trimLeadingSpaces()const;
    MyString trimEndingSpace()const;
    MyString trimAllSpaces()const;
    MyString toUpperCase()const;
    MyString toLowerCase()const;
    MyString createSubstring(int from, int to)const;
    int len()const;
    bool isEpmty()const;
    MyString reverse()const;
    int indexOf(char ch)const;
    int indexOfLast(char ch)const;
    bool include(char ch)const;
    int frequency(char ch)const;
    bool representAnUnsigninterger()const;
    bool representAnInterger()const;
    bool representAReal()const;
    static int MaxLen();
    MyString &operator+=(const MyString &aMyString);
    MyString &operator+=(const char* s);
    MyString &operator+=(char ch);
    MyString &operator++();
    MyString operator++(int);
    MyString &operator--();
    MyString operator--(int);
    
    

};

#endif /* MyString_hpp */
