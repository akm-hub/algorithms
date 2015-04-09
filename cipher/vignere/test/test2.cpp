/**
  * @purpose Vignere crypto driver code
  *
  * @author  Ashish
  * @license MIT license
  * @version 1.0, Doxygen compatible comments
  */

#include <iostream>
#include <string>
#include "vignere.h"

int main() {
    /// Create a cipher using the first 16 bytes of the passphrase
    Vignere *vignere = new Vignere("ALICE");
    std::string cleartext = "CODEISSECURE";

    /// Run it through the cipher and back
    std::string ciphertext = vignere->encrypt(cleartext);
    std::cout << "Encrypted text = " << ciphertext << std::endl;

    cleartext = vignere->decrypt(ciphertext);
    std::cout << "Clear text = " << cleartext << std::endl;
    return 0;
}
