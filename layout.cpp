#include "layout.h"
#include <unistd.h>

void showMainMenu() {
        cout << "  ###     ###  #######  #####    #####   " << endl;
        cout << "   ###   ###   ##       ##  ##   ##  ##  " << endl;
        cout << "    ### ###    #####    ##   ##  ####### " << endl;
        cout << "     #####     ##       ##   ##  ##   ## " << endl;
        cout << "      ###      #######  #####    ##   ## " << endl;
        cout << "\n";
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢   WELCOME VEDA HEALTHCARE   ¦¢" << endl;
        cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [1]  °í°´  ¦¢  [2]  ¿îµ¿    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [3]  »èÁ¦  ¦¢  [4]  Á¶È¸    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢         [0]  Á¾·á           ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢  ¹øÈ£ ÀÔ·Â: _               ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "\033[A"; // Ä¿¼­¸¦ À§·Î ÀÌµ¿
        cout << "\033[A";
        cout << "\033[14C"; // Ä¿¼­¸¦ '¹øÈ£ ÀÔ·Â: ' À§Ä¡·Î ÀÌµ¿
}

//ÄÜ¼Ö È­¸éÀ» Áö¿ì´Â ÇÔ¼ö
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//°í°´ °ü¸® ¸Þ´º¸¦ Ãâ·ÂÇÏ°í, »ç¿ëÀÚÀÇ ¼±ÅÃ¿¡ µû¶ó ÀûÀýÇÑ ÀÛ¾÷À» ¼öÇàÇÏ´Â ÇÔ¼ö
bool customerMenu(customerManager& custmanager) {

    int choice; // ¸Þ´º ¼±ÅÃÇÒ ¹øÈ£
    do {
        clearConsole();
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢          °í°´ °ü¸®          ¦¢" << endl;
        cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [1]  ÀÔ·Â  ¦¢  [2]  ¼öÁ¤    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [3]  »èÁ¦  ¦¢  [4]  Á¶È¸    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢         [0]  Á¾·á           ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢  ¹øÈ£ ÀÔ·Â: _               ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "\033[A"; // Ä¿¼­¸¦ À§·Î ÀÌµ¿
        cout << "\033[A";
        cout << "\033[14C"; // Ä¿¼­¸¦ '¹øÈ£ ÀÔ·Â: ' À§Ä¡·Î ÀÌµ¿

        cin >> choice;

        cout << "\n\n";

        if (choice == 1) { // 1. °í°´ Ãß°¡
            custmanager.addCustomer();
        }
        else if (choice == 2) { // 2. °í°´ Á¤º¸ ¼öÁ¤
            custmanager.modifyCustomer();
        }
        else if (choice == 3) { // 3. °í°´ »èÁ¦
            custmanager.deleteCustomer();
        }
        else if (choice == 4) { // 4. °í°´ Á¶È¸
            custmanager.viewCustomer();
        }
        else if (choice == 0) { // mainÀ¸·Î µ¹¾Æ°¡±â
            return false;
        }
        else {
            cout << "Invalid choice entered." << endl;
        }
    } while (choice != 0); // 0À» ÀÔ·ÂÇÏ¸é ¸ÞÀÎ¸Þ´º·Î µ¹¾Æ°¨.
    return true; // NEW ¸Þ´º°¡ Á¤»óÀûÀ¸·Î Á¾·áµÇÁö ¾Ê°í ·çÇÁ°¡ Á¾·áµÈ °æ¿ì true¸¦ ¹ÝÈ¯
}

// ¿îµ¿ °ü¸® ¸Þ´º ÇÔ¼ö
bool exerciseMenu(ExerciseManager& manager, customerManager& custmanager) {
    int choice;
    do {
        clearConsole();
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢          ¿îµ¿ °ü¸®          ¦¢" << endl;
        cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [1]  ÀÔ·Â  ¦¢  [2]  ¼öÁ¤    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [3]  »èÁ¦  ¦¢  [4]  Á¶È¸    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢         [0]  Á¾·á           ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢  ¹øÈ£ ÀÔ·Â: _               ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "\033[A"; // Ä¿¼­¸¦ À§·Î ÀÌµ¿
        cout << "\033[A";
        cout << "\033[14C"; // Ä¿¼­¸¦ '¹øÈ£ ÀÔ·Â: ' À§Ä¡·Î ÀÌµ¿

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
            cin >> id; // NEW Customer ID·Î °í°´ Á¶È¸

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
            sleep(3); //  NEW clearÇÔ¼ö·Î ÀÎÇØ¼­ È­¸éÀÌ Áö¿öÁö¹Ç·Î 3ÃÊ°£ Ãâ·ÂÇÏ±â À§ÇØ sleep ÇÔ¼ö Ãß°¡
        }
        else if (choice == 0) {
            return false;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return true; // NEW ¸Þ´º°¡ Á¤»óÀûÀ¸·Î Á¾·áµÇÁö ¾Ê°í ·çÇÁ°¡ Á¾·áµÈ °æ¿ì true¸¦ ¹ÝÈ¯
}

// ½Ä»ç °ü¸® ¸Þ´º ÇÔ¼ö
bool mealMenu(mealmanage& mealmanager, customerManager& custmanager) { // NEW °í°´°ü¸® Å¬·¡½º Ãß°¡
    int choice;
    do {
        clearConsole();
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢          ½Ä´Ü °ü¸®          ¦¢" << endl;
        cout << "¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [1]  ÀÔ·Â  ¦¢  [2]  ¼öÁ¤    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢  [3]  »èÁ¦  ¦¢  [4]  Á¶È¸    ¦¢" << endl;
        cout << "¦¢                             ¦¢" << endl;
        cout << "¦¢         [0]  Á¾·á           ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
        cout << "¦¢  ¹øÈ£ ÀÔ·Â: _               ¦¢" << endl;
        cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
        cout << "\033[A"; // Ä¿¼­¸¦ À§·Î ÀÌµ¿
        cout << "\033[A";
        cout << "\033[14C"; // Ä¿¼­¸¦ '¹øÈ£ ÀÔ·Â: ' À§Ä¡·Î ÀÌµ¿

        cin >> choice;

        cout << "\n\n";

        if (choice == 1) {  // ½Ä»ç °ü¸® ÀÔ·Â ÇÔ¼ö È£Ãâ
            int id, totalCalories;
            string name, food;

            cout << "Customer ID: ";
            cin >> id;

            // NEW Customer ID·Î °í°´ Á¶È¸
            Customer* cust = custmanager.getCustomerById(id);
            if (cust == nullptr) {
                cout << "No customer found with ID: " << id << endl;
                continue;
            }

            cout << "Food: ";
            cin >> food;
            cout << "Total Calories: ";
            cin >> totalCalories;

            // °í°´ Á¤º¸·Î meal Ãß°¡
            mealmanager.addMeal(*cust, food, totalCalories);
        } 
        else if (choice == 2) {  // ½Ä»ç °ü¸® ¼öÁ¤ ÇÔ¼ö È£Ãâ
            int id, totalCalories;
            string food;

            cout << "ID of Meal to Modify: ";
            cin >> id; // NEW Customer ID·Î °í°´ Á¶È¸

            cout << "New Food: ";
            cin >> food;
            cout << "New Total Calories: ";
            cin >> totalCalories;

            // NEW °³º° ÇÊµå·Î Á÷Á¢ Àü´ÞÇÏ¿© ´Ü¼øÈ­
            mealmanager.modifyMeal(id, food, totalCalories);
        }
        else if (choice == 3) { // ½Ä»ç°ü¸® »èÁ¦ ÇÔ¼ö È£Ãâ
            int id;
            cout << "ID of Meal to Delete: ";
            cin >> id;
            mealmanager.deleteMeal(id);
        }
        else if (choice == 4) { // ÀúÀåµÈ ½Ä»ç°ü¸® csvÆÄÀÏ ³»¿ë Ãâ·Â
            mealmanager.displayMeals();
            sleep(3); //  NEW clearÇÔ¼ö·Î ÀÎÇØ¼­ È­¸éÀÌ Áö¿öÁö¹Ç·Î 3ÃÊ°£ Ãâ·ÂÇÏ±â À§ÇØ sleep ÇÔ¼ö Ãß°¡
        }
        else if (choice == 0) {
            return false;  // ¸ÞÀÎ ¸Þ´º·Î µ¹¾Æ°¡±â À§ÇØ false ¹ÝÈ¯
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return true; // NEW ¸Þ´º°¡ Á¤»óÀûÀ¸·Î Á¾·áµÇÁö ¾Ê°í ·çÇÁ°¡ Á¾·áµÈ °æ¿ì true¸¦ ¹ÝÈ¯
}
