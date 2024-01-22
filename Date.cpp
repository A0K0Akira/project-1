#include "Date.h"

Date::Date() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    year = now->tm_year + 1900; // tm_year is years since 1900
    month = now->tm_mon + 1;    // tm_mon is months since January (0-11)
    day = now->tm_mday;
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}


int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getDifference(const Date &dateObj) const {
    // Convert current Date object to time_t
    std::tm this_tm = {};
    this_tm.tm_year = year - 1900;
    this_tm.tm_mon = month - 1;
    this_tm.tm_mday = day;
    this_tm.tm_hour = 0; // Set hours, minutes, and seconds to zero for accurate difference calculation
    this_tm.tm_min = 0;
    this_tm.tm_sec = 0;
    time_t this_time_t = std::mktime(&this_tm);

    // Convert parameter Date object to time_t
    std::tm dateObj_tm = {};
    dateObj_tm.tm_year = dateObj.getYear() - 1900;
    dateObj_tm.tm_mon = dateObj.getMonth() - 1;
    dateObj_tm.tm_mday = dateObj.getDay();
    dateObj_tm.tm_hour = 0;
    dateObj_tm.tm_min = 0;
    dateObj_tm.tm_sec = 0;
    time_t dateObj_time_t = std::mktime(&dateObj_tm);

    // Calculate the difference in seconds, and then convert it to days
    const int secondsPerDay = 60 * 60 * 24;
    double difference = std::difftime(this_time_t, dateObj_time_t);
    int differenceInDays = static_cast<int>(difference / secondsPerDay);
    return differenceInDays;
}

void Date::addDays(int numOfDays) {
    // Convert current Date object to time_t
    std::tm this_tm = {};
    this_tm.tm_year = year - 1900;  // tm_year is the year since 1900
    this_tm.tm_mon = month - 1;     // tm_mon is months since January (0-11)
    this_tm.tm_mday = day;
    this_tm.tm_hour = 0;            // Set hours, minutes, and seconds to zero
    this_tm.tm_min = 0;
    this_tm.tm_sec = 0;
    time_t this_time_t = std::mktime(&this_tm);

    // Add the number of days in seconds to the time_t value
    const int secondsPerDay = 60 * 60 * 24;
    this_time_t += numOfDays * secondsPerDay;

    // Convert the time_t value back to a tm struct
    std::tm* new_tm = std::localtime(&this_time_t);

    // Update the Date object with the new date
    year = new_tm->tm_year + 1900;
    month = new_tm->tm_mon + 1;
    day = new_tm->tm_mday;
}

