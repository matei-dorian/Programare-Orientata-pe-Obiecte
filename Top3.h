#ifndef TOP3_H_INCLUDED
#define TOP3_H_INCLUDED

class Top3{

protected: /// trebuie sa l intreb pe profu
Movie t1, t2, t3;

public:
virtual void find_top3( Watchlist<Movie> v) = 0;
virtual void show_top3() = 0;
};

class Top_comedy : public Top3{

public:
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
        if(t1.get_rating() != -1)
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1)
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1)
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_horror : public Top3{

public:
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
        if(t1.get_rating() != -1)
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1)
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1)
            cout<<"3. "<<t3<<"\n";
    }
};

class Top_action : public Top3{

public:
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
        if(t1.get_rating() != -1)
            cout<<"1. "<<t1<<"\n";
        if(t2.get_rating() != -1)
            cout<<"2. "<<t2<<"\n";
        if(t3.get_rating() != -1)
            cout<<"3. "<<t3<<"\n";
    }
};
#endif // TOP3_H_INCLUDED
