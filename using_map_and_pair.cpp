/*
Write a program that defines a map<string, int>
Program asks user to enter a name or “stop” or “print”. If user enters “stop” the program stops. If
user enters “print” then the program prints the content of the map as key-value pairs. If input is
neither “stop” not “print” then program asks user to enter an integer. Then program uses the
entered name as the key (~index to map) to store the entered integer.
To get the keys from the map you need to use iterators or range-for to loop through the map. When
looping through the map the elements of the map are std::pairs that contain key and the value. If
using iterator, the iterator “points” to a pair where first is key and second is the value. For example, if
your iterator is called it then key of the current element is it->first and value is it->second.
For example:
Enter name or “stop” or “print”: Keijo
Enter integer: 77
Enter name or “stop” or “print”: Erkki
Enter integer: 23
Enter name or “stop” or “print”: What
Enter integer: 5
Enter name or “stop” or “print”: print
Erkki : 23
Keijo : 77
What : 5
Enter name or “stop” or “print”: Himmel
Enter integer: 99
Enter name or “stop” or “print”: print
Erkki : 23
Himmel : 99
Keijo : 77
What : 5
Enter name or “stop” or “print”: Himmel
Enter integer: 55
Enter name or “stop” or “print”: print
Erkki : 23
Himmel : 55
Keijo : 77
What : 5
Enter name or “stop” or “print”: stop
<program stops>
 */
#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, int> myMap;
    std::string name;
    int number;
    bool stop = false;
    while (!stop){
        std::cout << R"(Enter name or "stop" or "print": )";
        std::cin >> name;
        if (name == "stop"){
            std::cout << "Program has been stopped !\n";
            stop = true;
        }else if (name == "print"){
            for (const auto & it : myMap){
                std::cout << it.first << " : " << it.second << std::endl;
            }
            stop = true;
        }else{
            std::cout << "Enter integer: ";
            std::cin >> number;
            myMap.insert(std::pair<std::string, int>(name, number));
            //std::cin.ignore();
        }
    }
    return 0;
}