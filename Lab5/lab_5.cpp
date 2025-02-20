#include <iostream>
#include <string>

class Animal {
protected:
  std::string name;
  int age;
public:
  Animal(std::string name, int age) : name(name), age(age) {};

  int makeSaund() {
    std::cout << "Animal makes a sound.\n";
    return 0;
  }

  virtual ~Animal() {}
};

class Dog : public Animal {
public:
  Dog(std::string name, int age) : Animal(name, age) {};
  int makeSaund() {
    std::cout << "Dog barks.\n";
    return 0;
  }

  ~Dog() override {}
};

class Cat : public Animal {
public:
  Cat(std::string name, int age) : Animal(name, age) {};
  int makeSaund() {
    std::cout << "Cat meows.\n";
    return 0;
  }

  ~Cat() override{}

};
int main() {
  Cat frstCat("Barsik", 3);
  Dog frstDog("Borbos", 4);

  frstCat.makeSaund();
  frstDog.makeSaund();

  return 0;
}
