#include "Composition.h"

int main (void) {
    Person *p1;
    Person *p2;
    Person *p3;
    p1 = new Person; //def con. called
    p2 = new Person("Matti");
    p3 = new Person("Matti", 20);
    p1->print();
    delete p1;
    delete p2;
    delete p3;
    return 0;
}