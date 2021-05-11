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
     void block_user(set<string> &names);
     void see_donations();
     void print_users();

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
        cin.ignore();
        if(x>0){
            cout<<"Members of the cast: ";
            for(int i=0;i<x;i++){

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

        double sum = 0;
        cout<<"Number of reviews: ";
        cin>>x;
        file << x <<"\n";
        if(x>0){
            cout<<"Marks: ";
            for(int i=0;i<x;i++){
                cin>>y;
                file << y <<"\n";
                sum = sum + y;
            }
        }

        d = sum/(double)x;
        cout<<"Rating: "<<d<<"\n";

        file<<d<<"\n";

        cout<<"Number of views: ";
        cin>>l;
        file<<l<<"\n";
        file<<"-\n";
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

void Admin :: block_user(set<string> &names){
    string blocked_name;
    cout<<"Enter the username of the account you want to block: ";
    cin>>blocked_name;
    if(names.find(blocked_name) != names.end())
        { names.erase(blocked_name);
          cout<<"\nThe user was blocked!\n";
          ofstream fout("usernames.txt");
          for(auto it = names.begin(); it != names.end(); it ++)
            fout<<*it<<"\n";
          fout.close();
          return;
        }
    cout<<"The user was already blocked or did not exist in the database.\n";

}

void Admin :: see_donations(){
    cout<<"A total of "<<Premium_User :: get_donations()<<" euros were donated by our users. Yey!\n";
}

void Admin :: print_users(){
    string name;
    cout<<"These are all the registered users:\n";
    ifstream fin("usernames.txt");
    while(fin>>name){
        cout<<name<<"\n";
    }
    fin.close();
}
#endif // ADMIN_H_INCLUDED
