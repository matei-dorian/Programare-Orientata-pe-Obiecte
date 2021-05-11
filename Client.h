#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

class Client{

public:
    virtual bool LogIn() {cout<<"You can not log in from here!"; return 0;}
    virtual void show_type() {cout<<"Undefined type";}
    virtual ~Client() {};
};

#endif // CLIENT_H_INCLUDED
