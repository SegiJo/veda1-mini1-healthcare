#include "customer_manage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <unistd.h>

using namespace std;

// NEW customerManager Ŭ������ ��� �Լ� getCustomerById�� ȣ���� �� ID�� �޾ƿ��� �Լ� �߰�
Customer* customerManager::getCustomerById(int id) {
    for (auto& cust : customers) { // �� ��Ͽ��� �ش� ID�� ���� ���� ã��
        if (cust.getId() == id) {
            return &cust; // �����ͷ� ��ȯ
        }
    }
    return nullptr; // ã�� ���ϸ� nullptr ��ȯ
}

// CSV ���Ͽ��� �� �����͸� �о�� customers ���Ϳ� �߰��ϴ� �Լ�
void customerManager::loadFromCSV(const string& filename) { // filename <= cust_filename = "customers.csv"
	ifstream file(filename); // ���� ��Ʈ�� ����

	//������ ������ ������ ���� �޽��� ���
	if (!file.is_open()) {
		cerr << "Cannot open file: " << filename << endl;
		return;
	}

	string line;

	// ������ �� ���� �о� ó���Ѵ�.
	while (getline(file, line)) {
		stringstream ss(line); // �� ���� stringstream���� ��ȯ
		string idStr, name, phoneNumber, gender;

		//�� �ʵ带 �޸��� �����Ͽ� �б�
		getline(ss, idStr, ',');
		getline(ss, name, ',');
		getline(ss, phoneNumber, ',');
		getline(ss, gender, ',');

		//�� �ʵ尡 ��ȿ���� Ȯ���ϰ� ��ü ����
		if (!idStr.empty() && !name.empty() && !phoneNumber.empty() && !gender.empty()) {
			int id = stoi(idStr); //ID�� ������ ��ȯ
			customers.emplace_back(id, name, phoneNumber, gender);
		}
	}
	file.close(); //���� �ݱ�
}

// ���ο� ���� �߰��ϴ� �Լ� (������ �Է��� ���� ���� �Է�)
void customerManager::addCustomer() {
	int id;
	string name, phoneNumber, gender;

	if (customers.size() >= 10) {
		cout << "Cannot add more customers. Please delete some customer information. Returning to menu." << endl;
		//this_thread::sleep_for(chrono::seconds(1)); VSCODE���� �۵� X
		sleep(1); // ��ü�� sleep ���
		return;
	}

	//--------ID�Է�---------
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

		// ID ���� Ȯ�� (��: 1~100 ������ ��ȿ�� ��)
		if (id < 1 || id > 100) {
			cout << "ID must be a number between 1 and 100. Please try again." << endl;
			continue;
		}

		//ID �ߺ� Ȯ��
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
			break; // ID�� �ߺ����� ������ �������� �̵�
		}
	}

	//--------�̸� �Է�---------
	while (true) {
		cout << "Customer Name (Enter 0 to cancel): ";
		getline(cin, name);

		if (name == "0") return;

		if (name.empty()) {
			cout << "Please enter a name." << endl;
		}
		else {
			break; //�̸��� �ԷµǸ� �������� �̵�
		}
	}

	//--------��ȭ��ȣ �Է�-----
	while (true) {
		cout << "Phone Number (excluding dashes, Enter 0 to cancel): ";
		getline(cin, phoneNumber);

		if (phoneNumber.empty()) {
			cout << "Please enter a phone number." << endl;
		}
		else if (phoneNumber == "0") return;
		else break; // ��ȭ��ȣ�� �ԷµǸ� �������� �̵�
	}

	//--------���� �Է�--------
	while (true) {
		cout << "Gender (M/F, Enter 0 to cancel): ";
		getline(cin, gender);

		if (gender.empty()) {
			cout << "Please enter gender." << endl;
		}
		else if (gender == "0") return;
		else if (gender == "M" || gender == "F") {
			break; // ������ M �Ǵ� F�� �ùٸ��� �ԷµǸ� ���� �ܰ�� �̵�
		}
		else {
			cout << "Invalid gender. Please enter M or F." << endl;
		}
	}

	//���ο� �� ��ü�� ���Ϳ� �߰��Ѵ�.
	customers.emplace_back(id, name, phoneNumber, gender);
	cout << "Customer has been added! Welcome to customer management!" << endl;

	//�߰��� �����͸� customers.csv ���Ͽ� ��� ����
	saveToCSV("customers.csv");
}

// ���� �����ϴ� �Լ�(ID�� �˻��Ͽ� ����)
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

	//�߰��� �����͸� customers.csv ���Ͽ� ��� ����
	saveToCSV("customers.csv");
}

// �� ������ �����ϴ� �Լ�(ID�� �˻��Ͽ� ���� ����)
void customerManager::modifyCustomer() {
	int id;

	//���� �����ϴ� ID����� 10�� ������ ���
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

	//ID�� �˻��Ͽ� ���� ã�´�.
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
	// ���� ã�� ���� ���
	cout << "\nCannot find customer with the specified ID. Please try again." << endl;

	//���� �� �����͸� customers.csv ���Ͽ� ��� ����
	saveToCSV("customers.csv");
}

// �� ������ ��ȸ�ϴ� �Լ�(ID�� �˻��Ͽ� ���� ���)
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
		//ID�� �˻��Ͽ� ���� ã�´�.
		for (auto it = customers.begin(); it != customers.end(); ++it) {
			if (it->id == id) {
				it->display();  // display() : �� ������ ����ϴ� �Լ�. customer.h�� ���ǵ�
				cout << "\nReturning to menu in 3 seconds.\n";
				//this_thread::sleep_for(chrono::seconds(3)); VSCODE���� �۵� X
				sleep(3); // ��ü�� sleep ���
				customerFound = true;
				return;
			}
		}

		// ���� ã�� ���� ���
		cout << " !! Cannot find customer with the specified ID. Please try again.\n(Enter 0 to exit)" << endl;
	}
}

// �� �����͸� CSV ���Ͽ� �����ϴ� �Լ�
void customerManager::saveToCSV(const string& filename) const {
	ofstream file(filename);

	if (!file.is_open()) {
		//������ ������ ������ ���� �޽��� ���
		cerr << "Cannot open file: " << filename << endl;
		return;
	}

	//��� �� �����͸� ���Ͽ� ���
	for (const auto& customer : customers) { // ���� ��� for������ customers ��ü ��ȸ 
		file << customer.id << ","
			<< customer.name << ","
			<< customer.phoneNumber << ","
			<< customer.gender << endl;
	}
	file.close(); //���� �ݱ�
}
