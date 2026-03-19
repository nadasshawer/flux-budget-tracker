#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

/**
 - @file text_utils.h
 - @brief Utility functions for string manipulation and text formatting.
          Contains tools for styling user input and preparing strings 
          for display in the UI.
 */

#include <string>

/**
 - @brief Capitalizes the first character of a string.
 - @param name: The string to be formatted.
 - @return std::string: The string with the first letter in uppercase.
           Example: "salary" -> "Salary".
 */
std::string capitalizeFirstLetter(std::string name);

#endif