#ifndef _VIGNERE_H_
#define _VIGNERE_H_

#define MAX_ALPHABETS 26 ///26 alphabets in English
#define INVALID_COLUMN -1

class Vignere {
 private:
    char tabula_recta_[MAX_ALPHABETS][MAX_ALPHABETS];
    std::string key_;
	
 public:
    explicit Vignere(const std::string);
    void set_key(const std::string&);
    std::string key(void);
    std::string encrypt(const std::string&);
    std::string decrypt(const std::string&);
};

#endif