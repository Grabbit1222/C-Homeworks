#include <iostream>
using namespace std;

// 오름차순 함수
void Ascending(float arr[5]) {
    float temp;
    for (int i = 0; i < 5; i++) { // 가장 큰 숫자를 arr[4], 그 다음 큰 숫자를 arr[3]....
        for (int j = 0; j < 4 - i; j++) { // 이웃하는 숫자들 비교↑
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 내림차순 함수
void Descending(float arr[5]) {
    float temp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // 변수 선언
    float nums[5];
    int X;
    cout << "5개의 숫자를 입력해주세요" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "숫자 입력: ";
        cin >> nums[i];
    }

    cout << "오름차순 or 내림차순?" << endl;
    cout << "오름차순 1번, 내림차순 2번" << endl;
    cin >> X;

    if (X == 1) {
        Ascending(nums); // Sort the array
        cout << "오름차순: ";
    }

    else if (X == 2) {
        Descending(nums);
        cout << "내림차순: ";
    }
    // 입력 받은 숫자가 1이나 2가 아닌 경우
    else {
        cout << "Press on the right button" << endl;
    }

    // 새로 나열된 숫자 프린트
    for (int i = 0; i < 5; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}