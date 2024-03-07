//
// Created by iamna on 06/03/2024.
//

#ifndef LAB12_OBSERVER_H
#define LAB12_OBSERVER_H


// Observer.h
class Observer {
public:
    virtual ~Observer() = default;
    virtual void notify(int value) = 0;
};
#endif //LAB12_OBSERVER_H
