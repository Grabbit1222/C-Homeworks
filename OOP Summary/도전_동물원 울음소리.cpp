#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Animal 기본 클래스
class Animal {
public:
    virtual void makeSound() = 0;  // 순수 가상 함수
    virtual ~Animal() {}  // 가상 소멸자
};

// Dog 클래스
class Dog : public Animal {
public:
    void makeSound() override { cout << "Bow Wow" << endl; }
};

// Cat 클래스
class Cat : public Animal {
public:
    void makeSound() override { cout << "Meow Meow" << endl; }
};

// Cow 클래스
class Cow : public Animal {
public:
    void makeSound() override { cout << "Moo Moo" << endl; }
};

// Zoo 클래스
class Zoo {
private:
    Animal* animals[10];  // 동물 객체를 저장하는 동적 배열
    int animalCount = 0;   // 현재 동물 개수

public:
    // 동물을 동물원에 추가하는 함수
    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount++] = animal;  // 동물 객체를 배열에 추가
        }
        else {
            cout << "동물원에 더 이상 동물을 추가할 수 없습니다!" << endl;
        }
    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    void performActions() {
        for (int i = 0; i < animalCount; ++i) {  // 모든 동물 객체에 대해 순차적으로 소리 내기
            animals[i]->makeSound();
        }
    }

    // Zoo 소멸자
    ~Zoo() {
        for (int i = 0; i < animalCount; ++i) {
            delete animals[i];  // 동적 할당된 동물 객체 메모리 해제
        }
    }
};

// 랜덤 동물을 생성하는 함수
Animal* createRandomAnimal() {
    int random = rand() % 3;  // 랜덤 수를 3을 나눈 나머지. 0, 1, 2 중 하나가 생성됨

    // 난수 값에 따라 Dog, Cat, Cow 객체를 동적으로 생성하고 그 주소값(포인터)을 반환
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
    srand(static_cast<unsigned int>(time(0))); // 난수 생성, 랜덤 수를 양수로 형 변형

    Zoo zoo;

    // 동물 5마리를 랜덤으로 생성하여 동물원에 추가
    for (int i = 0; i < 5; ++i) {
        Animal* randomAnimal = createRandomAnimal();
        zoo.addAnimal(randomAnimal);  // 동물원에 동물 추가
    }

    // 동물들의 소리와 행동을 실행
    zoo.performActions();

    return 0;
}