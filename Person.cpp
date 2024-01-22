#include "Person.h"

Person::Person(const string &name, const string &address, const string &email) : name(name), address(address),
                                                                                 email(email) {}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &_name) {
    this->name = _name;
}

const string &Person::getAddress() const {
    return address;
}

void Person::setAddress(const string &_address) {
    this->address = _address;
}

const string &Person::getEmail() const {
    return email;
}

void Person::setEmail(const string &_email) {
    this->email = _email;
}


