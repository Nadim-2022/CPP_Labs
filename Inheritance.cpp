#include <iostream>
#include <string>


class Person {
public:
    Person(const char* name0 = "nobody");
    virtual ~Person() = default;
    virtual void identity() const;
    virtual void interrogate(){};
private:
    std::string name;
};

class Spy : public Person {
public:
    Spy(const char* name0, const char* alias0, int resistance0);
    void set_identity(const char* name);
    void identity() const override;
    void interrogate() override;
    private:
    std::string alias;
    int resistance;
};

Person::Person(const char* name0) : name(name0) {}

void Person::identity() const {
    std::cout << "My name is: " << name << std::endl;
}

Spy::Spy(const char* name0, const char* alias0, int resistance0) : Person(name0), alias(alias0), resistance(resistance0) {}

void Spy::set_identity(const char* name0) {
    this->alias = name0;
}


void Spy::identity() const {
    if (resistance > 0) {
        std::cout << "My name is: " << alias << std::endl;
    } else {
        Person::identity();
        std::cout << "My alias is: " << alias << std::endl;
    }
}
void Spy::interrogate() {
    resistance--;
}


int main(int argc, char** argv) {

    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);

    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy.interrogate();
        spy.identity();
    }
    spy.set_identity("Bill Munny");
    spy.identity();

    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy2.interrogate();
        spy2.identity();
    }

    return 0;
}