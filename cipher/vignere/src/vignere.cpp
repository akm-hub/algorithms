/**
  * @purpose Vignere encryption implementation, based on tabula recta
  *
  * @author  Ashish
  * @license MIT license
  * @version 1.0, Doxygen compatible comments
  */

#include <iostream>
#include <string>
#include <cassert>
#include "vignere.h"
#include "vignere_util.h"

/** \brief parametrized constructor for initing the class
  * \param given_key - a string containing the passphrase text
  * \return none
  */
Vignere::Vignere(const std::string given_key) {
    set_key(given_key);
    std::string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int row = 0; row < MAX_ALPHABETS; row++) {
        for (int column = 0, index_in_alphabets = row; 
				column < MAX_ALPHABETS;
				column++, index_in_alphabets++) {
            tabula_recta_[row][column] = alphabets[index_in_alphabets % MAX_ALPHABETS];
        }
    }
}

/** \brief sets key_ member to a given string, after checks
  * \param t - the key string
  * \return void
  */
void Vignere::set_key(const std::string& t) {
    assert(!t.empty());
    assert(is_only_alphabets_in(t));
    key_ = uppercase_form_of(t);
}

/** \brief accessor for key_ memeber variable
  * \param void
  * \return key_ string
  */
std::string Vignere::key(void) {
    return key_;
}

/** \brief Encrypt the given string
  * \param given_cleartext - the cleartext
  * \return a string containing the ciphertext
  */
std::string Vignere::encrypt(const std::string& given_cleartext) {
    if (!is_only_alphabets_in(given_cleartext)) {
        return std::string();
    }
	
    std::string ciphertext;
    std::string cleartext = uppercase_form_of(given_cleartext);
    for (int index = 0, key_pos = 0; cleartext[index] != 0; index++) {
		int row = row_of(cleartext[index]);
		int	column = column_of(key_[key_pos]);			
		ciphertext += tabula_recta_[row][column];
		key_pos++;
        key_pos %= key_.size();
    }
    return ciphertext;
}

/** \brief Decrypt the given string
  * \param given_ciphertext - the ciphertext
  * \return a string containing the cleartext
  */
std::string Vignere::decrypt(const std::string& given_ciphertext) {
    if (!is_only_alphabets_in(given_ciphertext)) {
        return std::string();
    }
	
    std::string ciphertext = uppercase_form_of(given_ciphertext);
    std::string cleartext;
    for (int index = 0, key_pos = 0; ciphertext[index] != 0; index++) {
        int identified_column = INVALID_COLUMN; 
		int row = row_of(key_[key_pos]);
        for (int column = 0; column < MAX_ALPHABETS; column++) {
			if (tabula_recta_[row][column] == ciphertext[index]) {
				identified_column = column;
				break;
			}
		}
		cleartext += alphabet_at(identified_column);
		key_pos++;
        key_pos %= key_.size();
    }
    return cleartext;
}
