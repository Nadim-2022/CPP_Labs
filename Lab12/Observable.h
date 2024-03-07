//
// Created by iamna on 06/03/2024.
//

#ifndef LAB12_OBSERVABLE_H
#define LAB12_OBSERVABLE_H

// Observable.h
#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.h"

class Observable {
public:
    void addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

protected:
    void notifyObservers(int value) {
        for (const auto& observer : observers) {
            observer->notify(value);
        }
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif //LAB12_OBSERVABLE_H
