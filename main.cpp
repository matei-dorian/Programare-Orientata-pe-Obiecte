#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <string>
#include <conio.h> /// pentru a citi parola fara sa se vada pe ecran
#include <cstdio> /// pentru transform
#include "Movie.h"
#include "Watchlist.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include "Top3.h"
using namespace std;

map<string, Movie> m; /// dictionar cu elemente de forma titlu film -> obiect film
set<string> names; /// set cu toate username-urile

Top_action ta;
Top_comedy tc;
Top_horror th;
Top_romance tr;
Top_drama td;
Top_thriller tt;
Top_doc to;


void Create_Account(User &user){

    string last_name, first_name, email, password, user_name;
    vector<string> viewed;
    Watchlist<Movie> q;
    cout<<"Create an account:\n";
    cout<<"First name: "; cin>>first_name;
    cout<<"Last name: "; cin>>last_name;
    cout<<"Email: "; cin>>email;
    while(true){
        cout<<"User name: ";
        cin>>user_name;
        if(names.find(user_name) == names.end()) {
                ofstream file;
                file.open("usernames.txt", fstream::app);
                file<<"\n"<<user_name;
                file.close();
                names.insert(user_name);
                break;

        }
        else cout<<"The username already exists! Try another one!\n\n";
    }
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
    filew<<"STOP!\n";
    filew.close();

}

void Disconnect(vector<Client*> c){
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

void Initializare(){
    string dummy, title;
    Movie movie;
    ifstream fin("movies.txt");
    while(fin>>movie){
        //fin>>dummy;
        //cout<<dummy;
        title = movie.get_name();
        transform(title.begin(), title.end(), title.begin(), [](unsigned char c){ return tolower(c);} );
        m.insert({title, movie});
        //m[movie.get_name()].Show_details();
        //movie.Show_details();
        //cout<<"\n";
        fin.ignore();
        getline(fin, dummy);
        //cout<<m[title];

    }
    fin.close();

    ifstream fin2("usernames.txt");
    string s;
    while(fin2>>s){
        names.insert(s);
    }
    fin2.close();

    ifstream fin3("donations.txt");
    int d;
    fin3>>d;
    Premium_User::set_donations(d);
}

void Display_top3_type(string type){
/// functia afiseaza toate filmele din baza de date de un anumit gen
    //for(auto it = m.begin(); it != m.end(); it ++)
        //if(it->second.get_genre() == type) cout<<it->second<<"\n";

    //tc.show_top3();
    transform(type.begin(), type.end(), type.begin(), [](unsigned char c){ return tolower(c);} );
    if(type == "comedy"){
        tc.show_top3();
        return;
    }


    if(type == "horror"){
        th.show_top3();
        return;
    }


    if(type == "drama"){
        td.show_top3();
        return;
    }


    if(type == "thriller"){
        tt.show_top3();
        return;
    }


    if(type == "action"){
        ta.show_top3();
        return;
    }


    if(type == "documentary"){
       to.show_top3();
       return;
    }


    if(type == "romance"){
        tr.show_top3();
        return;
    }

    cout<<"The type you entered does not appear in our database!\n";

}

void Display_most_viewed(){
/// functia afiseaza filmele in ordinea ratingului

    int ct = 1;
    list<Movie> L;
    Movie movie;
    cout<<"Here is the list of movies:\n";
    for(auto it = m.begin(); it != m.end(); it ++)
        L.push_back(it->second);
    L.sort();
    for(auto it = L.begin(); it != L.end(); it ++){
        cout<<ct<<". "<<*it<<"\n";
        ct++;
    }
}

void Search(string movie_name){
    cout<<"\n";
    transform(movie_name.begin(), movie_name.end(), movie_name.begin(), [](unsigned char c){ return tolower(c);} );
    if(m.find(movie_name) == m.end()) cout<<"Sorry! The given movie name does not exist in our database yet.\n";
    else m[movie_name].Show_details();
}

void Donate(Premium_User &p){
    string card;
    int v;
    if(p.get_credit_card() == "no credit card"){
        cout<<"To be able to make a donation you have to register a credit card first!\n";
        cout<<"Enter a valid credit card number: ";
        cin>>card;
        p.set_card(card);
        cout<<"Card registered!\n\n";
    }
    cout<<"Enter the ammount you want to donate (in euros): ";
    cin>>v;
    cout<<"Thank you for your donation! :3\n";
    Premium_User :: set_donations(v);
    ofstream fout("donations.txt");
    fout<<Premium_User::get_donations()<<"\n";
    fout.close();
}

void Tops(){

for(auto it = m.begin(); it != m.end(); it ++){
    ta.update_top3(it->second);
    tc.update_top3(it->second);
    th.update_top3(it->second);
    tr.update_top3(it->second);
    td.update_top3(it->second);
    tt.update_top3(it->second);
    to.update_top3(it->second);
}

}

void User_Actions(User user){
 bool done = 0;
 int ct = 0;
 int key;
 string title;
 Premium_User p;

 while(done == 0)
    {
        cout<<"\n";
        cout<<"------------------------------------------------------\n";
        if(ct == 0) {cout<<"Here is what you can do:\n"; ct++;}
        cout<<"Want to watch a new movie? Press 1 to add it to your watchlist\n";
        cout<<"Already watched one? Mark it in your viewed movie list by pressing 2\n";
        cout<<"Press 3 to see what you have in your watchlist\n";
        cout<<"Press 4 if you want to see which movies you viewed\n";
        cout<<"Find out how much time you have spent watching movies by pressing 5!\n";

        cout<<"\nDon't know what to watch next?\n";
        cout<<"Browse for a movie with 6\n";
        cout<<"Use 7 to see the most viewed movies from our database\n";
        cout<<"Interested in only one genre? Find the top 3 movies of your favourite type by pressing 8\n";
        cout<<"\n";
        cout<<"Feeling generous? You can always help us grow with a donation by pressing 9\n";
        cout<<"To log out, press 0\n";
        cout<<"------------------------------------------------------\n";
        cout<<"\nYour action: ";
        cin>>key;

        switch(key){
            case 1:
                     user.update_watchlist(m);
                     break;

            case 2:
                      cout<<"Enter movie title: ";
                      cin.ignore();
                      getline(cin, title);
                      user.mark_as_viewed(title);
                      break;

            case 3: user.print_watchlist();
                      break;

            case 4: user.print_viewed();
                      break;

            case 5: user.total_time(m);
                      break;

            case 6:
                      cout<<"Enter movie title: ";
                      cin.ignore();
                      getline(cin, title);
                      Search(title);
                      break;

            case 7: Display_most_viewed();
                      break;

            case 8: cout<<"Enter the genre: ";
                      cin>>title;
                      Display_top3_type(title);
                      break;

            case 9: Donate(p);
                      break;

            case 0: cout<<"You have been disconnected!";
                      done = 1;
                      break;

            default: cout<<"Sorry, the entered command does not exist!\n";

        }

    }
}

void Admin_Actions(Admin admin){
    bool done = 0;
    char key;

 while(done == 0)
    {
        cout<<"\n";
        cout<<"------------------------------------------------------\n";

        cout<<"Press 1 to see all the movies in the database\n";
        cout<<"Press 2 to add a new movie\n";
        cout<<"\nPress 3 to see all the registered users\n";
        cout<<"Press 4 to block a user\n";
        cout<<"\nPress 5 to see the donations\n";
        cout<<"To log out, press 0\n";
        cout<<"------------------------------------------------------\n";
        cout<<"\nYour action: ";
        cin>>key;

        switch(key){
            case '1':
                     Display_most_viewed();
                     Initializare();
                     break;

            case '2':
                      admin.Add_movie();
                      break;

            case '3': admin.print_users();
                      break;

            case '4': admin.block_user(names);
                      break;

            case '5': admin.see_donations();
                      break;

            case '0': cout<<"You have been disconnected!";
                      done = 1;
                      break;

            default: cout<<"Sorry, the entered command does not exist!\n";

        }

    }
}



class MeniuInteractiv{
    static MeniuInteractiv *obiect;
    MeniuInteractiv(){}

public:
    static MeniuInteractiv* getInstance(){
        if(!obiect)
            obiect=new MeniuInteractiv();
        return obiect;
    }

    void meniu(){
        bool done = 0, r; /// when done is 1 we exit main
        char key;
        string dummy;
        User user;
        Premium_User p;
        Admin admin;
        Movie n;

        Initializare();
        Tops();

        cout<<"Welcome!";
    while(done == 0)
    {
        cout<<"\n";
        cout<<"------------------------------------------------------\n";
        cout<<"To log into your account press 1 on your keyboard\n";
        cout<<"You don't have an account? Press 2 to register!\n";
        cout<<"\nTo log in as an admin, press 3\n";
        cout<<"To exit the app, press 0\n";
        cout<<"------------------------------------------------------\n";
        cout<<"\nYour action: ";
        cin>>key;

        switch(key){
            case '1': r = user.LogIn();
                      //user.print_viewed();
                      //user.print_watchlist();
                      //user.update_watchlist(m);
                      //user.mark_as_viewed("The movie");
                      //user.print_watchlist();
                      if(r == 1)User_Actions(user);
                      break;

            case '2': Create_Account(user);
                      break;

            case '3': if(admin.LogIn()) {cout<<"You are logged as an admin\n"; Admin_Actions(admin);}
                    else cout<<"You are not an admin!\n";
                    break;

            case '0': done = 1;
                    break;

            default: cout<<"Sorry, the entered command does not exist!\n";

        }

    }

    }
};

MeniuInteractiv* MeniuInteractiv::obiect=0;

int main()
{
    MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
    //Display_type('C');
    //Display_most_viewed();
    //Search("Last movie");
    //Search("Doctor Strange");
    /*vector<Client*> c;

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
    return 0;*/
    return 0;
}
