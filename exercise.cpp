#include "exercise.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unistd.h>
#include <iomanip>
using namespace std;

// void Exercise::display() const {
//     cout << "ID: " << id << ", Name: " << name << ", Exercise Type: " << type << ", Duration: " << duration << " minutes" << endl;
// }

void ExerciseManager::loadFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << " ※ 파일을 열수 없습니다 : " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) { // getline으로 토큰 단위로 읽어들임
        stringstream ss(line);
        string idStr, name, type, durationStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, type, ',');
        getline(ss, durationStr, ',');

        if (!idStr.empty() && !name.empty() && !type.empty() && !durationStr.empty()) {
            int id = stoi(idStr);
            int duration = stoi(durationStr);
            exercises.emplace_back(id, name, type, duration);
        }
    }
    saveToCSV("exercises.csv");

    file.close();
}

void ExerciseManager::saveToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << " ※ 파일을 열수 없습니다 : " << filename << endl;
        return;
    }

    for (const auto& exercise : exercises) {
        file << exercise.id << "," << exercise.name << "," << exercise.type << "," << exercise.duration << endl;
    }

    file.close();
}

void ExerciseManager::addExercise(const Customer& cust, const string& type, int duration) {
    // 같은 ID를 가진 비어있는 운동 정보를 찾음
    auto it = find_if(exercises.begin(), exercises.end(),
                      [&cust](const Exercise& e) {
                          return e.id == cust.id && e.type.empty() && e.duration == 0;
                      });
    
    if (it != exercises.end()) {
        // 비어있는 운동 정보를 찾았다면, 그 자리에 새 정보를 덮어씀
        it->type = type;
        it->duration = duration;
        cout << "--------------------------------------------------------" << endl;
        cout << " ▷ ID " << cust.id << "번 고객님 운동 정보를 업데이트했습니다." << endl;sleep(2);
    } else {
        // 비어있는 운동 정보가 없다면, 새로운 Exercise 객체를 추가
        exercises.emplace_back(cust.id, cust.name, type, duration);
        cout << "--------------------------------------------------------" << endl;
        cout << " ▷ ID " << cust.id << "번 고객님 새로운 운동 정보를 추가했습니다." << endl;sleep(2);
    }

    saveToCSV("exercises.csv");
}

void ExerciseManager::modifyExercise(int id, const string& type,int duration) {
    for (auto& e : exercises) {
        if (e.id == id) {
            e.type = type;               
            e.duration = duration; 
            cout << "--------------------------------------------------------" << endl;
            cout << " ▷ 수정 완료 되었습니다."<< endl;sleep(2);
            return;
        }
    }
    sleep(2);
    saveToCSV("exercises.csv");
}

void ExerciseManager::deleteExercise(int id, const string& type) {

    auto it = find_if(exercises.begin(), exercises.end(),
                      [id, &type](const Exercise& e) {
                          return e.id == id && e.type == type;
                      });

    if (it != exercises.end()) {
        it->type.clear();  // 운동 유형을 빈 문자열로 초기화
        it->duration = 0;  // 운동 시간을 0으로 초기화
        cout << "--------------------------------------------------------" << endl;
        cout << " ▷ ID " << id << " 번 고객님의 '" << type << "' 운동 정보가 삭제돼었습니다." << endl;
        saveToCSV("exercises.csv");
        sleep(2);
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << " ▷ ID " << id << " 번 고객님의 '" << type << "' 운동 정보를 찾았습니다." << endl;sleep(2);
    }
}


// void ExerciseManager::displayExercises() const {
//     bool hasExercises = false;
//     for (const auto& exercise : exercises) {
//         if (!exercise.type.empty() && exercise.duration > 0) {
//             cout << "ID: " << exercise.id << "| 이름: " << exercise.name 
//                  << "| 운동 유형: " << exercise.type 
//                  << "| 운동 시간: " << exercise.duration << " 분" << endl;
//             hasExercises = true;
//         }
//     }
//     if (!hasExercises) {
//         cout << "표시할 운동 기록이 없음." << endl;
//     } else {
//         cout << "총 " << count_if(exercises.begin(), exercises.end(), 
//                                  [](const Exercise& e) { return !e.type.empty() && e.duration > 0; })
//              << "개의 운동 기록이 표시되었음." << endl;
//     }
// }
void ExerciseManager::displayExercises() const {
    bool hasExercises = false;
    
    // 헤더 출력
    cout << left << setw(5) << "ID" 
         << setw(17) << "이름" 
         << setw(20) << "운동 유형" 
         << setw(10) << "운동 시간" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (const auto& exercise : exercises) {
        if (!exercise.type.empty() && exercise.duration > 0) {
            cout << left << setw(5) << exercise.id 
                 << setw(15) << exercise.name 
                 << setw(15) << exercise.type 
                 << setw(7) << exercise.duration << " 분" << endl;
            hasExercises = true;
        }
    }
    
    if (!hasExercises) {
        cout << "--------------------------------------------------------" << endl;
        cout << " ▷ 표시할 운동 기록이 없음." << endl;sleep(2);
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << " ▷ 총 " << count_if(exercises.begin(), exercises.end(), 
                                 [](const Exercise& e) { return !e.type.empty() && e.duration > 0; })
             << "개의 운동 기록이 표시되었음." << endl;sleep(2);
    }
}

// void ExerciseManager::displayAllCustomers() const {
//     // 고객 정보가 있는지 확인
//     if (exercises.empty()) {
//         cout << "저장된 고객 정보가 없습니다." << endl;
//         return;
//     }

//     // 고객 목록 출력
//     cout << "현재 저장된 고객 목록:" << endl;
//     for (const auto& exercise : exercises) {
//         cout << "ID: " << exercise.id << "| 이름: " << exercise.name 
//         <<  "| 운동 유형: " << exercise.type << " | 운동 시간: " << exercise.duration << " 분" << "\n\n";
//     }
// }
void ExerciseManager::displayAllCustomers() const {
    // 고객 정보가 있는지 확인
    if (exercises.empty()) {
        cout << " -- 저장된 고객 정보가 없습니다." << endl;
        return;
    }

    // 헤더 출력
    cout << left << setw(5) << "ID" 
         << setw(17) << "이름" 
         << setw(20) << "운동 유형" 
         << setw(10) << "운동 시간" << endl;
    cout << "--------------------------------------------------------" << endl;

    // 고객 목록 출력
    for (const auto& exercise : exercises) {
        cout << left << setw(5) << exercise.id 
             << setw(15) << exercise.name 
             << setw(15) << exercise.type 
             << setw(7) << exercise.duration << " 분" << "\n\n";
    }
}

const vector<Exercise>& ExerciseManager::getExercisesByType(const string& type) const {
    static const vector<Exercise> emptyVector;
    auto it = exercisesByType.find(type);

    if (it != exercisesByType.end()) {
        return it->second;
    }
    else {
        return emptyVector;
    }
}
