/*
Progetto book 
Gruppo: è un 2.1 o un 2.0?
Membri: Giovanni Sgaravatto, Mattia Colapietro, Filippo Artico
*/

//file.h DATE
#ifndef DATA
#define DATA

#include<iostream>
#include<string>

using namespace std;

class Date{
    
    private:
    int day;
    int month;
    int year;

    public:
    Date();
    Date(int day, int month, int year): day(day), month(month), year(year){}
    void setData(int d,int m, int y);
    string getData();
    static bool check_data(int day,int month, int year);
    friend ostream& operator<<(ostream& os, Date datina);
};

ostream& operator<<(ostream& os, Date datina);

#endif