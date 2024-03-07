//
// Created by iamna on 06/03/2024.
//

#ifndef LAB12_COLOROBSERVER_H
#define LAB12_COLOROBSERVER_H

// ColorObserver.h
#include <iostream>
#include "Observer.h"

class ColorObserver : public Observer {
public:
    ColorObserver(std::string color) : color(std::move(color)) {}

    void notify(int value) override {
        std::cout << "The value of " << color << " has changed to " << value << std::endl;
    }

private:
    std::string color;
};

#endif //LAB12_COLOROBSERVER_H
