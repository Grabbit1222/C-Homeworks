#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() = 0;  // ���� ���� �Լ�
    virtual ~Animal() {}  // ���� �Ҹ���
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Bow Wow" << endl; } //overrisde�� makeSound ������
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

    //������
    Animal* animals[] = { &dog, &cat, &cow };
    for (Animal* animal : animals) {  // animals �迭 �ȿ� �ִ� Animal Ÿ���� animal�� �ּҵ�
        animal->makeSound();
    }
}