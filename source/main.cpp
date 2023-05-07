/*
 *
 */

// Includes
#include <iostream>
#include <tuple>
#include <vector>
#include <chrono>

// Local includes
#include "../include/brute_force.h"
#include "../include/dictionary_attack.h"
#include "../include/rule_based.h"
#include "../include/password_comparison.h"

/*
 * should check equality after each generated password
 * not generating all passwords then checking them all
 */

// Function declaration
std::tuple<std::string, std::string> flagger(int argc, char* argv[]);
void usage_helper();


int main(int argc, char* argv[]) {
    flagger(argc, argv);
    Brute_Force* BF = new Brute_Force();
    Dictionary_Attack* DA = new Dictionary_Attack();

    std::vector<std::string> passwords;
    std::cout << "Generating passwords..." << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now();
    BF->generate_passwords("", 4, passwords);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    std::cout << "Elapsed time for password generation: " << \
        duration1.count() << " milliseconds" <<  std::endl;
    
    std::cout << "Initializing brute force attack" << std::endl;
    // Brute force attack by trying each password until the correct one is found
    std::string correct_password = "assu"; // The correct password to be guessed
    auto start2 = std::chrono::high_resolution_clock::now();
    for (std::string password : passwords) {
        if (password == correct_password) {
            std::cout << "Password found: " << password << std::endl;
            auto stop2 = std::chrono::high_resolution_clock::now();
            auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2-start2);
            std::cout << "Elapsed time for brute force attack: " << duration2.count() \
                << " milliseconds" << std::endl;
            break;
        }
    }
    return 0;
}

// Functions
std::tuple<std::string, std::string> flagger(int argc, char* argv[]) {
    /*
     *
     */
    std::string run_mode;
    std::string dirname;
    
    if (argc > 1) {
        // Iterate over the flags

        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0) {
                usage_helper();
            }

            else if (strcmp(argv[i], "-m") == 0) {
                std::cout << "MODDE: " << argv[i+1] << std::endl;
                run_mode = argv[i+1];
            }
            else if (strcmp(argv[i], "-d") == 0) {
                std::cout << "DIRNAME: " << argv[i+1] << std::endl;
                dirname = argv[i+1];
            }
        }
    } 
    if (run_mode.empty()) {
        std::cout << "Run mode not selected" << std::endl;
    }
    if (dirname.empty()) {
        std::cout << "Dirname not specified" << std::endl;
    }
    return std::make_tuple(run_mode, dirname);
}

void usage_helper() {
    /*
     *
     */
    std::cout << "--------------------USAGE--------------------" << "\n";
    std::cout << "./pw_attack -h | -m <run_mode> | -d <dirname>" << "\n";
    std::cout << "\n-h: \t Shows the helper for running the file.\n";
    std::cout << "\n-m: \t Sets the run mode. Available options: 'brute_force', 'dict_attack', 'rule_based'.\n";
    std::cout << "The run mode is set to 'brute_force' by default.\n";
    std::cout << "\n-d: \t Specifies the directory path to the dictionary which will be used, in case run_mode is set to 'dict_attack.\n";
    std::cout << "The directory is by default set to ....\n\n";
}
