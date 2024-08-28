#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>

using namespace std;

class meal { // 식사관리 클래스
public:
    int id;
    string name;
    string food;
    int totalCalories;

    meal(int id, string name, string food, int totalCalories)
        : id(id), name(name), food(food), totalCalories(totalCalories) {}

    void display() const { // 출력 함수
        cout << "ID: " << id << ", Name: " << name << ", Food: " << food << ", Total Calories: " << totalCalories << endl;
    }
};

#endif // !MEAL_H
