#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() = 0;  // 순수 가상 함수
    virtual ~Animal() {}  // 가상 소멸자
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Bow Wow" << endl; } //overrisde로 makeSound 재정의
};

class Cat : public Animal {
public:
    void makeSound() override { cout << "Meow Meow" << endl; }
};

class Cow : public Animal {
public:
    void makeSound() override { cout << "Moo Moo" << endl; }
};

int main() {
    Dog dog;
    Cat cat;
    Cow cow;

    //다형성
    Animal* animals[] = { &dog, &cat, &cow };
    for (Animal* animal : animals) {  // animals 배열 안에 있는 Animal 타입의 animal의 주소들
        animal->makeSound();
    }
}