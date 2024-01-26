//
// Created by iamna on 26/01/2024.
//

#ifndef CPP_LABS_COMPOSITION_H
#define CPP_LABS_COMPOSITION_H

#include <iostream>
#include <cstring>

class Person {
    public:
        Person(const char *name0="", int age0=0);
        void print();
    private:
        char name[30];
        int age;
};

#endif //CPP_LABS_COMPOSITION_H
