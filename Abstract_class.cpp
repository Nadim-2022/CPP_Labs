//
// Created by iamna on 02/03/2024.
//
#include "iostream"

using namespace std;
class Counter {
public:
    virtual void inc() = 0;
    virtual void dec() = 0;
    virtual operator int() = 0;
    virtual ~Counter() {};
};

class LimitedCounter : public Counter {
public:
    LimitedCounter(int value0, int upperLimit0);
    void inc() override;
    void dec() override;
    operator int() override;

private:
    int value;
    int upperLimit;
};

LimitedCounter::LimitedCounter(int value0, int upperLimit0) {
    value = value0;
    upperLimit = upperLimit0;
}
void LimitedCounter::inc (){
    if ( value < upperLimit){
        value++;
    }
}
void LimitedCounter::dec() {
    if (value < 0){
        value--;
    }
}
LimitedCounter::operator int() {
    return value;
}
class OverflowCounter : public Counter{
public:
    OverflowCounter(int value0, int upperLimit0);
    void inc() override;
    void dec() override;
    operator int() override;

private:
    int value;
    int upperLimit;
};
OverflowCounter::OverflowCounter(int value0, int upperLimit0) {
    value = value0;
    value = upperLimit0;
}

void OverflowCounter::inc() {
    if (value >= upperLimit){
        value = 0;
    }
}
void OverflowCounter::dec() {
    if (value <= 0){
        value = upperLimit;
    }
}
OverflowCounter::operator int() {
    return value;
}

// you need to implement this function
void UseCounter(Counter& ctr, int num){
    if (num > 0){
        for ( int i = 0; i < num ; i++){
            ctr.inc();
        }
    } else{
        for ( int i = num; i < 0; i++){
            ctr.dec();
        }
    }
}


int main(int argc, char** argv) {
    LimitedCounter lc(0, 5);
    OverflowCounter oc(5, 9);

    cout << oc << endl;
    UseCounter(oc, 5);
    cout << oc << endl; // should display zero
    UseCounter(oc, -1);
    cout << oc << endl; // should display 9
    oc.dec();
    cout << oc << endl; // should display 8
/*
    cout << lc << endl;
    lc.inc();
    cout << lc << endl;
    lc.dec();
    cout << lc << endl;
    for(int i = 0; i < 10; ++i) lc.inc();
    cout << lc << endl;
    UseCounter(lc, -9);
    cout << lc << endl;
*/
    return 0;
}
