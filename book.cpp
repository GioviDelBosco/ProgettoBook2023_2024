/*
Progetto book 
Gruppo: è un 2.1 o un 2.0?
Membri: Giovanni Sgaravatto, Mattia Colapietro, Filippo Artico
*/

//file.cpp book
#include <iostream>
#include <string>
#include "book.h"

using namespace std;

Book::Book(){
    isbn="000-000-000-0";
    nome="";
    cognome="";
    titolo="";
    disponibile=true;
};
Book::Book(string isbn, string titolo, string nome, string cognome, bool disponibile){
    this->isbn=isbn;
    this->titolo=titolo;
    this->nome=nome;
    this->cognome=cognome;
    this->disponibile=true;
}
Book::Book(string nome, string cognome, string titolo, string isbn){
    this->nome=nome;
    this->cognome=cognome;
    this->titolo=titolo;
    this->isbn=isbn;
}

//Tutti i get necessari
string Book::getIsbn(){
    return isbn;
}
string Book::getNome(){
    return nome;
}
string Book::getCognome(){
    return cognome;
}
string Book::getTitolo(){
    return titolo;
}
bool Book::getDisponibile(){
    return disponibile;
}

//Tutti i set necessari
void Book::setIsbn(string i){
    isbn=i;
}
void Book::setTitolo(string t){
    titolo=t;
}
void Book::setNome(string n){
    nome=n;
}
void Book::setCognome(string c){
    cognome=c;
}
void Book::setDisponibile(bool d){
    disponibile=d;
}

//prestito restituzione controlla se il libro è disponibile, se si, prende in prestito il libro, sennò no :D
void Book::prestitoRestituzione(Book &i){
    Book isbn=i;
    if(isbn.getDisponibile()==false){
        cout<<"Hai restituito il libro in prestito!\n";
        isbn.setDisponibile(true);
    }else if(isbn.getDisponibile()==true){
        cout<<"Hai preso il libro in prestito!\n";
        isbn.setDisponibile(false);
    }
}
//checkIsbn controlla i requisiti minimi di ISBN
bool checkIsbn(string isbnNumber){
    //controllo se è vuoto
    if(isbnNumber.empty()){
        cout<<"non hai inserito nessun isbn!\n";
        return false;
    }
    //controllo che isbn sia lungo 13
    int n=isbnNumber.length(); //n è la lunghezza di isbn
    if(n!=13){
        cout<<"Devi inserire 13 caratteri\n";
        return false;
    }
    //controllo l'inserimento di '-' ogni 3 numeri
    for (int i = 0; i < 12; i++)
    {
        char value= isbnNumber[i];
        if(i==3 || i== 7|| i==11){
            if (value!='-')
            {
                cout<<"Non hai inserio '-' ogni 3 numeri\n";
                return false;
            }
            else if(value<'0' || value>'9'){
                cout<<"ISBN errato";
                return false;
            }
            
        }
    }
    return true;
    
}
//overload operatori
bool operator==(Book lib1, Book lib2){
    if (lib1.getIsbn()==lib2.getIsbn()){
        return true;
    }
    return false;
}
bool operator!=(Book lib1, Book lib2){
    if(lib1.getIsbn()!=lib2.getIsbn()){
        return true;
    }
    return false;
}
ostream &operator<<(ostream &os, Book lib1){
    os<<"Titolo: "<<lib1.getTitolo()<< "\n"
      <<"Autore: "<<lib1.getNome() <<" "<<lib1.getCognome()<<"\n"
      <<"Codice Libro: "<<lib1.getIsbn()<<"\n";
      return os;
}
