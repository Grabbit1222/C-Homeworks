#include <iostream>
using namespace std;


// ���� �Լ�
float sum(float arr[]) {
    float a;
    a = 0;
    for (int j = 0; j <= 4; j++) {
        a = a + arr[j];
    }
    return a;
}
// 5�� ������ �Լ�
float avg(float x) {
    int b;
    b = x / 5;
    return b;
}

int main() {
    // ���� ����
    float nums[5];
    int i = 1;
    cout << "5���� ���ڸ� �Է����ּ���" << endl;
    for (i; i <= 5; i++) {
        cout << "���� �Է�: ";
        cin >> nums[i - 1];
    }

    cout << "5�� ������ ��: " << sum(nums) << endl;
    cout << "5�� ������ ���: " << avg(sum(nums)) << endl;

    return 0;
}