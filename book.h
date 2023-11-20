/*
Progetto book 
Gruppo: è un 2.1 o un 2.0?
Membri: Giovanni Sgaravatto, Mattia Colapietro, Filippo Artico
*/

//file.h book
#ifndef LIBRO
#define LIBRO

#include <iostream>
#include <string>

using namespace std;
class Book
{
private:
    string isbn;
    string titolo;
    string nome;
    string cognome;
    bool disponibile;

public:
    Book();
    Book(string nome, string cognome, string titolo, string isbn);
    Book(string isbn, string titolo, string nome, string cognome, bool disponibile);

    void setIsbn(string i);
    string getIsbn();
    void setTitolo(string t);
    string getTitolo();
    void setNome(string n);
    string getNome();
    void setCognome(string c);
    string getCognome();
    void setDisponibile(bool d);
    bool getDisponibile();
    static void prestitoRestituzione(Book& i);
    friend bool operator==(Book lib1, Book lib2);
    friend bool operator!=(Book lib1, Book lib2);
    friend ostream& operator<<(ostream& os, Book lib1);
    };

    bool operator==(Book lib1, Book lib2);
    bool operator!=(Book lib1, Book lib2);
    ostream& operator<<(ostream& os, Book lib1);

#endif