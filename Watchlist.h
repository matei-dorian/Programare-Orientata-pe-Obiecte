#ifndef WATCHLIST_H_INCLUDED
#define WATCHLIST_H_INCLUDED
#include "Movie.h"
using namespace std;


template <class T> class Watchlist{
    /// aceast clasa va fi practic un vector dinamic din stl
    /// sursa: https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/

    T *v; /// pointer catre vectorul nostru
    int capacity; /// lungimea maxima
    int current; /// lungimea curenta

public:

    ///Constructor
    Watchlist(){
        v = new T[1];
        capacity = 1;
        current = 0;
    }

    Watchlist(int capacity){
        v = new T[capacity];
        this->capacity = capacity;
        current = 0;
    }

    Watchlist(const Movie m){
        v = new T[1];
        capacity = 1;
        current = 1;
        v[0] = m;
    }

    Watchlist(const Watchlist<T> &w){
        v = new T[w.capacity];
        capacity = w.capacity;
        current = w.current;
        for(int i=0;i<w.current;i++)
            v[i] = w.v[i];

    }

    ///Destructor
    ~Watchlist(){
        delete [] v;
    };

    ///Getteri
    int get_capacity(){return capacity; }
    int get_size(){return current; }

    ///Setteri
    void set_capacity(int capacity){this->capacity = capacity;}

    /// Operatori
    /// =
    Watchlist& operator = (const Watchlist<T> &w){

        this->current = w.current;
        this->capacity = w.capacity;
        T *aux = new T [w.capacity];

        for(int i=0;i<w.capacity;i++)
            aux[i] = w.v[i];
        delete [] v;
        v = aux;

        return *this;
    }

    ///<<
    friend std::ostream& operator<< (std::ostream &out, const Watchlist<T> &w){
        if(w.current == 0)
            out<<"Your watch list is empty!\n";
        else{
            out<<"You have "<<w.current<<" movies in your watch list:\n";
            for(int i=0;i<w.current;i++)
                out<<i<<". "<<w.v[i]<<"\n";

        }
        return out;
    }

    ///>>
    friend std::istream& operator>> (std::istream &in, Watchlist<T> &w){
        int x;
        Movie m;
        in>>x;

        for(int i=0;i<x;i++){
            in>>m;
            w.push(m);
        }
        return in;
    }

    ///Metode
    void push(T data){ /// metoda care adauga un element la finalul vectorului

        if (current == capacity) { /// daca nu avem suficient spatiu disponibil -> dublam spatiul
            T* aux = new T[2 * capacity];


            for (int i=0;i<current;i++) { /// copiem din vectorul initial in vectorul marit
                aux[i] = v[i];
            }

            ///  stergem vectorul initial
            delete[] v;
            capacity *= 2;
            v = aux;
        }

        v[current++] = data;

    }

    void pop() { current--; } /// stergem ultimul element

    void print(){ /// functia afiseaza watchlistul userului
        cout<<"Your Watchlist: ";
        for (int i=0;i<current;i++) {
            cout << v[i] << " ";
        }
        cout <<"\n";
    }

    bool isempty(){
        if(current == 0) return 1;
        return 0;
    }
};



#endif // WATCHLIST_H_INCLUDED
