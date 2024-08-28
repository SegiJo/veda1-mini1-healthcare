#include "meal_manage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void mealmanage::loadFromCSV(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "파일을 열 수 없습니다: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) { // getline으로 토큰 단위로 읽어들임
        stringstream ss(line);
        string idStr, name, food, totalCaloriesStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, food, ',');
        getline(ss, totalCaloriesStr, ',');

        if (!idStr.empty() && !name.empty() && !food.empty() && !totalCaloriesStr.empty()) {
            int id = stoi(idStr);
            int totalCalories = stoi(totalCaloriesStr);
            meals.emplace_back(id, name, food, totalCalories);
        }
    }

    file.close();
}

void mealmanage::saveToCSV(const string& filename) { // 변경 내용 저장
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "파일을 열 수 없습니다: " << filename << endl;
        return;
    }

    for (const auto& meal : meals) {
        file << meal.id << "," << meal.name << "," << meal.food << "," << meal.totalCalories << endl;
    }

    file.close();
}

void mealmanage::addMeal(const Customer& cust, const string& food, int totalCalories) {
    // customer의 id와 name을 이용하여 meal 생성
    meals.emplace_back(cust.id, cust.name, food, totalCalories);
}

void mealmanage::modifyMeal(int id, const string& food, int totalCalories) {
    for (auto& m : meals) {
        if (m.id == id) {
            m.food = food;               // food 수정
            m.totalCalories = totalCalories; // totalCalories 수정
            return;
        }
    }
    cout << "No meal found with ID: " << id << endl;
}

void mealmanage::deleteMeal(int id) { // 식사관리 삭제 기능
    meals.erase(remove_if(meals.begin(), meals.end(), [id](const meal& m) { return m.id == id; }), meals.end());
}

void mealmanage::displayMeals() const { // csv에 저장되어있는 값 출력
    for (const auto& meal : meals) {
        meal.display();
    }
}
