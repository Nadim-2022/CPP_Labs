/*
 * Write a program that asks user to enter a line that contains integers or “stop” to stop the program. If
 * user enters a string that starts with “stop” the program stops. Otherwise, the program creates a
 * string stream from the user input and reads integers from the stream. Program keeps reading and
 * summing integer until the stream ends or reading an integer fails because text or other nonnumerical character is encountered.
 * When the reading stops the sum and count are printed and program asks user to enter another string.
 * For example:
 * Enter a line with numbers or “stop”: 1 6 34 78 4 6
 * Total of 6 numbers is 129
 * Enter a line with numbers or “stop”: 4 99 zip 44 6
 * Total of 2 numbers is 103
 * Enter a line with numbers or “stop”: stop
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::string line;
    bool stop = false;
    while (!stop){
        std::cout << "Enter a line with numbers or \"stop\": ";
        std::getline(std::cin, line);
        if (line.find("stop") == 0){
            std::cout << "Program has been stopped !\n";
            stop = true;
        }else{
            std::istringstream stream(line);
            int sum = 0;
            int count = 0;
            int number;
            while (stream >> number){
                sum += number;
                count++;
            }
            std::cout << "Total of " << count << " numbers is " << sum << std::endl;
        }

    }
    return 0;
}

/*
 int main() {
    std::string line;
    std::vector<int> numbers;
    int pts;
    while (true){
        std::cout << "Enter a line with numbers or \"stop\": ";
        std::getline(std::cin, line);
        if (line.find("stop") == 0){
            std::cout << "Program has been stopped !\n";
            break;
        }
        std::istringstream stream(line);
        while (stream >> pts){
            numbers.push_back(pts);
        }
        std::cout << "Total of " << numbers.size() << " numbers is " << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
    }
    return 0;
}

 */