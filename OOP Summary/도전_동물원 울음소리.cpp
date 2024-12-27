#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Animal �⺻ Ŭ����
class Animal {
public:
    virtual void makeSound() = 0;  // ���� ���� �Լ�
    virtual ~Animal() {}  // ���� �Ҹ���
};

// Dog Ŭ����
class Dog : public Animal {
public:
    void makeSound() override { cout << "Bow Wow" << endl; }
};

// Cat Ŭ����
class Cat : public Animal {
public:
    void makeSound() override { cout << "Meow Meow" << endl; }
};

// Cow Ŭ����
class Cow : public Animal {
public:
    void makeSound() override { cout << "Moo Moo" << endl; }
};

// Zoo Ŭ����
class Zoo {
private:
    Animal* animals[10];  // ���� ��ü�� �����ϴ� ���� �迭
    int animalCount = 0;   // ���� ���� ����

public:
    // ������ �������� �߰��ϴ� �Լ�
    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount++] = animal;  // ���� ��ü�� �迭�� �߰�
        }
        else {
            cout << "�������� �� �̻� ������ �߰��� �� �����ϴ�!" << endl;
        }
    }

    // �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
    void performActions() {
        for (int i = 0; i < animalCount; ++i) {  // ��� ���� ��ü�� ���� ���������� �Ҹ� ����
            animals[i]->makeSound();
        }
    }

    // Zoo �Ҹ���
    ~Zoo() {
        for (int i = 0; i < animalCount; ++i) {
            delete animals[i];  // ���� �Ҵ�� ���� ��ü �޸� ����
        }
    }
};

// ���� ������ �����ϴ� �Լ�
Animal* createRandomAnimal() {
    int random = rand() % 3;  // ���� ���� 3�� ���� ������. 0, 1, 2 �� �ϳ��� ������

    // ���� ���� ���� Dog, Cat, Cow ��ü�� �������� �����ϰ� �� �ּҰ�(������)�� ��ȯ
    if (random == 0) {
        return new Dog();
    }
    else if (random == 1) {
        return new Cat();
    }
    else {
        return new Cow();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // ���� ����, ���� ���� ����� �� ����

    Zoo zoo;

    // ���� 5������ �������� �����Ͽ� �������� �߰�
    for (int i = 0; i < 5; ++i) {
        Animal* randomAnimal = createRandomAnimal();
        zoo.addAnimal(randomAnimal);  // �������� ���� �߰�
    }

    // �������� �Ҹ��� �ൿ�� ����
    zoo.performActions();

    return 0;
}