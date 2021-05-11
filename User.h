#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "Client.h"
#include <cstring>
using namespace std;
extern set<string> names;

class User : public Client{
    string first_name, last_name, user_name, email, password;
    vector<string> viewed;  /// filmele vazute
    Watchlist<Movie> q;  /// filmele pe care vreau sa le vad

public:
    ///Constructor
    User();
    User(string first_name, string last_name, string user_name, string email, string password);
    User(string first_name, string last_name, string user_name, string email, string password, vector<string> viewed, Watchlist<Movie> q);
    User(const User &u);

    ///Destructor
    virtual ~User();

    ///Getteri
    string get_first_name(){ return first_name;}
    string get_last_name(){ return last_name;}
    string get_user_name(){ return user_name;}
    string get_email(){ return email;}
    string get_password(){ return password;}

    ///Setteri
    void set_first_name(string new_name){ this->first_name = new_name;}
    void set_last_name(string new_name){ this->last_name = new_name;}
    void set_user_name(string new_name){ this->user_name = new_name;}
    void set_email(string email){ this->email = email;}
    void set_password(string password){ this->password = password;}

    ///Metode
    void print_viewed();
    void print_watchlist();
    bool LogIn();
    void show_type(){cout<<"One user";}
    void update_watchlist(map<string, Movie> m);
    void mark_as_viewed(string title);
    void total_time(map<string, Movie> m);

    ///Operatori
    /// =
    User& operator = (const User &user);

    ///<<
    friend std::ostream& operator<< (std::ostream &out, const User &user);

    ///>>
     friend std::istream& operator>> (std::istream &in, User &user);

};

User :: User(){

    first_name = "Unknown";
    last_name = "Unknown";
    email = "Unknown";
    user_name = "Anonymus";
    password = "";
}

User :: User(string first_name, string last_name, string user_name, string email, string password, vector<string> viewed, Watchlist<Movie> q){

    this->first_name = first_name;
    this->last_name = last_name;
    this->email = email;
    this->user_name = user_name;
    this->password = password;
    this->viewed = viewed;
    this->q = q;
}

User :: User(string first_name, string last_name, string user_name, string email, string password){

    this->first_name = first_name;
    this->last_name = last_name;
    this->email = email;
    this->user_name = user_name;
    this->password = password;
}

User :: User(const User &u){

    this->first_name = u.first_name;
    this->last_name = u.last_name;
    this->email = u.email;
    this->user_name = u.user_name;
    this->password = u.password;
    this->viewed = u.viewed;
    this->q = u.q;
}

User :: ~User(){
    //cout<<"User killed";
}

void User :: print_viewed(){ /// afiseaza lista de filme vazute de utilizator
    cout<<"This is the list of movies you saw:\n";
    for(int i=0;i<viewed.size();i++)
        cout<<i+1<<". "<<viewed[i]<<"\n";
    return;
}

void User :: print_watchlist(){
    cout<<q;
    return;
}

User& User :: operator = (const User &user){
    if(this != &user){
        this->first_name = user.first_name;
        this->last_name = user.last_name;
        this->user_name = user.user_name;
        this->password = user.password;
        this->email = user.email;
        this->viewed = user.viewed;
        this->q = user.q;
    }
    return *this;

}

std :: ostream& operator<< (std::ostream &out, const User &user){
    out<<"You are logged in as: "<<user.user_name<<"\n";
    out<<"You have watched a total of: "<<user.viewed.size()<<" movies.\n";
    out<<user.q<<"\n";
    return out;
}

std::istream& operator>> (std::istream &in, User &user){
    in>>user.user_name;
    in>>user.password;
    in>>user.first_name;
    in>>user.last_name;
    in>>user.email;
    return in;
}

bool IsLoggedIn(User &user){
    string username, password, un, pw, fn, ln, e, mv, wl, stop = "STOP!";
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
            password.pop_back();
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

    if(names.find(username) != names.end()){
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
    while(true){
            getline(readw, wl);
            //cout<<wl<<"!\n";
            if(wl == stop) break;
            Movie m(wl);  /// construim un film cu numele wl
            //cout<<m<<"!\n";
            q.push(m);    /// il adaugam la watchlist

    }
    readw.close();

    if(un == username && pw == password)
        {
            User temp(fn, ln, un, e, pw, viewed, q);
            user = temp;
            return true;
        }
    }
    return false;
}


bool User :: LogIn(){
    bool status = IsLoggedIn(*this);

    if(!status){
        cout<<"Login failed: Invalid username or password\n";
        return 0;
    }

    else{

        cout<<"Welcome back "<<this->get_user_name()<<"!\n";
        return 1;
    }

}


void User :: update_watchlist(map<string, Movie> m){
    int nr;
    string name;

    cout<<"Number of movies you want to add: ";
    cin>>nr;
    cin.ignore();
    cout<<"What movies do you want to see next?\n";
    for(int i = 1; i <= nr; i ++){
        cout<<"Type movie name: ";
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), [](unsigned char c){ return tolower(c);} );
        auto it = m.find(name);
        if(it != m.end()) this->q.push(it->second);
        else cout<<"This movie is unavailable.\n";
    }
    ///rescriem watchlistu in fisier!!!!!!!!!!!!!
    //cout<<q.get_size();
    ofstream fout("data\\" + user_name + "W.txt");
    for(int i = 0; i < q.get_size(); i ++)
        fout<<q[i]<<"\n";
    fout<<"STOP!\n";
    fout.close();
    cout<<"Your watchlist was updated successfully!\n";

}

void User :: mark_as_viewed(string title){
    string s;
    int i;
    viewed.push_back(title);
    transform(title.begin(), title.end(), title.begin(), [](unsigned char c){ return tolower(c);} );
    for(i = 0; i < q.get_size(); i ++){
        s = q[i].get_name();
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c);} );
        if(title == s) q.delete_element(i);
    }
    ofstream fout("data\\" + user_name + "W.txt");
    for(int i = 0; i < q.get_size(); i ++)
        fout<<q[i]<<"\n";
    fout<<"STOP!\n";
    fout.close();

    ofstream file("data\\" + user_name + ".txt");
    file << user_name << endl;
    file << password << endl;
    file << first_name << endl;
    file << last_name << endl;
    file << email << endl;
    for(int i=0;i<viewed.size();i++)
        file << viewed[i] << endl;
    file.close();
    cout<<"Movie marked successfully!\n";
}

void User :: total_time(map<string, Movie> m){
    long long t = 0;
    string s;
    for(int i = 0; i < viewed.size(); i ++){
        s = viewed[i];
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c);} );
        if(m.count(s) != 0) t = t + m[s].get_time()/3600;
    }
    if(t <= 100)
        cout<<"Congratulations! You have watched a total of "<<t<<" hours of movies.\n";
    else
        cout<<"Congratulations! You have watched a total of "<<t/24<<" days and "<<t%24<<" hours of movies.\n";
}

class Premium_User : public User{

string credit_card;
static int donations; /// aceasta variabila va aduna donatiile de la toti utilizatorii

public:
    ///Constructori
    Premium_User() : User(){credit_card = "no credit card";}
    Premium_User(string first_name, string last_name, string user_name, string email, string password, vector<string> viewed, Watchlist<Movie> q, string credit_card = "no credit card"):User(first_name, last_name, user_name,email, password, viewed, q)
                {this->credit_card = credit_card;}
    Premium_User(const Premium_User &u) : User(u){this->credit_card = u.credit_card;}

    ///Destructor
    ~Premium_User() {}

    ///Operatori
    Premium_User& operator = (const Premium_User &user){

        if(this != &user){
            User::operator=(user);
            this->credit_card = user.credit_card;
        }
        return *this;
    }

    friend std::ostream& operator<< (std::ostream &out, const Premium_User &user){
        out<<(User&)user;
        out<<"Total donations:"<<user.donations;
        return out;
    }

    friend std::istream& operator>> (std::istream &in, Premium_User &user){
        in>>(User&)user;
        in>>user.credit_card;
        return in;
    }

    /// Setter
    void set_card(string credit_card){this->credit_card = credit_card;}
    static void set_donations(int v) {donations += v;}

    /// Getter
    static int get_donations(){return donations;}
    string get_credit_card() {return credit_card;}

    /// Metode
    void Donate(int x){
        if(credit_card == "no card") {cout<<"Sorry, you must register your credit card first!\n"; return;}
        donations += x;
        cout<<"Thank you for your donation! :>\n";
    }

};

int Premium_User :: donations = 0;

#endif // USER_H_INCLUDED
