#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class user {
    private:
        string email;
        string username;
        string password;
        string role; // "master" atau "player"
    public:
        user();
        user(string email, string username, string password, string role);

        bool login(string uname, string pass);
        string getRole();
        string getUsername();

        // registration manual (dummy)
        void setData(string email, string username, string password, string role);
};

#endif
