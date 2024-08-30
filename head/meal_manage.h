#ifndef MEAL_MANAGER_H
#define MEAL_MANAGER_H

#include <vector>
#include <string>
#include "meal.h"
#include "customer.h" // NEW 고객 헤더 추가

using namespace std;

class mealmanage {
public:
    vector<meal> meals; 

    void loadFromCSV(const string& filename);
    void saveToCSV(const string& filename);
    void addMeal(const Customer& cust, const string& food, int totalCalories); // NEW id 기준으로 food와 totalCalories 입력
    void modifyMeal(int id, const string& food, int totalCalories); // id 기준으로 food와 totalCalories만 수정
    void deleteMeal(int id, const string& food);   

    void displayAllCustomers() const;

    void displayMeals() const;
};

#endif // !MEAL_MANAGER_H
