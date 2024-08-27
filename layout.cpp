#include "layout.h"
#include <unistd.h>

void showMainMenu() {
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*      헬스케어에 오신걸 환영합니다      *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*          1. 고객관리                   *" << endl;
    cout << "*          2. 운동관리                   *" << endl;
    cout << "*          3. 식단관리                   *" << endl;
    cout << "*          0. Exit Program               *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << "                   옵션을 선택하세요:   ";
}

//콘솔 화면을 지우는 함수
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//고객 관리 메뉴를 출력하고, 사용자의 선택에 따라 적절한 작업을 수행하는 함수
bool customerMenu(customerManager& custmanager) {

    int choice; // 메뉴 선택할 번호
    do {
        clearConsole();
        cout << "\n\n ▷▷▷▷ Customer Management ◁◁◁◁" << endl;
        cout << "   1. Add Customer" << endl;
        cout << "   2. Modify Customer Information" << endl;
        cout << "   3. Delete Customer" << endl;
        cout << "   4. View Customer" << endl;
        cout << "   0. Return to Main Menu" << endl;
        cout << "            >> Choice: ";
        cin >> choice;

        if (choice == 1) { // 1. 고객 추가
            custmanager.addCustomer();
        }
        else if (choice == 2) { // 2. 고객 정보 수정
            custmanager.modifyCustomer();
        }
        else if (choice == 3) { // 3. 고객 삭제
            custmanager.deleteCustomer();
        }
        else if (choice == 4) { // 4. 고객 조회
            custmanager.viewCustomer();
        }
        else if (choice == 0) { // main으로 돌아가기
            return false;
        }
        else {
            cout << "Invalid choice entered." << endl;
        }
    } while (choice != 0); // 0을 입력하면 메인메뉴로 돌아감.
    return true; // NEW 메뉴가 정상적으로 종료되지 않고 루프가 종료된 경우 true를 반환
}

// 운동 관리 메뉴 함수
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
            cin >> id; // NEW Customer ID로 고객 조회

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
            sleep(3); //  NEW clear함수로 인해서 화면이 지워지므로 3초간 출력하기 위해 sleep 함수 추가
        }
        else if (choice == 0) {
            return false;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return true; // NEW 메뉴가 정상적으로 종료되지 않고 루프가 종료된 경우 true를 반환
}

// 식사 관리 메뉴 함수
bool mealMenu(mealmanage& mealmanager, customerManager& custmanager) { // NEW 고객관리 클래스 추가
    int choice;
    do {
        clearConsole();
        cout << "\n*** Meal Management ***" << endl;
        cout << "1. Add Meal" << endl;
        cout << "2. Modify Meal" << endl;
        cout << "3. Delete Meal" << endl;
        cout << "4. Display Meals" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {  // 식사 관리 입력 함수 호출
            int id, totalCalories;
            string name, food;

            cout << "Customer ID: ";
            cin >> id;

            // NEW Customer ID로 고객 조회
            Customer* cust = custmanager.getCustomerById(id);
            if (cust == nullptr) {
                cout << "No customer found with ID: " << id << endl;
                continue;
            }

            cout << "Food: ";
            cin >> food;
            cout << "Total Calories: ";
            cin >> totalCalories;

            // 고객 정보로 meal 추가
            mealmanager.addMeal(*cust, food, totalCalories);
        } 
        else if (choice == 2) {  // 식사 관리 수정 함수 호출
            int id, totalCalories;
            string food;

            cout << "ID of Meal to Modify: ";
            cin >> id; // NEW Customer ID로 고객 조회

            cout << "New Food: ";
            cin >> food;
            cout << "New Total Calories: ";
            cin >> totalCalories;

            // NEW 개별 필드로 직접 전달하여 단순화
            mealmanager.modifyMeal(id, food, totalCalories);
        }
        else if (choice == 3) { // 식사관리 삭제 함수 호출
            int id;
            cout << "ID of Meal to Delete: ";
            cin >> id;
            mealmanager.deleteMeal(id);
        }
        else if (choice == 4) { // 저장된 식사관리 csv파일 내용 출력
            mealmanager.displayMeals();
            sleep(3); //  NEW clear함수로 인해서 화면이 지워지므로 3초간 출력하기 위해 sleep 함수 추가
        }
        else if (choice == 0) {
            return false;  // 메인 메뉴로 돌아가기 위해 false 반환
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return true; // NEW 메뉴가 정상적으로 종료되지 않고 루프가 종료된 경우 true를 반환
}
