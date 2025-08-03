#include "Person.h"

Person::Person(const std::string& id, const std::string& name, const std::string& email)
    : ID(id), name(name), email(email) {}

std::string Person::getID() const { return ID; }
std::string Person::getName() const { return name; }
std::string Person::getEmail() const { return email; }
Time& Person::getSchedule() { return schedule; }

void Person::setID(const std::string& id) { ID = id; }
void Person::setName(const std::string& name) { this->name = name; }
void Person::setEmail(const std::string& email) { this->email = email; }
void Person::setSchedule(const Time& time) { schedule = time; }
