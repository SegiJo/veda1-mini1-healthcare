#include "customer_manage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <unistd.h>

using namespace std;

// NEW customerManager 클래스의 멤버 함수 getCustomerById를 호출해 고객 ID를 받아오는 함수 추가
Customer* customerManager::getCustomerById(int id) {
    for (auto& cust : customers) { // 고객 목록에서 해당 ID를 가진 고객을 찾음
        if (cust.getId() == id) {
            return &cust; // 포인터로 반환
        }
    }
    return nullptr; // 찾지 못하면 nullptr 반환
}

// CSV 파일에서 고객 데이터를 읽어와 customers 벡터에 추가하는 함수
void customerManager::loadFromCSV(const string& filename) { // filename <= cust_filename = "customers.csv"
	ifstream file(filename); // 파일 스트림 생성

	//파일이 열리지 않으면 에러 메시지 출력
	if (!file.is_open()) {
		cerr << "Cannot open file: " << filename << endl;
		return;
	}

	string line;

	// 파일의 각 줄을 읽어 처리한다.
	while (getline(file, line)) {
		stringstream ss(line); // 한 줄을 stringstream으로 변환
		string idStr, name, phoneNumber, gender;

		//각 필드를 콤마로 구분하여 읽기
		getline(ss, idStr, ',');
		getline(ss, name, ',');
		getline(ss, phoneNumber, ',');
		getline(ss, gender, ',');

		//각 필드가 유효한지 확인하고 객체 생성
		if (!idStr.empty() && !name.empty() && !phoneNumber.empty() && !gender.empty()) {
			int id = stoi(idStr); //ID를 정수로 변환
			customers.emplace_back(id, name, phoneNumber, gender);
		}
	}
	file.close(); //파일 닫기
}

// 새로운 고객을 추가하는 함수 (간단한 입력을 통해 정보 입력)
void customerManager::addCustomer() {
	int id;
	string name, phoneNumber, gender;

	if (customers.size() >= 10) {
		cout << "Cannot add more customers. Please delete some customer information. Returning to menu." << endl;
		//this_thread::sleep_for(chrono::seconds(1)); VSCODE에서 작동 X
		sleep(1); // 대체로 sleep 사용
		return;
	}

	//--------ID입력---------
	while (true) {
		cout << "Customer ID (Enter 0 to cancel): ";

		if (!(cin >> id)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid number." << endl;
			continue;
		}

		cin.ignore();

		if (id == 0) return;

		// ID 범위 확인 (예: 1~100 사이의 유효한 값)
		if (id < 1 || id > 100) {
			cout << "ID must be a number between 1 and 100. Please try again." << endl;
			continue;
		}

		//ID 중복 확인
		bool idExists = false;
		for (const auto& customer : customers) {
			if (customer.id == id) {
				idExists = true; break;
			}
		}

		if (idExists) {
			cout << "ID already exists. Please try again." << endl;
			continue;
		}
		else {
			break; // ID가 중복되지 않으면 다음으로 이동
		}
	}

	//--------이름 입력---------
	while (true) {
		cout << "Customer Name (Enter 0 to cancel): ";
		getline(cin, name);

		if (name == "0") return;

		if (name.empty()) {
			cout << "Please enter a name." << endl;
		}
		else {
			break; //이름이 입력되면 다음으로 이동
		}
	}

	//--------전화번호 입력-----
	while (true) {
		cout << "Phone Number (excluding dashes, Enter 0 to cancel): ";
		getline(cin, phoneNumber);

		if (phoneNumber.empty()) {
			cout << "Please enter a phone number." << endl;
		}
		else if (phoneNumber == "0") return;
		else break; // 전화번호가 입력되면 다음으로 이동
	}

	//--------성별 입력--------
	while (true) {
		cout << "Gender (M/F, Enter 0 to cancel): ";
		getline(cin, gender);

		if (gender.empty()) {
			cout << "Please enter gender." << endl;
		}
		else if (gender == "0") return;
		else if (gender == "M" || gender == "F") {
			break; // 성별이 M 또는 F로 올바르게 입력되면 다음 단계로 이동
		}
		else {
			cout << "Invalid gender. Please enter M or F." << endl;
		}
	}

	//새로운 고객 객체를 벡터에 추가한다.
	customers.emplace_back(id, name, phoneNumber, gender);
	cout << "Customer has been added! Welcome to customer management!" << endl;

	//추가한 데이터를 customers.csv 파일에 즉시 저장
	saveToCSV("customers.csv");
}

// 고객을 삭제하는 함수(ID로 검색하여 삭제)
void customerManager::deleteCustomer() {
	int id;

	cout << "\nCurrent ID list:\n\n" << "ID List | ";
	int count = 0;

	for (const auto& customer : customers) {
		cout << customer.id << " ";
		count++;
		if (count % 10 == 0) {
			cout << "\n";
		}
	}
	if (count % 10 != 0) {
		cout << "\n";
	}

	cout << "\n  >> ID of customer to delete (Delete all -1): ";
	cin >> id;

	if (id == -1) {
		customers.clear();
		cout << "! All customers have been deleted." << endl;
		saveToCSV("customers.csv");
		return;
	}

	for (auto it = customers.begin(); it != customers.end(); ++it) {
		if (it->id == id) {
			customers.erase(it);
			cout << " \n >> Customer has been deleted." << endl;
			saveToCSV("customers.csv");
			return;
		}
	}

	cout << "Cannot find customer with the specified ID." << endl;

	//추가한 데이터를 customers.csv 파일에 즉시 저장
	saveToCSV("customers.csv");
}

// 고객 정보를 수정하는 함수(ID로 검색하여 정보 수정)
void customerManager::modifyCustomer() {
	int id;

	//현재 존재하는 ID목록을 10개 단위로 출력
	cout << "\nCurrent ID list:\n\n" << "ID List | ";
	int count = 0;

	for (const auto& customer : customers) {
		cout << customer.id << " ";
		count++;
		if (count % 10 == 0) {
			cout << "\n";
		}
	}
	if (count % 10 != 0) {
		cout << "\n";
	}

	cout << "  >> ID of customer to modify: ";
	cin >> id;
	cin.ignore();

	//ID로 검색하여 고객을 찾는다.
	for (auto it = customers.begin(); it != customers.end(); ++it) {
		if (it->id == id) {
			cout << "New Name: ";
			cin.ignore();
			getline(cin, it->name);
			
			cout << "New Phone Number: ";
			getline(cin, it->phoneNumber);

			cout << "New Gender: ";
			getline(cin, it->gender);

			cout << "Customer information has been updated." << endl;
			saveToCSV("customers.csv");
			return;
		}
	}
	// 고객을 찾지 못한 경우
	cout << "\nCannot find customer with the specified ID. Please try again." << endl;

	//수정 후 데이터를 customers.csv 파일에 즉시 저장
	saveToCSV("customers.csv");
}

// 고객 정보를 조회하는 함수(ID로 검색하여 정보 출력)
void customerManager::viewCustomer() const {
	int id;
	bool customerFound = false;

	cout << "\nCurrent ID list:\n\n" << "ID List | ";
	int count = 0;
	for (const auto& customer : customers) {
		cout << customer.id << " ";
		count++;
		if (count % 10 == 0) {
			cout << "\n";
		}
	}
	if (count % 10 != 0) {
		cout << "\n\n";
	}

	while (!customerFound) {
		cout << "  >> ID of customer to view (1~100): ";
		cin >> id;

		if (id == 0) {
			cout << "Returning to main menu.\n" << endl;
			return;
		}
		//ID로 검색하여 고객을 찾는다.
		for (auto it = customers.begin(); it != customers.end(); ++it) {
			if (it->id == id) {
				it->display();  // display() : 고객 정보를 출력하는 함수. customer.h에 정의됨
				cout << "\nReturning to menu in 3 seconds.\n";
				//this_thread::sleep_for(chrono::seconds(3)); VSCODE에서 작동 X
				sleep(3); // 대체로 sleep 사용
				customerFound = true;
				return;
			}
		}

		// 고객을 찾지 못한 경우
		cout << " !! Cannot find customer with the specified ID. Please try again.\n(Enter 0 to exit)" << endl;
	}
}

// 고객 데이터를 CSV 파일에 저장하는 함수
void customerManager::saveToCSV(const string& filename) const {
	ofstream file(filename);

	if (!file.is_open()) {
		//파일이 열리지 않으면 에러 메시지 출력
		cerr << "Cannot open file: " << filename << endl;
		return;
	}

	//모든 고객 데이터를 파일에 기록
	for (const auto& customer : customers) { // 범위 기반 for문으로 customers 객체 순회 
		file << customer.id << ","
			<< customer.name << ","
			<< customer.phoneNumber << ","
			<< customer.gender << endl;
	}
	file.close(); //파일 닫기
}
