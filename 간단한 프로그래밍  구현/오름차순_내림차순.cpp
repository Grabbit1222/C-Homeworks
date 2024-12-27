#include <iostream>
using namespace std;

// �������� �Լ�
void Ascending(float arr[5]) {
    float temp;
    for (int i = 0; i < 5; i++) { // ���� ū ���ڸ� arr[4], �� ���� ū ���ڸ� arr[3]....
        for (int j = 0; j < 4 - i; j++) { // �̿��ϴ� ���ڵ� �񱳡�
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// �������� �Լ�
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
    // ���� ����
    float nums[5];
    int X;
    cout << "5���� ���ڸ� �Է����ּ���" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "���� �Է�: ";
        cin >> nums[i];
    }

    cout << "�������� or ��������?" << endl;
    cout << "�������� 1��, �������� 2��" << endl;
    cin >> X;

    if (X == 1) {
        Ascending(nums); // Sort the array
        cout << "��������: ";
    }

    else if (X == 2) {
        Descending(nums);
        cout << "��������: ";
    }
    // �Է� ���� ���ڰ� 1�̳� 2�� �ƴ� ���
    else {
        cout << "Press on the right button" << endl;
    }

    // ���� ������ ���� ����Ʈ
    for (int i = 0; i < 5; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}