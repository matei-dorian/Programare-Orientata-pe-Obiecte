#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include <string>

using namespace std;

const int Max_Users = 1000;
const int Max_Platforms = 6;
const int Max_Cast = 100;
const int Max_Reviews = 50;

class Movie{

    static int n;  /// numarul total de filme inregistrate
    static int *f; /// vector de frecventa pentru id-uri

    string name; /// numele filmului
    int movie_id; /// fiecare film va avea un id unic
    int year;  /// anul de aparitie al filmului
    string director; /// numele regizorului
    char genre;  /// tipul filmului -> codificat printr-o litera
    long long time;  /// timpul in secunde
    float budget;  /// bugetul filmului
    //string description; /// descrierea filmului

    int n_cast;  /// numar actori
    string *cast;  /// nume actori

    //int n_reviews;  /// numar review-uri
    //string *reviews;

    int n_platforms;  /// numarul de site-uri
    char *platforms;  /// numele site-urilor pe care poate fi vizionat -> co/dificare printr-o litera

    int n_marks; /// numarul de note
    float *marks; /// notele acordate de utilizatori
    double rating;  /// ratingul calculat ca media aritmetica a notelor
    bool popular;  /// filmul este popular daca ratingul e >= 9
    long views;
    /// map cu toate filmele
public:
    ///Constructor
    Movie();
    Movie(string name);
    Movie(int year, string name, string director, char genre, float budget, long long time);
    Movie(int year, string name, string director, char genre, float budget, long long time, int n_cast, string *cast, int n_platforms, char *platforms);
    Movie(const Movie &m);

    ///Destructor
    virtual ~Movie();

    ///Getteri
    static int get_n() {return n; }
    string get_name() {return name; }
    int get_year() {return year; }
    int get_movie_id() {return movie_id; }
    string get_director() {return director; }
    char get_genre() {return genre; }
    long long get_time() {return time; }
    float get_budget() {return budget; }
    //string get_description() {return description; }
    int get_n_cast() {return n_cast; }
    string* get_cast() {return cast; } /// sa am grija cum se comporta asta
    //int get_n_reviews() {return n_reviews; }
    //string* get_reviews() {return reviews; }
    int get_n_platforms() {return n_platforms; }
    char* get_platforms() {return platforms; }
    int get_n_marks() {return n_marks; }
    float* get_marks() {return marks; }
    double get_rating() {return rating; }
    bool get_popular() {return popular; }
    long get_views() {return views; }

    ///Setteri
    void set_name(string new_name) {this->name = new_name; }
    void set_genre(char new_genre) {this->genre = new_genre; }
    void set_time(long long new_time) {this->time = new_time; }
    void set_year(int new_year) {this->year = new_year; }
    void set_budget(float new_budget) {this->budget = new_budget; }
    //void set_description(string new_description) {this->description = new_description; }
    void set_n_cast(int new_n_cast) {this->n_cast = new_n_cast; }
    void set_cast(string *new_cast, int length);
    void set_n_platforms(int new_n_platforms) {this->n_platforms = new_n_platforms; }
    void set_platforms(char *new_platforms, int length);
    void set_rating(double new_rating) {this->rating = rating; }
    void set_popular(bool new_popular) {this->popular = new_popular; }
    void set_views(bool new_views) {this->views = new_views; }

    ///Operatori
    ///=
    Movie& operator= (const Movie &m);

    ///<<
    friend std::ostream& operator<< (std::ostream &out, const Movie &m);

    ///>>
    friend std::istream& operator>> (std::istream &in, Movie &w);

    /// []
    float& operator[] (int index);

    /// ++
    Movie& operator++ ();  /// forma postfix
    Movie operator++ (int); /// forma postfix

    /// +
    Movie operator+(const int v);
    friend Movie operator+(const int v, Movie m);

    /// *
    Movie operator*(const int v);
    friend Movie operator*(const int v, Movie m);

    /// cast
    explicit operator double() const {return (double)rating; }
    operator int() const {return movie_id; }
    operator long() const {return views; }

    /// >, >=
    friend bool operator> (const Movie &m1, const Movie &m2);
    friend bool operator>= (const Movie &m1, const Movie &m2);

    /// ==
    friend bool operator== (const Movie &m1, const Movie &m2); /// https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/

    ///Metode
    void Show_details();
};

int Movie :: n;
int *Movie :: f;

Movie :: Movie(){  /// constructor fara parametrii
    n++;  /// marim numarul de filme inregistrate
    if(f == NULL){
        f = new int[Max_Users];
        for(int i=0;i<Max_Users;i++)
            f[i] = 0;
    }

    movie_id = 0;
    while(f[movie_id] !=0)
        movie_id++;
    f[movie_id] = 1;

    name = "Unknown name";
    director = "Unknown director";
    genre = '?';
    budget = 0;
    time = 0;
    year = -1;
    //description = "No description available";

    cast = new string[Max_Cast]{"No cast"}; /// alocam memorie si initializam cu "No cast"
    n_cast = 0;

    platforms = new char[Max_Platforms]{'?'};
    n_platforms = 0;  /// The movie is unavailable

    marks = new float[Max_Users]{0.0};
    n_marks = 0;

    //reviews = new string[Max_Reviews]{"No reviews"};
    //n_reviews = 0;

    rating = 0;  /// The movie has no rating yet
    popular = 0;  /// filmul nu are rating -> nu e popular
    views = 0;
}

Movie :: Movie(string name){
    n++;  /// marim numarul de filme inregistrate
    if(f == NULL){
        f = new int[Max_Users];
        for(int i=0;i<Max_Users;i++)
            f[i] = 0;
    }

    movie_id = 0;
    while(f[movie_id] !=0)
        movie_id++;
    f[movie_id] = 1;

    name = name;
    director = "Unknown director";
    genre = '?';
    budget = 0;
    time = 0;
    year = -1;
    //description = "No description available";

    cast = new string[Max_Cast]{"No cast"}; /// alocam memorie si initializam cu "No cast"
    n_cast = 0;

    platforms = new char[Max_Platforms]{'?'};
    n_platforms = 0;  /// The movie is unavailable

    marks = new float[Max_Users]{0.0};
    n_marks = 0;

    //reviews = new string[Max_Reviews]{"No reviews"};
    //n_reviews = 0;

    rating = 0;  /// The movie has no rating yet
    popular = 0;  /// filmul nu are rating -> nu e popular
    views = 0;
}


Movie :: Movie (int year, string name, string director, char genre, float budget, long long time){ /// constructor cu parametrii
    n++;  /// marim numarul de filme inregistrate
    if(f == NULL){
        f = new int[Max_Users];
        for(int i=0;i<Max_Users;i++)
            f[i] = 0;
    }

    movie_id = 0;
    while(f[movie_id] !=0)
        movie_id++;
    f[movie_id] = 1;

    /* date introduse de admin */
    this->name = name;
    this->year = year;
    this->director = director;
    this->genre = genre;
    this->budget = budget;
    this->time = time;
    //this->description = description;
    /* date introduse de admin */

    cast = new string[Max_Cast]{"No cast"};
    n_cast = 0;  /// cast-ul va fi introdus cu setterul

    /* daca se apeleaza acest constructor atunci filmu e disponibil pe toate platformele */
    n_platforms = Max_Platforms;
    platforms = new char[Max_Platforms]{'H', 'N', 'D', 'Y', 'A', 'P'}; /// H - HBO, N - Netflix , D - Disney+, Y - Youtube, A - AppleTV, P - PrimeVideo

    /* urmatoarele campuri vor fi goale deoarece valorile vor fi modificate de catre utilizatori si critici */
    marks = new float[Max_Users];
    n_marks = 0;

    //reviews = new string[Max_Reviews];
    //n_reviews = 0;

    rating = 0;  /// The movie has no rating yet
    popular = 0;  /// filmul nu are rating -> nu e popular
    views = 0;


}

Movie :: Movie (int year, string name, string director, char genre, float budget, long long time, int n_cast, string *cast, int n_platforms, char *platforms){ /// constructor cu parametrii
    n++;  /// marim numarul de filme inregistrate
    if(f == NULL){
        f = new int[Max_Users];
        for(int i=0;i<Max_Users;i++)
            f[i] = 0;
    }

    movie_id = 0;
    while(f[movie_id] !=0)
        movie_id++;
    f[movie_id] = 1;

    /* date introduse de admin */
    this->name = name;
    this->year = year;
    this->director = director;
    this->genre = genre;
    this->budget = budget;
    this->time = time;
    //this->description = description;

    this->n_cast = n_cast;
    //cast = new string[Max_Cast];
    this->cast = cast;

    //platforms = new char[Max_Platforms];
    this->platforms = platforms;
    this->n_platforms = n_platforms;
    /* date introduse de admin */

    /* urmatoarele campuri vor fi goale deoarece valorile vor fi modificate de catre utilizatori si critici */
    marks = new float[Max_Users];
    n_marks = 0;

    //reviews = new string[Max_Reviews];
    //n_reviews = 0;

    rating = 0;  /// The movie has no rating yet
    popular = 0;  /// filmul nu are rating -> nu e popular
    views = 0;


}

Movie :: Movie(const Movie &m){ /// constructor de copiere
    /// numarul de filme nu se modifica
    this->movie_id = m.movie_id;
    this->name = m.name;
    this->year = m.year;
    this->director = m.director;
    this->genre = m.genre;
    this->budget = m.budget;
    this->time = m.time;
    //this->description = m.description;

    this->n_cast = m.n_cast;
    this->cast = new string[Max_Cast];
    for(int i=0;i<this->n_cast;i++)
        this->cast[i] = m.cast[i];

    this->n_platforms = m.n_platforms;
    platforms = new char[Max_Platforms];
    for(int i=0;i<this->n_platforms;i++)
        this->platforms[i] = m.platforms[i];

    this->n_marks = m.n_marks;
    this->marks = new float[Max_Users];
    for(int i=0;i<this->n_marks;i++)
        this->marks[i] = m.marks[i];

    //this->n_reviews = m.n_reviews;
    //this->reviews = new string[Max_Reviews];
    //for(int i=0;i<this->n_reviews;i++)
     //   this->reviews[i] = m.reviews[i];

    this-> rating = m.rating;
    this->popular = m.popular;
    this->views = m.views;
}

Movie :: ~Movie(){
    n--; /// filmul a fost sters deci numarul de filme scade
    f[movie_id] = 0; /// eliberam id-ul

    /// eliberam memoria alocata dinamic

    if(cast != NULL)
    delete [] cast;

    if(platforms != NULL)
    delete [] platforms;

    if(marks != NULL)
    delete [] marks;
    //delete [] reviews;

}

void Movie :: set_cast(string *new_cast, int length){
    if(length <= 0) {cout<<"Wrong list!"; exit(0);}

    set_n_cast(length);
    if(cast != NULL) delete [] cast;

    cast = new string [length];
    for(int i = 0; i < length; i++)
        cast[i] = new_cast[i];

}

void Movie :: set_platforms(char *new_platforms, int length){
    if(length <= 0) {cout<<"Wrong list!"; exit(0);}

    set_n_platforms(length);
    if(platforms != NULL) delete [] platforms;

    platforms = new char [length];
    for(int i = 0; i < length; i++)
        platforms[i] = new_platforms[i];
}

void Movie :: Show_details(){
    cout<<"Name of the movie: "<<this->name<<"\n";
    cout<<"The movie was made in: "<<this->year<<" by "<<this->director<<"\n";
    cout<<this->name<<" is ";
    switch(this->genre){
        case 'H': cout<<"a horror movie ";
                  break;
        case 'R': cout<<"a romantic movie ";
                  break;
        case 'A': cout<<"an action movie ";
                  break;
        case 'T': cout<<"a thriller ";
                  break;
        case 'D': cout<<"a drama ";
                  break;
        case 'O': cout<<"a documentary ";
                  break;
        case 'C': cout<<"a comedy ";
                  break;
        default: cout<<" of unknown genre ";
    }
    cout<<"and has a total runtime of "<<this->time/3600<<" hours and "<<this->time%3600/60<<" minutes.\n";
    cout<<"The estimated budget is: "<<this->budget<<"\n";
    cout<<"You can watch this movie on: ";

    for(int i=0;i<this->n_platforms;i++){
        if(this->platforms[i] == 'N') cout<<"Netflix";
        if(this->platforms[i] == 'H') cout<<"HBO";
        if(this->platforms[i] == 'D') cout<<"Disney+";
        if(this->platforms[i] == 'Y') cout<<"Youtube";
        if(this->platforms[i] == 'A') cout<<"AppleTV";
        if(this->platforms[i] == 'P') cout<<"PrimeVideo";
        if(i<this->n_platforms - 1) cout<<", ";
        else cout<<".\n";
        }

    cout<<"The cast is composed by: ";
    for(int i=0;i<this->n_cast;i++){
        cout<<this->cast[i];
        if(i<this->n_cast - 1) cout<<", ";
        else cout<<".\n";
    }

    cout<<this->name<<" was reviewed by "<<this->n_marks<<" users and has a rating of "<<this->rating<<" out of 10.\n";

}

Movie& Movie :: operator = (const Movie &m){  /// are sens sa fie folosit doar daca obiectul care face apelul a fost initializat cu Movie m(y);
    if(this != &m){
        this->budget = m.budget;
        this->genre = m.genre;
        this->name = m.name;
        this->year = m.year;
        this->movie_id = m.movie_id;
        this->director = m.director;
        this->time = m.time;
        this->views = m.views;
        this->popular = m.popular;
        this->n_cast = m.n_cast;
        this->n_marks = m.n_marks;
        this->n_platforms = m.n_platforms;
        this->rating = m.rating;

        for(int i=0;i<m.n_cast;i++)
            cast[i] = m.cast[i];
        for(int i=0;i<m.n_platforms;i++)
            cast[i] = m.platforms[i];
        for(int i=0;i<m.n_marks;i++)
            cast[i] = m.marks[i];
    }
    return *this;
}

std::ostream& operator<< (std::ostream &out, const Movie &m){
    out<<m.name;
    return out;

}

std::istream& operator>> (std::istream &in, Movie &w){

    getline(in, w.name);

    in>>w.movie_id;
    in>>w.year;
    in.ignore();
    getline(in, w.director);
    in>>w.genre;
    in>>w.time;
    in>>w.budget;
    in>>w.n_cast;
    in.ignore();

    if(w.cast != NULL) delete [] w.cast;
    w.cast = new string [w.n_cast];
    for(int i=1;i<=w.n_cast;i++)
        getline(in, w.cast[i - 1]);

    in>>w.n_platforms;
    if(w.platforms != NULL) delete [] w.platforms;
    w.platforms = new char [w.n_platforms];
    for(int i=1;i<=w.n_platforms;i++)
        in>>w.platforms[i - 1];

    in>>w.n_marks;
    if(w.marks != NULL) delete [] w.marks;
    w.marks = new float [w.n_marks];
    for(int i=1;i<=w.n_marks;i++)
        in>>w.marks[i - 1];
    in>>w.rating;
    in>>w.popular;
    in>>w.views;
    return in;
}

float& Movie :: operator[] (int index){
    if(0 <= index && index < this->n_marks)
        return this->marks[index];
    else {cout<<"Index gresit"; exit(0);}

}

Movie& Movie :: operator++(){
    ++views;
    return *this;
}

Movie Movie :: operator++(int){
    Movie temp(*this);
   ++(*this);
   return temp;


}

Movie Movie :: operator+(const int v){
    Movie temp(*this);
    temp.views = temp.views + v;
    return temp;
}

Movie operator+(const int v, Movie m){
      m.views = m.views + v;
        return m;
}

Movie Movie :: operator*(const int v){
    Movie temp(*this);
    temp.views = temp.views * v;
    return temp;
}

Movie operator*(const int v, Movie m){
      m.views = m.views * v;
        return m;
}

bool operator> (const Movie &m1, const Movie &m2){
    return m1.views > m2.views;
}

bool operator>= (const Movie &m1, const Movie &m2){
    return m1.views >= m2.views;

}

bool operator== (const Movie &m1, const Movie &m2){
    return m1.name == m2.name;
}

class Awarded_Movie : public Movie{
    string award;

public:

    ///Constructori
    Awarded_Movie() : Movie() {this->award = "no awards";}
    Awarded_Movie(int year, string name, string director, char genre, float budget, long long time, int n_cast, string *cast, int n_platforms, char *platforms) :Movie(year, name, director, genre, budget, time, n_cast, cast, n_platforms, platforms)
                  {this->award = "no awards";}
    Awarded_Movie(const Awarded_Movie &m): Movie(m){this->award = m.award;}

    ///Destructor
    ~Awarded_Movie() {} /// se apeleaza doar destructorul lui Movie

    ///Operatori
    Awarded_Movie& operator=(const Awarded_Movie& m){
        if(this != &m){
            Movie::operator=(m);
            this->award=m.award;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Awarded_Movie& m){
        out<<(Movie&)m;  /// Afisarea va fi aceeasi si pentru filmele care au un premiu
        return out;
    }

    friend istream& operator>>(istream& in, Awarded_Movie& m){
        in>>(Movie&)m;
        in>>m.award;
        return in;
    }

    ///Metode
    void give_award(string award);
    void show_award();
};

void Awarded_Movie :: give_award(string award){

    /// daca un film are un premiu -> rating-ul creste cu 0.5 pana la maximul de 10
    if(this -> award == "no awards") this->set_rating(min(this->get_rating() + 0.5, 10.00));
    this->award = award;
    cout<<"The award was successfully assigned to the movie "<<*this<<"\n";
}

void Awarded_Movie :: show_award(){

    if(this->award == "no awards") cout<<"The movie "<<*this<<" did not earn any awards\n";
    else cout<<"The movie "<<*this<<" earned the "<<this->award<<" award\n";
}
#endif // MOVIE_H_INCLUDED
