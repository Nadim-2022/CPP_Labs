#include <iostream>
#include <string>

class Observer;
class Subject {
public:
    virtual void Attach(Observer *o) = 0; // Set
    virtual void Notify() = 0;
};
// Abstract interface of Observer
class Observer {
public:
    virtual void Update() = 0;
};

class Person {
public:
    Person(const char* name0 = "nobody");
    virtual ~Person() = default;
    virtual void identity() const;
    virtual void interrogate(){};
    std::string getName() const { return name; }
private:
    std::string name;
};
Person::Person(const char* name0) : name(name0) {}

void Person::identity() const {
    std::cout << "My name is: " << name << std::endl;
}


class Spy : public Person, public Subject{
public:
    Spy(const char* name0, const char* alias0, int resistance0);
    void set_identity(const char* name);
    void identity() const override;
    void interrogate() override;
    void Attach(Observer *o) override;
    void Notify() override;
private:
    std::string alias;
    int resistance;
    Observer *observer;
};
Spy::Spy(const char* name0, const char* alias0, int resistance0) : Person(name0), alias(alias0), resistance(resistance0) {}

void Spy::Attach(Observer *o) {
    this->observer = o;
}
void Spy::Notify(){
    if(observer != nullptr){
        observer->Update();
    }
}
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
    if (resistance<=0){
        Notify();
    }

}

class Judge: public Person, public Observer {
public:
    Judge(const char* name0): Person(name0){};
    void Update() override;
private:
};
void Judge::Update() {
    std::cout << "[My name is: " << getName() << std::endl;
    std::cout << "I'm sending a spy to prison!]" << std::endl;
}



int main(int argc, char** argv) {

    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);
    Judge judge("Judge Barnhill");
    spy.Attach(&judge);
    spy2.Attach(&judge);

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