#ifndef _LATOUT_H_
#define _LAYOUT_H_

#include <iostream>
#include <thread>
#include <chrono>
#include "customer_manage.h"
#include "meal_manage.h"
#include "exercise.h"

bool customerMenu(customerManager& custmanager);
bool exerciseMenu(ExerciseManager& manager, customerManager& custmanager);
bool mealMenu(mealmanage& mealmanager, customerManager& custmanager);
void showMainMenu();

void clearConsole();


#endif // _LAYOUT_H