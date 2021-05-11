#ifndef TOP3_H_INCLUDED
#define TOP3_H_INCLUDED

class Top3{

public: /// trebuie sa l intreb pe profu
Movie t1, t2, t3;

public:
Top3(){};
Top3(const Top3 &T){
    this->t1 = T.t1;
    this->t2 = T.t2;
    this->t3 = T.t3;
}
virtual void find_top3(Watchlist<Movie> v) = 0;
virtual void show_top3() {
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best comedy movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
virtual void update_top3(Movie m) = 0;
};

class Top_comedy : public Top3{

public:
    Top_comedy(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_comedy(const Top_comedy &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    void update_top3(Movie m){
        if(m.get_genre() == 'C'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }
    virtual void find_top3(Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'C'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    virtual void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best comedy movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_horror : public Top3{

public:
    Top_horror(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_horror(const Top_horror &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    virtual void update_top3(Movie m){
        if(m.get_genre() == 'H'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }
    void find_top3(Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'H'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best horror movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_action : public Top3{

public:
    Top_action(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_action(const Top_action &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    virtual void update_top3(Movie m){
        if(m.get_genre() == 'A'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }

    void find_top3( Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'A'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best action movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_romance : public Top3{

public:
    Top_romance(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_romance(const Top_romance &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    virtual void update_top3(Movie m){
        if(m.get_genre() == 'R'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }

    void find_top3( Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'R'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best romance movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_doc : public Top3{

public:
    Top_doc(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_doc(const Top_doc &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    void update_top3(Movie m){
        if(m.get_genre() == 'O'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }
    virtual void find_top3(Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'O'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    virtual void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best documentaries out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_drama : public Top3{

public:
    Top_drama(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_drama(const Top_drama &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    void update_top3(Movie m){
        if(m.get_genre() == 'D'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }
    virtual void find_top3(Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'D'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    virtual void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best drama movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_thriller : public Top3{

public:
    Top_thriller(){
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);
    }

     Top_thriller(const Top_thriller &t){
        this->t1 = t.t1;
        this->t2 = t.t2;
        this->t3 = t.t3;
    }
    void update_top3(Movie m){
        if(m.get_genre() == 'T'){
                if(m.get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = m;
                }
                else if(m.get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = m;
                }
                else if(m.get_rating() >= t3.get_rating())
                    t3 = m;
            }

    }
    virtual void find_top3(Watchlist<Movie> v){ /// sa ma uit daca trebuie pus virtual
        t1.set_rating(-1);
        t2.set_rating(-1);
        t3.set_rating(-1);

        for(int i = 0; i <= v.get_size(); i ++)
            if(v[i].get_genre() == 'T'){
                if(v[i].get_rating() >= t1.get_rating()){
                    t3 = t2;
                    t2 = t1;
                    t1 = v[i];
                }
                else if(v[i].get_rating() >= t2.get_rating()){
                    t3 = t2;
                    t2 = v[i];
                }
                else if(v[i].get_rating() >= t3.get_rating())
                    t3 = v[i];
            }
    }

    virtual void show_top3(){
        /// daca avem mai putine filme -> afisam doar cate avem
        cout<<"The best thriller movies out now are:\n";
        if(t1.get_rating() != -1 && t1.get_name() != "Unknown name")
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1 && t2.get_name() != "Unknown name")
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1 && t3.get_name() != "Unknown name")
            cout<<"3. "<<t3<<"\n";
    }
};
#endif // TOP3_H_INCLUDED
