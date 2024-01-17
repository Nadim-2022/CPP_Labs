/*
 * Write a program that defines an empty vector of integers. Then program asks user how many
 * numbers he/she wants to enter. Then program asks user to enter the numbers one at a time and
 * adds them to the vector. When all number have been entered the program prints the numbers in the
 * vector.
 * For example:
 * How many numbers do you want enter? 4
 * Enter nr[1]: 23
 * Enter nr[2]: 12
 * Enter nr[3]: 4
 * Enter nr[4]: 5
 * You entered: 23, 12, 4, 5
 */

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // empty vector of integers
    int n; // how many numbers user wants to enter
    std::cout << "How many numbers do you want enter?  "; // ask user how many numbers he/she wants to enter
    std::cin >> n; // user enters how many numbers he/she wants to enter
    for (int i = 0; i < n; i++){ // loop that asks user to enter the numbers one at a time and adds them to the vector
        int number;
        std::cout << "Enter nr[" << i + 1 << "]: ";
        std::cin >> number;
        numbers.push_back(number); // adds the number to the vector
    }
    std::cout << "You entered: ";
    for (int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i]; // prints the numbers in the vector
        if (i < numbers.size() - 1){  // if the number is not the last number in the vector, print a comma after the number
            std::cout << ", ";
        }
    }
    return 0;
}