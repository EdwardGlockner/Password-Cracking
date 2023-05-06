/*
 *
 */

#include "../include/brute_force.h"

Brute_Force::Brute_Force() {

}

Brute_Force::~Brute_Force() {

}

void Brute_Force::generate_passwords(std::string password, const int length,\
        std::vector<std::string> &passwords) {
    if (length == 0) {
            passwords.push_back(password);
    } 
    else {
        for (char c : CHARS) {
                generate_passwords(password + c, length - 1, passwords);
        }
    }
}
