#include <iostream>
#include "customer_manage.h" // ������ ��� Ŭ����
#include "meal_manage.h" // �Ļ���� ��� Ŭ����
#include "exercise.h" // ����� ��� Ŭ����

#include "layout.h"
#include <unistd.h>

using namespace std;

/*
    ���� �Լ��� �ʱ� �޴� ��� �κе� �Լ��� ���� ���� �ۼ��� ����
*/

int main() {

    int main_num;

    string meal_filename = "meal.csv";
    string exercise_filename = "exercises.csv";

    //-------��--------------------------------
    customerManager custmanager;    // �� ���� ��ü ����
    string cust_filename = "customers.csv";
    custmanager.loadFromCSV(cust_filename);     // ���� CSV���Ͽ��� �� ���� �ҷ�����

    mealmanage mealmanager;
    mealmanager.loadFromCSV(meal_filename);

    ExerciseManager exerciseManager;
    exerciseManager.loadFromCSV(exercise_filename);

//---------------------------------------
    do {
        clearConsole();  // �ܼ� ȭ�� �����
        showMainMenu();
        cin >> main_num;

        if (main_num == 1) { // ������ ���� ���� ���
            customerMenu(custmanager);
        }

        // ���� �޴��� � ���� �ɼ� �߰�
        else if (main_num == 2) {
            if (!exerciseMenu(exerciseManager,custmanager)) {
                continue;
            }
        }

        else if (main_num == 3) { // �Ļ���� ���̾ƿ� �Լ��� ���

            if (!mealMenu(mealmanager,custmanager)) { // 240808 false���� ���� �� �ٽ� ���ƿ� continue ����
                continue;  // 240808 ���� �޴��� ���ư���
            }
        }
        else if (main_num != 0) {
            cout << "\n             �� �߸��ȹ�ȣ ��" << endl;
            //this_thread::sleep_for(chrono::seconds(1)); VSCODE���� �۵� X
            sleep(1); // ��ü�� sleep ���
        }

    } while (main_num != 0); // 240808 �ݺ������� ǥ���ϰ� 0�� �Է½� ���Ḧ ���� do-while�� ��� 

    custmanager.saveToCSV(cust_filename); // �Է� �� ������ ���� ����
    exerciseManager.saveToCSV(exercise_filename);
    mealmanager.saveToCSV(meal_filename); // �Է� �� ������ ���� ����

    clearConsole();
    cout << "Exiting the healthcare program. Thank you for using it." << endl;
    return 0;
}
