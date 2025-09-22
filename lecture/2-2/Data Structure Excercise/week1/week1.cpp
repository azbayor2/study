#include <iostream>

using namespace std;


class Animal {
    public:
    virtual void makeSound() const{
        cout << "Animal Sound" << "\n";
    }
};

class Dog : public Animal{
    public:
    void makeSound() const override{
        cout << "왈왈" << "\n";
    }
};

class Shape{
    public:
    virtual void draw() const = 0;
    virtual ~Shape(){
        cout << "shape destructor\n";
    }

};

class Circle : public Shape{
    public:
    
    void draw() const{
        cout << "drawing circle\n";
    }

    ~Circle(){
        cout << "Circle destructor";
    }
};



int main(){
    // Animal * animal = new Dog();
    // animal->makeSound();

    // delete animal;

    Shape * s = new Circle();

    s->draw();
    delete s;

    return 0;
}