#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h> /// pentru a citi parola fara sa se vada pe ecran
#include "Movie.h"
#include "Watchlist.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include "Top3.h"
using namespace std;



/*bool IsLoggedIn(User &user){
    string username, password, un, pw, fn, ln, e, mv, wl;
    char a;
    vector<string> viewed;
    Watchlist<Movie> q;

    cout<< "Enter username: ";
    cin>> username;

    cout<< "Enter password: ";
    for(int i=0;;){/// bucla infinita
        a = getch();
        if(a == '\b' && i >= 1){ /// daca se apasa backspace
            cout<<"\b \b";
            i--;
        }
        else if(a == '\r'){ /// daca se apasa enter
            //password.push_back('\0');
            cout<<'\n';
            break;
        }

        else { password.push_back(a);
               i++;
               cout<<'*';
        } /// cod adaptat dupa : https://www.youtube.com/watch?v=pau4tQ7fFrE&t=352s


    }

    ifstream read("data\\" + username + ".txt");
    getline(read, un);   /// citim username-ul
    getline(read, pw);  /// citim parola
    getline(read, fn);  /// citim prenumele
    getline(read, ln);  /// citim numele de familie
    getline(read, e);   /// citim email-ul

    while(getline(read, mv)) ///citim filmele din lista de vizionari
        viewed.push_back(mv);
    read.close();

    ifstream readw("data\\" + username + "W.txt"); /// fisier separat pentru watch list
    while(getline(readw, wl)){
            Movie m(wl);  /// construim un film cu numele wl
            q.push(m);    /// il adaugam la watchlist

    }
    readw.close();
    if(un == username && pw == password)
        {
            User temp(fn, ln, un, e, pw, viewed, q);
            user = temp;
            return true;
        }

    return false;
}*/

/*void LogIn(User &user){ /// cod adaptat dupa: https://www.youtube.com/watch?v=I_aWPGCaaFA
    bool status = IsLoggedIn(user);

    if(!status){
        cout<<"Login failed: Invalid username or password\n";
        return;
    }

    else{
        cout<<"Welcome back "<<user.get_user_name()<<"!\n";
        return;
    }

}*/

void Create_Account(User &user){

    string last_name, first_name, email, password, user_name;
    vector<string> viewed;
    Watchlist<Movie> q;
    cout<<"Create an account:\n";
    cout<<"First name: "; cin>>first_name;
    cout<<"Last name: "; cin>>last_name;
    cout<<"Email: "; cin>>email;
    cout<<"User name: "; cin>>user_name;
    cout<<"Password:"; cin>>password;


    bool add=1;
    while(add == 1){
        int key;
        cout<<"Do you want to mark a movie as viewed? (Press 1 for YES or 0 for NO)\n";
        cout<<"Your action: ";
        cin>>key;
        if(key == 1)
        {
            string movie;
            cout<<"Enter movie name: ";
            cin.ignore(); /// nu merge getline fara
            getline(cin, movie);  /// https://www.decodejava.com/cpp-how-to-read-string-from-console.htm
            viewed.push_back(movie);
        }
        else {cout<<"Account successfully created!"; add=0;}
    }

    cout<<"\n";

    User temp(first_name, last_name, user_name, email, password, viewed, q);
    user = temp;
    /// q este un vector cu 0 elemente

    ///Scriem un fisier cu datele utilizatoruluui
    ofstream file;
    file.open("data\\" + user_name + ".txt");

    file << user_name << endl;
    file << password << endl;
    file << first_name << endl;
    file << last_name << endl;
    file << email << endl;
    for(int i=0;i<viewed.size();i++)
        file << viewed[i] << endl;
    file.close();

    ofstream filew;
    filew.open("data\\" + user_name + "W.txt"); /// fisier separat pentru watch list
    filew.close();

}

/*bool LogIn_Admin(Admin &admin){
     string name, password;
     cout<< "Enter username: ";
     cin.ignore();
     getline(cin, name);
     cout<< "Enter password: ";
     getline(cin, password);

     if(name == admin.get_name() && password == admin.get_password())
        return 1;
     return 0;


}*/

void Disconnect(vector<Client*> c)
{
    if(c.empty()){ cout<<"No clients have connected!"; return;}
    for(int i = 0; i < c.size(); i ++)
    {
        User *u = dynamic_cast<User*>(c[i]);
        if(u != NULL){
            u->show_type();
            cout<<" has logged out.\n";
            delete u;
        }
        else{
            Admin *a = dynamic_cast<Admin*>(c[i]);
            if(a != NULL){
                a->show_type();
                cout<<" has logged out.\n";
                delete a;
            }
        }
    }
}

int main()
{
    bool done = 0, r; /// when done is 1 we exit main
    char key;
    User user;
    Admin admin;
    Movie m;
    Top_comedy t;
    ifstream fin("movies.txt");

    vector<Client*> c;

    /// urmatoare secventa de cod permite logarea in aplicatie a mai multor utilizatori in acelasi timp
    /// atunci cand se apasa tasta 0 aplicatia se inchide si afiseaza tipul fiecarui client
    while(!done){
        int cmd;
        cout<<"PRESS 1 - to log in as an user\n";
        cout<<"PRESS 2 - to log in as an admin\n";
        cout<<"Press 0 - to disconnect\n";
        cin>>cmd;
        if(cmd == 1){
            User *u = new User;
            if(u->LogIn()) c.push_back(u);
            u = nullptr;
        }
        if(cmd == 2){
            Admin *a = new Admin;
            if(a->LogIn()) {cout<<"You are logged as an admin\n"; c.push_back(a);}
            else cout<<"You are not an admin\n";
            a = nullptr;
        }
        if(cmd == 0){
            Disconnect(c);
            done = 1;
        }
    }

   // Awarded_Movie a;
   // a.give_award("Oscar");
    return 0;

    /*cout<<"Welcome!";  ---> parte din etapa 3
    while(done == 0)
    {
        cout<<"\n";
        cout<<"------------------------------------------------------\n";
        cout<<"To log into your account press 1 on your keyboard\n";
        cout<<"You don't have an account? Press 2 to register!\n";
        cout<<"\nTo log in as an admin, press 3\n";
        cout<<"To exit the app, press 0\n";
        cout<<"------------------------------------------------------\n";
        cout<<"Your action: ";
        cin>>key;

        switch(key){
            case '1': r = user.LogIn();
                    //User_Actions();
                     break;

            case '2': Create_Account(user);
                    break;

            case '3': if(admin.LogIn()) cout<<"You are logged as an admin\n";
                        //Admin_Actions();
                     //}
                    else cout<<"You are not an admin!\n";
                    break;

            case '0': done = 1;
                    break;

            default: cout<<"Sorry, the entered command does not exist!\n";

        }

    }

    return 0;*/
}
