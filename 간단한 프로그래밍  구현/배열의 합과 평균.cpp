#include <iostream>
using namespace std;


// 총합 함수
float sum(float arr[]) {
    float a;
    a = 0;
    for (int j = 0; j <= 4; j++) {
        a = a + arr[j];
    }
    return a;
}
// 5로 나누는 함수
float avg(float x) {
    int b;
    b = x / 5;
    return b;
}

int main() {
    // 변수 선언
    float nums[5];
    int i = 1;
    cout << "5개의 숫자를 입력해주세요" << endl;
    for (i; i <= 5; i++) {
        cout << "숫자 입력: ";
        cin >> nums[i - 1];
    }

    cout << "5개 숫자의 합: " << sum(nums) << endl;
    cout << "5개 숫자의 평균: " << avg(sum(nums)) << endl;

    return 0;
}