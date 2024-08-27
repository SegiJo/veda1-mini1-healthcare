#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

// �������� ��Ÿ���� Ŭ����
class Customer {
public:
    int id;                // �� ID
    string name;           // �� �̸�
    string phoneNumber;    // �� ��ȭ��ȣ
    string gender;         // �� ����

    // ������ : �� ������ �ʱ�ȭ
    Customer(int id, string name, string phoneNumber, string gender)
        : id(id), name(name), phoneNumber(phoneNumber), gender(gender) {}

    // �� ������ ����ϴ� �Լ�
    void display() const {
        cout << "\n�� ID: " << id
            << "| Name: " << name
            << "| Phone: " << phoneNumber
            << "| Gender: " << gender << endl;
    }

    // NEW ID�� ��ȯ�ϴ� ��� �Լ�
    int getId() const { return id; }
};

#endif // !CUSTOMER_H