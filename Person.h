#ifndef LIBRARY_PERSON_H
#define LIBRARY_PERSON_H

#include <string>

using namespace std;
class Person {
private:
    string name;
    string address;
    string email;

public:
    Person(const string &name, const string &address, const string &email);

    const string &getName() const;

    void setName(const string &_name);

    const string &getAddress() const;

    void setAddress(const string &_address);

    const string &getEmail() const;

    void setEmail(const string &_email);
};


#endif //LIBRARY_PERSON_H
