#include "user.h"

user::user() {}

user::user(string email, string username, string password, string role)
    : email(email), username(username), password(password), role(role) {}

bool user::login(string uname, string pass){
    return (uname == username && pass == password);
}

string user::getRole() {
    return role;
}

string user::getUsername() {
    return username;
}

void user::setData(string email, string username, string password, string role) {
    this->email = email;
    this->username = username;
    this->password = password;
    this->role = role;
}