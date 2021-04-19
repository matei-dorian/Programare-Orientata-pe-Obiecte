#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include <fstream>
#include "Client.h"

using namespace std;


class Admin : public Client{
    const string name;
    string password;

public:
    ///Constructori
    Admin();
    Admin(string _name);
    Admin(string _name, string password);
    Admin(const Admin &a);

    ///Destructori
    ~Admin();

    ///Getteri
    string get_name() {return name;}
    string get_password() {return password;}

    ///Setteri
    void set_password(string password) {this->password = password;}

    ///Operatori
    /// =
    Admin& operator = (const Admin &admin);

    ///<<
    friend std::ostream& operator<< (std::ostream &out, const Admin &admin);

    ///>>
     friend std::istream& operator>> (std::istream &in, Admin &admin);

     ///Metode
     void Add_movie();
     bool LogIn();
     void show_type(){cout<<"One admin";}

};

Admin :: Admin() : name("Admin1"){
    password = "123";
}

Admin :: Admin(string _name) : name(_name){
    password = "123";
}

Admin :: Admin(string _name, string password) : name(_name){
    this->password = password;
}

Admin :: Admin(const Admin &a) : name(a.name){
    this->password = a.password;
}

Admin :: ~Admin(){
   // cout<<"Admin killed";
}

Admin& Admin :: operator = (const Admin &admin){
    /// Trebuie initializat mai intai cu numele corect
    if(this != &admin){
        this->password = admin.password;
    }
    return *this;
}

std :: ostream& operator<< (std::ostream &out, const Admin &admin){
    out<<"Admin name: "<<admin.name<<"\n";
    out<<"Admin password: "<<admin.password<<"\n";
    return out;
}

std :: istream& operator>> (std::istream &in, Admin &admin){
    /*cout<<"Enter an admin name (no spaces allowed!): ";
    in>>admin.name; -> fac in functie */
    cout<<"Enter a password: ";
    in>>admin.password;
    return in;
}

void Admin :: Add_movie(){

        string s;
        int x;
        char c;
        float y;
        long long l;
        double d;

        ofstream file;
        file.open("movies.txt", fstream::app); /// deschidem fisierul in modul append
        cout<<"To add a new movie, enter the following data:\n";

        cout<<"Name of the movie: ";
        cin.ignore();
        getline(cin, s);
        file << s <<"\n";

        cout<<"The year it was made: ";
        cin>>x;
        file << x <<"\n";

        cout<<"Name of the director: ";
        cin.ignore();
        getline(cin, s);
        file << s <<"\n";

        cout<<"Genre: ";
        cin>>c;
        file << c <<"\n";

        cout<<"Total runtime in seconds: ";
        cin>>l;
        file<< l <<"\n";

        cout<<"Budget: ";
        cin>>y;
        file << y <<"\n";

        cout<<"Number of actors in the cast: ";
        cin>>x;
        file << x <<"\n";
        if(x>0){
            cout<<"Members of the cast: ";
            for(int i=0;i<x;i++){
                cin.ignore();
                getline(cin, s);
                file << s <<"\n";
            }
        }

        cout<<"Number of platforms: ";
        cin>>x;
        file << x <<"\n";
        if(x>0){
            cout<<"Platforms where the movie is available: ";
            for(int i=0;i<x;i++){
                cin>>c;
                file << c <<"\n";
            }
        }

        cout<<"Number of reviews: ";
        cin>>x;
        file << x <<"\n";
        if(x>0){
            cout<<"Marks: ";
            for(int i=0;i<x;i++){
                cin>>y;
                file << y <<"\n";
            }
        }

        cout<<"Rating: ";
        cin>>d;
        file<<d<<"\n";

        if(d > 8.5)
            file<<1<<"\n";
        else
            file<<0<<"\n";

        cout<<"Number of views: ";
        cin>>l;
        file<<l<<"\n";
        cout<<"Movie added successfully!\n";
    }

bool Admin :: LogIn(){
     string name, password;
     cout<< "Enter username: ";
     cin.ignore();
     getline(cin, name);
     cout<< "Enter password: ";
     getline(cin, password);

     if(name == this->name && password == this->password)
        return 1;
     return 0;


}
#endif // ADMIN_H_INCLUDED
