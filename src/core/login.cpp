/**
 - @file login.cpp
 - @brief implementation of the user login system.
 */

#include "../../include/core/login.h"
#include "../../include/auth/user_info.h"
#include <iostream>
#include <string>
#include <conio.h>

extern UserInfo newUser;

bool loginUser() {
    std::string inputUser, inputPass;
    char ch;

    std::cout << "\n<--------- USER LOGIN --------->\n";
    std::cout << "- Username: ";
    std::cin >> inputUser;

    std::cout << "- Password: ";
    // masking the password input with asterisks
    while ((ch = _getch()) != 13) {
        if (ch == 8) {
            if (!inputPass.empty()) {
                inputPass.pop_back();
                std::cout << "\b \b";
            }
        } else {
            inputPass.push_back(ch);
            std::cout << "*";
        }
    }
    std::cout << std::endl;

    // verifies if credentials match the registered user
    if (inputUser == newUser.getUsername() && inputPass == newUser.getPassword()) {
        std::cout << "\nSUCCESS: Welcome back, " << newUser.getFirstName() << "!\n";
        return true;
    } else {
        std::cout << "\nERROR: Invalid username or password.\n";
        return false;
    }
}