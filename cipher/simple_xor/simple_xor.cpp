/**
  * @purpose Simple XOR encryption implementation
  *
  * @author  Ashish
  * @license MIT license
  * @version 1.0, Doxygen compatible comments
  */
#include <iostream>
#include <string>
using namespace std;

class SimpleXOR {
 private:
 	string key_;
 public:
 	explicit SimpleXOR(const string&);
 	void set_key(const string&);
 	void set_key(const char*);
 	string key(void);
 	string xor_key_with(const string&);
 	string encrypt(const string&);
 	string decrypt(const string&);
};

/** \brief parametrized constructor for initing the class
  * \param given_key - a string containing the passphrase text
  * \return none
  */
SimpleXOR::SimpleXOR(const string& key) : key_(key) {
}

/** \brief setter for key_ private member variable
  * \param key - a string containing the passphrase text
  * \return none
  */
void SimpleXOR::set_key(const string& given_key) {
	key_ = given_key;
}

/** \brief another setter for key_ private member variable
  * \param key - a c-style string containing the passphrase text
  * \return none
  */
void SimpleXOR::set_key(const char* given_key) {
	key_ = given_key;
}

/** \brief accessor for the key
  * \param none
  * \return string in key_ member variable in the class
  */
string SimpleXOR::key(void) {
	return key_;
}

/** \brief do XOR of key with the given string
  * \param input - a string that needs to be XORed with key
  * \return the final XORed string
  */
string SimpleXOR::xor_key_with(const string& input) {
	string output;
	int key_length = key_.length();
	for (int index = 0; input[index] != 0; index++) {
		output += input[index] ^ key_[index % key_length];
	}
	return output;
}

/** \brief encrypt the message
  * \param given_cleartext - the cleartext string
  * \return the ciphertext string
  */
string SimpleXOR::encrypt(const string& given_cleartext) {
	return xor_key_with(given_cleartext);
}

/** \brief decrypt the message
  * \param given_ciphertext - the ciphertext string
  * \return cleartext string
  */
string SimpleXOR::decrypt(const string& given_ciphertext) {
	return xor_key_with(given_ciphertext);
}


int main(int argc, const char * argv[])
{
	SimpleXOR simple_xor("HELLO, WORLD");
    string ciphertext = simple_xor.encrypt("www.github.com");
    cout << "Ciphertext = " << ciphertext << endl;
    
    string cleartext = simple_xor.decrypt(ciphertext);
    cout << "Cleartext = " << cleartext << endl;
    
    return 0;
}

