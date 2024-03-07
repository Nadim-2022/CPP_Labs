//
// Created by iamna on 06/03/2024.
//

#ifndef LAB12_OBSERVABLEINTEDIT_H
#define LAB12_OBSERVABLEINTEDIT_H


// ObservableIntEdit.h
#include "IntEdit.h"
#include "Observable.h"

class ObservableIntEdit : public IntEdit, public Observable {
public:
    ObservableIntEdit(std::string title) : IntEdit(std::move(title)) {}

    bool event(menuEvent e) override {
        bool result = IntEdit::event(e);
        if (result && e == ok) {
            notifyObservers(observarble_integer);
        }
        return result;
    }
};

#endif //LAB12_OBSERVABLEINTEDIT_H
