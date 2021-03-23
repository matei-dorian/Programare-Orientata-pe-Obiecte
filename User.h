#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

using namespace std;

class User{
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
    ~User();

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
    this->first_name = user.first_name;
    this->last_name = user.last_name;
    this->user_name = user.user_name;
    this->password = user.password;
    this->email = user.email;
    this->viewed = user.viewed;
    this->q = user.q;
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


#endif // USER_H_INCLUDED
