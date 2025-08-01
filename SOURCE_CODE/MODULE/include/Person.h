#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Time.h"
#include "Person.h"

class Person {
protected:
    std::string ID;
    std::string name;
    std::string email;
    Time schedule;

public:
    Person() = default;
    Person(const std::string& id, const std::string& name, const std::string& email);

    // Getters
    std::string getID() const;
    std::string getName() const;
    std::string getEmail() const;
    Time& getSchedule();

    // Setters
    void setID(const std::string& id);
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setSchedule(const Time& time);
};

#endif // PERSON_H
