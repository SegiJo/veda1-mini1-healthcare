#include "layout.h"
#include <unistd.h>
#include <locale.h>

void showMainMenu() {
        cout << "\033[38;5;208m"; // 주황색 적용
        cout << " ###     ###  #######  ######    #######  " << endl;
        cout << "  ###   ###   ##       ##   ##   ##   ##  " << endl;
        cout << "   ### ###    #####    ##   ##   #######  " << endl;
        cout << "    #####     ##       ##   ##   ##   ##  " << endl;
        cout << "     ###      #######  ######    ##   ##  " << endl;
        cout << "\033[0m\n"; // 색상 다시 리셋
        cout << "┌────────────────────────────────────────┐" << endl;
        cout << "│         WELCOME VEDA HEALTHCARE        │" << endl;
        cout << "├────────────────────────────────────────┤" << endl;
        cout << "│                                        │" << endl;
        cout << "│               [1]  고객                │" << endl;
        cout << "│                                        │" << endl;
        cout << "│               [2]  운동                │" << endl;
        cout << "│                                        │" << endl;
        cout << "│               [3]  식단                │" << endl;
        cout << "│                                        │" << endl;
        cout << "│               [0]  종료                │" << endl;
        cout << "│                                        │" << endl;
        cout << "└────────────────────────────────────────┘" << endl;
        cout << "┌────────────────────────────────────────┐" << endl;
        cout << "│  번호 입력: _                          │" << endl;
        cout << "└────────────────────────────────────────┘" << endl;
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[14C"; // 커서를 '번호 입력: ' 위치로 이동

}

//�ܼ� ȭ���� ����� �Լ�
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//���� ���� �޴��� ����ϰ�, ������� ���ÿ� ���� ������ �۾��� �����ϴ� �Լ�
bool customerMenu(customerManager& custmanager) {

    int choice; // �޴� ������ ��ȣ
    do {
        clearConsole();
        cout << "┌─────────────────────────────┐" << endl;
        cout << "│          고객 관리          │" << endl;
        cout << "├─────────────────────────────┤" << endl;
        cout << "│                             │" << endl;
        cout << "│  [1]  입력  │  [2]  수정    │" << endl;
        cout << "│                             │" << endl;
        cout << "│  [3]  삭제  │  [4]  조회    │" << endl;
        cout << "│                             │" << endl;
        cout << "│         [0]  종료           │" << endl;
        cout << "└─────────────────────────────┘" << endl;
        cout << "┌─────────────────────────────┐" << endl;
        cout << "│  번호 입력: _               │" << endl;
        cout << "└─────────────────────────────┘" << endl;
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[14C"; // 커서를 '번호 입력: ' 위치로 이동


        cin >> choice;

        cout << "\n\n";

        if (choice == 1) { // 1. ���� �߰�
            custmanager.addCustomer();
        }
        else if (choice == 2) { // 2. ���� ���� ����
            custmanager.modifyCustomer();
        }
        else if (choice == 3) { // 3. ���� ����
            custmanager.deleteCustomer();
        }
        else if (choice == 4) { // 4. ���� ��ȸ
            custmanager.viewCustomer();
        }
        else if (choice == 0) { // main���� ���ư���
            return false;
        }
        else {
            cout << "Invalid choice entered." << endl;
        }
    } while (choice != 0); // 0�� �Է��ϸ� ���θ޴��� ���ư�.
    return true; // NEW �޴��� ���������� ������� �ʰ� ������ ����� ��� true�� ��ȯ
}

// � ���� �޴� �Լ�
bool exerciseMenu(ExerciseManager& manager, customerManager& custmanager) {
    int choice;
    do {
        clearConsole();
        cout << "┌─────────────────────────────┐" << endl;
        cout << "│          운동 관리          │" << endl;
        cout << "├─────────────────────────────┤" << endl;
        cout << "│                             │" << endl;
        cout << "│  [1]  입력  │  [2]  수정    │" << endl;
        cout << "│                             │" << endl;
        cout << "│  [3]  삭제  │  [4]  조회    │" << endl;
        cout << "│                             │" << endl;
        cout << "│         [0]  종료           │" << endl;
        cout << "└─────────────────────────────┘" << endl;
        cout << "┌─────────────────────────────┐" << endl;
        cout << "│  번호 입력: _               │" << endl;
        cout << "└─────────────────────────────┘" << endl;
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[14C"; // 커서를 '번호 입력: ' 위치로 이동

        cin >> choice;

        cout << "\n\n";

        if (choice == 1) {
            int id;
            string type;
            int duration;

            cout << "Customer ID: ";
            cin >> id;

            Customer* cust = custmanager.getCustomerById(id); 
            if (cust == nullptr) {
                cout << "No customer found with ID: " << id << endl;
                sleep(3);
                continue;
            }

            cout << "Exercise Type: ";
            cin >> type;
            cout << "Exercise Duration (minutes): ";
            cin >> duration;
            manager.addExercise(*cust, type, duration);
        }
        else if (choice == 2) {
            int id;
            string type;
            int duration;

            cout << "ID of Exercise to Modify: ";
            cin >> id; // NEW Customer ID�� ���� ��ȸ

            cout << "New Exercise Type: ";
            cin >> type;
            cout << "New Exercise Duration (minutes): ";
            cin >> duration;

            manager.modifyExercise(id, type, duration);
        }
        else if (choice == 3) {
            int id;
            cout << "Id of Exercise to Delete: ";
            cin >> id;
            manager.deleteExercise(id);
        }
        else if (choice == 4) {
            manager.displayExercises();
            sleep(3); 
        }
        else if (choice == 0) {
            return false;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return true; 
}

// �Ļ� ���� �޴� �Լ�
bool mealMenu(mealmanage& mealmanager, customerManager& custmanager) { // NEW �������� Ŭ���� �߰�
    int choice;
    do {
        clearConsole();
        cout << "┌─────────────────────────────┐" << endl;
        cout << "│          식단 관리          │" << endl;
        cout << "├─────────────────────────────┤" << endl;
        cout << "│                             │" << endl;
        cout << "│  [1]  입력  │  [2]  수정    │" << endl;
        cout << "│                             │" << endl;
        cout << "│  [3]  삭제  │  [4]  조회    │" << endl;
        cout << "│                             │" << endl;
        cout << "│         [0]  종료           │" << endl;
        cout << "└─────────────────────────────┘" << endl;
        cout << "┌─────────────────────────────┐" << endl;
        cout << "│  번호 입력: _               │" << endl;
        cout << "└─────────────────────────────┘" << endl;
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[14C"; // 커서를 '번호 입력: ' 위치로 이동

        cin >> choice;

        cout << "\n\n";

        if (choice == 1) {  // �Ļ� ���� �Է� �Լ� ȣ��
            int id, totalCalories;
            string name, food;

            cout << "Customer ID: ";
            cin >> id;

            // NEW Customer ID�� ���� ��ȸ
            Customer* cust = custmanager.getCustomerById(id);
            if (cust == nullptr) {
                cout << "No customer found with ID: " << id << endl;
                continue;
            }

            cout << "Food: ";
            cin >> food;
            cout << "Total Calories: ";
            cin >> totalCalories;

            // ���� ������ meal �߰�
            mealmanager.addMeal(*cust, food, totalCalories);
        } 
        else if (choice == 2) {  // �Ļ� ���� ���� �Լ� ȣ��
            int id, totalCalories;
            string food;

            cout << "ID of Meal to Modify: ";
            cin >> id; // NEW Customer ID�� ���� ��ȸ

            cout << "New Food: ";
            cin >> food;
            cout << "New Total Calories: ";
            cin >> totalCalories;

            // NEW ���� �ʵ�� ���� �����Ͽ� �ܼ�ȭ
            mealmanager.modifyMeal(id, food, totalCalories);
        }
        else if (choice == 3) { // �Ļ���� ���� �Լ� ȣ��
            int id;
            cout << "ID of Meal to Delete: ";
            cin >> id;
            mealmanager.deleteMeal(id);
        }
        else if (choice == 4) { // ����� �Ļ���� csv���� ���� ���
            mealmanager.displayMeals();
            sleep(3); //  NEW clear�Լ��� ���ؼ� ȭ���� �������Ƿ� 3�ʰ� ����ϱ� ���� sleep �Լ� �߰�
        }
        else if (choice == 0) {
            return false;  // ���� �޴��� ���ư��� ���� false ��ȯ
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return true; // NEW �޴��� ���������� ������� �ʰ� ������ ����� ��� true�� ��ȯ
}
