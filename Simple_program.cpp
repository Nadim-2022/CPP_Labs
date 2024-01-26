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
    std::vector<int> numbers;
    int n;
    std::cout << "How many numbers do you want enter?  ";
    std::cin >> n;
    for (int i = 0; i < n; i++){
        int number;
        std::cout << "Enter nr[" << i + 1 << "]: ";
        std::cin >> number;
        numbers.push_back(number);
    }
    std::cout << "You entered: ";
    for (int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i];
        if (i < numbers.size() - 1){
            std::cout << ", ";
        }
    }
    return 0;
}