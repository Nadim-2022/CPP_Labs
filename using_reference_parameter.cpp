/*
 * Write a function that takes a reference to string and a character (by value) as parameters. The
 * function replaces all occurrences of the character with underscores.
 * Write a program that ask user to enter a string. Then program asks user to enter character to replace
 * or “stop” to stop the program. Note that program must read a string after the second question to be
 * able to test for “stop”. If answer is not “stop” then program passes the first character of second
 * question’s answer as the character to replace. Then program prints the string and continues. If
 * answer is “stop” the program ends.
 * For example:
 * Enter a string: This is a test
 * Enter character to replace or “stop”: i
 * Result: Th_s _s a test
 * Enter a string: I love C++
 * Enter character to replace or “stop”: stop
 */

#include <iostream>
#include <string>


void replace_character(std::string &str, char character){

    for (char & i : str){
        if (i == character){
            i = '_';
        }
    }
    /*
    std::string replaceWith {"_"};
    size_t pos = str.find(character);
    while (pos != std::string::npos){
        str.replace(pos, replaceWith.size(), replaceWith);
        pos = str.find(character);
    }
     */


}


int main() {
    std::string str;
    std::string character;
    bool stop = false;
    while (!stop){
        std::cout << "Enter a string: ";
        std::getline(std::cin, str);
        std::cout << "Enter character to replace or \"stop\" : ";
        std::getline(std::cin, character);
       if(!character.compare("stop")){
           std::cout << "\nProgram has been stopped !\n";
           stop = true;
       }else{
           replace_character(str, character[0]);
           std::cout << "Result: " << str << std::endl;
       }

    }
    return 0;
}
