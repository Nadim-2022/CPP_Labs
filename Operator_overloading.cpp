/*
 Implement class House for storing housing informa3on.
The class must use std::string for storing the address of the house, a double for the size (area in m2
)
of the house and an int for the price of the house in euros. All data member must be private.
Class must define a constructor that takes the house informa3on as parameters and there must be
default constructor.
The class must have the following operators:
• Output operator for prin3ng the housing informa3on with minimal formaDng. No newlines
may be printed by the operator.
• Input operator for reading the housing informa3on from a stream. The operator must accept
the format produced by the output operator. The address of the house may contain spaces
so the operator must be able to read an address with spaces in it.
• Less than operator that compares two houses by price/m2
Class must define the following member func3ons:
• setAddress for seDng the address of the house
• setArea for seDng the area of the house
• setPrice for seDng the price of the house
Write a program that defines a vector of House.
The program asks user to enter informa3on of five houses and stores them in the vector. The houses
must be asked in the following ways:
• Ask user to enter the house informa3on (address, area, price) and use constructor to create
a house by passing the informa3on as parameters
• Create a house using default constructor, ask user to enter the house informa3on and use
seJer func3ons before adding the house to the vector
• Create house using default constructor and read values using the input operator
You can decide the mix between the five houses but at least one house must be asked using each of
the above ways.
Then sort the vector using std::sort and print the house informa3on one house per line.
Notes:
To read a string from a stream using other that default delimiter (white space) you can use
std::getline. It has overload that takes three parameters: stream to read from, reference to a string,
and delimi3ng character. For example:
std::getline(std::cin, my_str, ':');
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class House{
    friend std::ostream &operator<<(std::ostream &OUT, const House &house);
    friend std::istream &operator>>(std::istream &CIN , House &house);
public:
    House() :  area(0.0), price(0) {};
    House(std::string &address0, double area0, int price0);
    void setAddress(std::string &address0);
    void setArea(double area0);
    void setPrice(int price0);
    bool operator<(const House &house) const;
private:
    std::string address;
    double area;
    int price;
};
House::House(std::string &address0, double area0, int price0) {
    address = address0;
    area = area0;
    price = price0;
}
void House::setAddress(std::string &address0){
    address = address0;
}
void House::setArea(double area0) {
    area = area0;
}
void House::setPrice(int price0) {
    price = price0;
}
std::ostream &operator<<(std::ostream &COUT, const House &house){
    return COUT << house.address << " " << house.area << " "<<house.price;
}
std::istream &operator>>(std::istream  &CIN, House &house){
    std::getline(CIN, house.address, ':');
    CIN >> house.area >> house.price;
    return CIN;
}

bool House::operator<(const House &house) const{
    return price / area < house.price / house.area;
}


int main(){
    std::vector<House> houses;
    std::string address;
    double area;
    int price;
    //Ask user to enter the house information (address, area, price) and use constructor to create
    for (int i = 0; i < 3; i++){
        std::cout << "Enter address, area and price: ";
        std::getline(std::cin, address, ':');
        std::cin >> area >> price;
        House house(address, area, price);
        houses.push_back(house);
    }
    //Create a house using default constructor, ask user to enter the house information and use
    House house;
    std::cout << "Enter address, area and price: ";
    std::getline(std::cin, address, ':');
    std::cin >> area >> price;
    house.setAddress(address);
    house.setArea(area);
    house.setPrice(price);
    houses.push_back(house);

    //Create house using default constructor and read values using the input operator
    House house1;
    std::cout << "Enter address, area and price: ";
    std::cin >> house1;
    houses.push_back(house1);

    std::sort(houses.begin(), houses.end());
    for (const auto & Nadim : houses){
        std::cout << Nadim << std::endl;
    }
    return 0;


}
