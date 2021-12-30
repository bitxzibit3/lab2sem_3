//
// Created by Timur on 18.12.2021.
//

#ifndef LAB2_PERSON_H
#define LAB2_PERSON_H

#include <string>

class Profession
{
private:
    std::string prof;
public:
    Profession(std::string);
    std::string GetProf ();
};
class Person
{
private:
    std::string name, surname;
    int age;
    profession prof;
public:
    std::string GetName ();
    std::string GetSurname ();
    int GetAge ();
    profession GetProf();
};

#endif //LAB2_PERSON_H
