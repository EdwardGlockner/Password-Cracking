/*
 *
 */

#ifndef __BRUTE_FORCE_H
#define __BRUTE_FORCE_H

#include <iostream>
#include <vector>

class Brute_Force {
    public:
        Brute_Force();
        ~Brute_Force();

        void generate_passwords(std::string password, const int length, \
                std::vector<std::string>& passwords);

        std::vector<std::string> passwords;
        const std::string CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        const int PASSWORD_LENGTH = 8;
};

#endif
