/**
 - @file main.cpp
 - @brief entry point for the flux systems engine.
 */

#include "../../include/core/registration.h"
#include "../../include/core/login.h"
#include "../../include/auth/menu_handler.h"
#include <iostream>

int main() {
    // welcome message for the flux systems engine
    std::cout << "WELCOME TO FLUX SYSTEMS ENGINE\n\n";

    // handles user registration logic
    std::cout << "Please register your account.\n";
    registerUser();

    // loops login until authentication is successful
    bool authenticated = false;
    while (!authenticated) {
        authenticated = loginUser();
    }

    // launches the main menu for tracker selection
    chooseTracker();

    return 0;
}