/**
  * @purpose Utility functions for Vignere encryption implementation
  *
  * @author  Ashish
  * @license MIT license
  * @version 1.0, Doxygen compatible comments
  */

#include <iostream>
#include <string>
#include "vignere_util.h"

/** \brief function to convert only lowercase to uppercase 
  * \param src - the string to be converted
  * \return the uppercase converted string
  */
std::string uppercase_form_of(const std::string& src) {
    std::string dest;
    for (int i = 0; src[i] != 0 ; i++) {
        char c = src[i];
        dest += (c >= 'a' && c <= 'z') ? 'A' + (c - 'a') : c;
    }
    return dest;
}

/** \brief check if the string contains only alphabets 
  * \param str - the string to be validated
  * \return true or false - if its valid or not
  */
bool is_only_alphabets_in(const std::string& str) {
    bool rc = true;
    for (int i = 0; str[i] != 0 ; i++) {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        } else {
            rc = false;
            break;
        }
    }
    return rc;
}

/** \brief return the row in row header, corresponding to the character given
  * \param given_char - a character in English Alphabet
  * \return the row number in row header, in tabula recta
  */
int row_of(char given_char) {
 return given_char - 'A';
}

/** \brief return the column in column header, corresponding to the character given
  * \param given_char - a character in English Alphabet
  * \return the column number in column header, in tabula recta
  */
int column_of(char given_char) {
	return given_char - 'A';
}

/** \brief return the alphabet corresponding to the given column in column header 
  * \param given_column - a number representing the column in tabula recta
  * \return the alphabet for the given column in column header, in tabula recta
  */
char alphabet_at(int given_column) {
	return 'A' + given_column;
}

