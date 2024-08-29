#include "layout.h"
#include <unistd.h>
#include <locale.h>

void showMainMenu() {
    cout << "\033[38;5;208m\033[48;5;18m"; // 주황색 텍스트, 진한 남색 배경

    cout << "  ███    ███  ███████  ██████     █████   " << endl;
    cout << "   ███  ███   ██       ██   ██   ██   ██  " << endl;
    cout << "    ██████    █████    ██   ██   ███████  " << endl;
    cout << "     ████     ██       ██   ██   ██   ██  " << endl;
    cout << "      ██      ███████  ██████    ██   ██  " << endl;

    cout << "\033[0m"; // 색상 초기화
    // 나머지 메뉴 부분
    cout << "\033[1;37;40m"; // 흰색 텍스트, 검정 배경
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃         WELCOME VEDA HEALTHCARE        ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃                                        ┃" << endl;
    cout << "┃             [1]  고객관리              ┃" << endl;
    cout << "┃                                        ┃" << endl;
    cout << "┃             [2]  운동관리              ┃" << endl;
    cout << "┃                                        ┃" << endl;
    cout << "┃             [3]  식단관리              ┃" << endl;
    cout << "┃                                        ┃" << endl;
    cout << "┃             [0]  종료                  ┃" << endl;
    cout << "┃                                        ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    // 번호 입력 부분을 강조
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃             번호 입력: [ _ ]           ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    
    cout << "\033[A"; // 커서를 위로 이동
    cout << "\033[A";
    cout << "\033[27C"; // 커서를 '번호 입력: ' 위치로 이동
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
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃                고객 관리                 ┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃                                          ┃" << endl;
        cout << "┃      [1]  입력      │      [2]  수정     ┃" << endl;
        cout << "┃                     │                    ┃" << endl;
        cout << "┃      [3]  삭제      │      [4]  조회     ┃" << endl;
        cout << "┃                                          ┃" << endl;
        cout << "┃                [0]  종료                 ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        // 번호 입력 부분을 강조
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃             번호 입력: [ _ ]             ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[27C"; // 커서를 '번호 입력: ' 위치로 이동


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
            cout << "잘못된 선택입니다." << endl;
        }
    } while (choice != 0); // 0�� �Է��ϸ� ���θ޴��� ���ư�.
    return true; // NEW �޴��� ���������� ������� �ʰ� ������ ����� ��� true�� ��ȯ
}

// 운동 관리 메뉴 함수
bool exerciseMenu(ExerciseManager& manager, customerManager& custmanager) {
    int choice;
    do {
        clearConsole();
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃                운동 관리                 ┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃                                          ┃" << endl;
        cout << "┃      [1]  입력      │      [2]  수정     ┃" << endl;
        cout << "┃                     │                    ┃" << endl;
        cout << "┃      [3]  삭제      │      [4]  조회     ┃" << endl;
        cout << "┃                                          ┃" << endl;
        cout << "┃                [0]  종료                 ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        // 번호 입력 부분을 강조
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃             번호 입력: [ _ ]             ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[27C"; // 커서를 '번호 입력: ' 위치로 이동

        cin >> choice;

        cout << "\n\n";

        if (choice == 1) {
            int id;
            string type;
            int duration;

            cout << "고객 ID: ";
            cin >> id;

            Customer* cust = custmanager.getCustomerById(id); 
            if (cust == nullptr) {
                cout << "해당 ID의 고객이 없습니다: " << id << endl;
                sleep(3);
                continue;
            }

            cout << "운동 유형: ";
            cin >> type;
            cout << "운동 시간 (분): ";
            cin >> duration;
            manager.addExercise(*cust, type, duration);
        }
        else if (choice == 2) {
            int id;
            string type;
            int duration;

            manager.displayAllCustomers(); // 현재 존재하는 고객 리스트 표시
            
            cout << "수정할 고객 ID: ";
            cin >> id; 
            cout << "수정할 운동 유형: ";
            cin >> type;
            cout << "수정할 운동 시간(분): ";
            cin >> duration;

            manager.modifyExercise(id, type, duration);
        }
        else if (choice == 3) {
            int id;
            string type;
            manager.displayAllCustomers();
            cout << "삭제할 고객님의 ID와 운동 유형을 입력: ";
            cin >> id >> type;
            manager.deleteExercise(id, type);
        }
        else if (choice == 4) {
            manager.displayExercises();
            sleep(3); 
        }
        else if (choice == 0) {
            return false;
        }
        else {
            cout << "잘못된 선택입니다." << endl;
        }
    } while (choice != 0);
    return true; 
}

// 식단 관리 메뉴 함수
bool mealMenu(mealmanage& mealmanager, customerManager& custmanager) {
    int choice;
    do {
        clearConsole();
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃                식단 관리                 ┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃                                          ┃" << endl;
        cout << "┃      [1]  입력      │      [2]  수정     ┃" << endl;
        cout << "┃                     │                    ┃" << endl;
        cout << "┃      [3]  삭제      │      [4]  조회     ┃" << endl;
        cout << "┃                                          ┃" << endl;
        cout << "┃                [0]  종료                 ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        // 번호 입력 부분을 강조
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃             번호 입력: [ _ ]             ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        
        cout << "\033[A"; // 커서를 위로 이동
        cout << "\033[A";
        cout << "\033[27C"; // 커서를 '번호 입력: ' 위치로 이동

        cin >> choice;

        cout << "\n\n";

        if (choice == 1) {  
            int id, totalCalories;
            string name, food;

            cout << "고객 ID: ";
            cin >> id;

            Customer* cust = custmanager.getCustomerById(id);
            if (cust == nullptr) {
                cout << "해당 ID의 고객이 없습니다: " << id << endl;sleep(2);
                continue;
            }

            cout << "음식: ";
            cin >> food;
            cout << "총 칼로리: ";
            cin >> totalCalories;

            mealmanager.addMeal(*cust, food, totalCalories);
        } 
        else if (choice == 2) { 
            int id, totalCalories;
            string food;

            cout << "수정할 식단의 고객 ID: ";
            cin >> id;

            cout << "새 음식: ";
            cin >> food;
            cout << "새 총 칼로리: ";
            cin >> totalCalories;

            mealmanager.modifyMeal(id, food, totalCalories);
        }
        else if (choice == 3) { 
            int id;
            string food;
            mealmanager.displayAllCustomers();
            cout << "삭제할 고객님의 ID와 섭취한 음식을 입력: ";
            cin >> id >> food;
            mealmanager.deleteMeal(id, food);
        }
        else if (choice == 4) { 
            mealmanager.displayMeals();
            sleep(3); 
        }
        else if (choice == 0) {
            return false;
        }
        else {
            cout << "잘못된 선택입니다." << endl;
        }
    } while (choice != 0);

    return true;
}
