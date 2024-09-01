#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 고객정보를 나타내는 클래스
class Customer {
public:
    int id;                // 고객 ID
    string name;           // 고객 이름
    string phoneNumber;    // 고객 전화번호
    string gender;         // 고객 성별

    // 생성자 : 고객 정보를 초기화
    Customer(int id, string name, string phoneNumber, string gender)
        : id(id), name(name), phoneNumber(phoneNumber), gender(gender) {}

    // 고객 정보를 출력하는 함수
    void display() const {
        cout << "\n----------------------------------------" << endl;
        cout << left << setw(10) << "ID" << ": " << id << endl
            << left << setw(10) << "Name" << ": " << name << endl
            << left << setw(10) << "Phone" << ": " << phoneNumber << endl
            << left << setw(10) << "Gender" << ": " << gender << endl;
        cout << "----------------------------------------" << endl;
    }

    // NEW ID를 반환하는 멤버 함수
    int getId() const { return id; }
};

#endif // !CUSTOMER_H