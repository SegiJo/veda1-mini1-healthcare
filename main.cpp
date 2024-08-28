#include <iostream>
#include "customer_manage.h" // 고객관리 담당 클래스
#include "meal_manage.h" // 식사관리 담당 클래스
#include "exercise.h" // 운동관리 담당 클래스

#include "layout.h"
#include <unistd.h>

using namespace std;

/*
    메인 함수의 초기 메뉴 출력 부분도 함수로 따로 빼서 작성할 예정
*/

int main() {

    int main_num;

    string meal_filename = "meal.csv";
    string exercise_filename = "exercises.csv";

    //-------고객--------------------------------
    customerManager custmanager;    // 고객 관리 객체 생성
    string cust_filename = "customers.csv";
    custmanager.loadFromCSV(cust_filename);     // 기존 CSV파일에서 고객 정보 불러오기

    mealmanage mealmanager;
    mealmanager.loadFromCSV(meal_filename);

    ExerciseManager exerciseManager;
    exerciseManager.loadFromCSV(exercise_filename);

//---------------------------------------
    do {
        clearConsole();  // 콘솔 화면 지우기
        showMainMenu();
        cin >> main_num;

        if (main_num == 1) { // 고객관리 저장 내용 출력
            customerMenu(custmanager);
        }

        // 메인 메뉴에 운동 관리 옵션 추가
        else if (main_num == 2) {
            if (!exerciseMenu(exerciseManager,custmanager)) {
                continue;
            }
        }

        else if (main_num == 3) { // 식사관리 레이아웃 함수를 출력

            if (!mealMenu(mealmanager,custmanager)) { // 240808 false값이 들어올 시 다시 돌아와 continue 수행
                continue;  // 240808 메인 메뉴로 돌아가기
            }
        }
        else if (main_num != 0) {
            cout << "\n             ※ 잘못된번호 ※" << endl;
            //this_thread::sleep_for(chrono::seconds(1)); VSCODE에서 작동 X
            sleep(1); // 대체로 sleep 사용
        }

    } while (main_num != 0); // 240808 반복적으로 표시하고 0을 입력시 종료를 위해 do-while문 사용 

    custmanager.saveToCSV(cust_filename); // 입력 및 수정한 내용 저장
    exerciseManager.saveToCSV(exercise_filename);
    mealmanager.saveToCSV(meal_filename); // 입력 및 수정한 내용 저장

    clearConsole();
    cout << "Exiting the healthcare program. Thank you for using it." << endl;
    return 0;
}
