#include "exercise.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unistd.h>

using namespace std;

void Exercise::display() const {
    cout << "ID: " << id << ", Name: " << name << ", Exercise Type: " << type << ", Duration: " << duration << " minutes" << endl;
}

void ExerciseManager::loadFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
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
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    for (const auto& exercise : exercises) {
        file << exercise.id << "," << exercise.name << "," << exercise.type << "," << exercise.duration << endl;
    }

    file.close();
}

// void ExerciseManager::addExercise(const Customer& cust,const string& type, int duration) {
//     exercises.emplace_back(cust.id,cust.name,type,duration);
//     saveToCSV("exercises.csv");
// }

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
        cout << "ID " << cust.id << "운동 정보를 업데이트함." << endl;
    } else {
        // 비어있는 운동 정보가 없다면, 새로운 Exercise 객체를 추가
        exercises.emplace_back(cust.id, cust.name, type, duration);
        cout << "ID " << cust.id << "에 새로운 운동 정보를 추가함." << endl;
    }

    saveToCSV("exercises.csv");
    sleep(2);
}

void ExerciseManager::modifyExercise(int id, const string& type,int duration) {
    for (auto& m : exercises) {
        if (m.id == id) {
            m.type = type;               
            m.duration = duration; 
            return;
        }
    }
    cout << "No exercises found with ID: " << id << endl;
    saveToCSV("exercises.csv");
}

void ExerciseManager::deleteExercise(int id) {
    for (auto& exercise : exercises) {
        if (exercise.id == id) {
            exercise.type.clear();  // 운동 유형을 빈 문자열로 clear
            exercise.duration = 0;  // int형은 clear()함수가 안됨. 운동 시간을 0으로 초기화

            cout << id << "번 고객님의 운동 정보가 삭제됨." << endl;
            sleep(3);
            break;
        }
    }
    
    saveToCSV("exercises.csv");

    // 이전 코드
    //exercises.erase(remove_if(exercises.begin(), exercises.end(), [id](const Exercise& m) { return m.id == id; }), exercises.end());
    //saveToCSV("exercises.csv");
}

void ExerciseManager::displayExercises() const {
    for (const auto& exercise : exercises) {
        exercise.display();
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
