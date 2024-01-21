#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H

#include <ctime>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date();

    Date(int year, int month, int day);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    int getDifference(const Date &dateObj) const;

    void addDays(int numOfDays);
};


#endif //LIBRARY_DATE_H
