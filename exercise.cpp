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

void ExerciseManager::addExercise(const Customer& cust,const string& type, int duration) {
    exercises.emplace_back(cust.id,cust.name,type,duration);
    saveToCSV("exercises.csv");
}

void ExerciseManager::modifyExercise(int id, const string& type,int duration) {
    for (auto& m : exercises) {
        if (m.id == id) {
            m.type = type;               // food 수정
            m.duration = duration; // totalCalories 수정
            return;
        }
    }
    cout << "No meal found with ID: " << id << endl;
    saveToCSV("exercises.csv");
}

void ExerciseManager::deleteExercise(int id) {
    exercises.erase(remove_if(exercises.begin(), exercises.end(), [id](const Exercise& m) { return m.id == id; }), exercises.end());
    saveToCSV("exercises.csv");
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
