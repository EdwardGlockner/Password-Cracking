#include <iostream>
#include <vector>

#include "../include/brute_force.h"
#include "../include/dictionary_attack.h"
#include "../include/rule_based.h"
#include "../include/password_comparison.h"

int main() {
    Brute_Force* BF = new Brute_Force();
    Dictionary_Attack* DA = new Dictionary_Attack();

    std::vector<std::string> passwords;
    std::cout << "Generating passwords..." << std::endl;
    BF->generate_passwords("", 5, passwords);
    
    std::cout << "Initializing brute force attack" << std::endl;
    // Brute force attack by trying each password until the correct one is found
    std::string correct_password = "assku"; // The correct password to be guessed
    for (std::string password : passwords) {
        if (password == correct_password) {
            std::cout << "Password found: " << password << std::endl;
            break;
        }
    }
    return 0;
}
