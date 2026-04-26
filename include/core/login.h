#ifndef LOGIN_H
#define LOGIN_H

/**
 - @file login.h
 - @brief logic for authenticating existing users.
 - @details validates credentials against the userinfo model to allow access.
 */

/**
 - @brief handles the login process including username and password validation.
 - @return bool: returns true if login is successful.
 */
bool loginUser();

#endif