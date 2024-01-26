/*
    Implement a class for calculaIng running average of a number of values. The idea of running average
    that average is calculated of last N values. For example, when running average of last 10 values is
    calculated every Ime a new value is added if there are already 10 values the oldest value is removed.
    Implement a class called RunningAverage:
        • Constructor takes number of values as a parameter for example:
        RunningAverage avg(5);
        Creates an instance that remember five last values.
        • A deque of integers is used to store the values
        • Class has member funcIon void add_value(int value) which is used to add a new
        value and to remove the oldest value if there are specified number of elements so that
        number of values in the never exceeds the size given in the constructor.
        • Class has member funcIon double get_average() that returns the average of the stored
        values.
    Write a program that creates running average object to calculate running average of last five
    numbers. Program asks user to enter numbers and to enter zero to stop. If entered value is not zero
    it is added to the running average and program prints the current running average. If value is zero the
    program prints the current running average and then stops.
 */

#include <iostream>
#include <deque>

#define MAX 5
class RunningAverage{
    public:
        RunningAverage(int max0 = 0);
        void add_value(int value);
        double get_average();
    private:
        std::deque<int> values;
        int max;
};

RunningAverage::RunningAverage(int max0) {
    max = max0;
}

void RunningAverage::add_value(int value) {
    if (values.size() == max){
        values.pop_front();
    }
    values.push_back(value);
}

double RunningAverage::get_average() {
    double sum = 0;
    for (int value : values){
        sum += value;
    }
    return sum / (double) values.size();
}

int main(){
    RunningAverage avg(MAX);
    bool stop = false;
    int number;
    while (!stop){
        std::cout << "Enter a number or 0 to stop: ";
        std::cin >> number;
        if (number == 0){
            std::cout << "Program has been stopped !\n";
            stop = true;
        }
        avg.add_value(number);
        std::cout << "Current average is " << avg.get_average() << std::endl;
    }
    return 0;
}