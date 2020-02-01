//
// Created by troyl on 11/6/2019.
//

#include <string>
#include <iostream>

#include "hash_test_main.cpp"
#include "tL_test_main.cpp"
#include "uci_main.cpp"
#include "test_moves_main.cpp"

void print_seperator(std::string txt){
    int length_text = txt.length();
    std::cout << "\n\n\n\n";

    //print 1st line of asterisks
    for(int i = 0; i < length_text + 10; i++){
        std::cout << "*";
    }
    std::cout << "\n";

    //print middle line
    std::cout << "**** " + txt + " ****\n";

    //print 2nd line of asterisks
    for(int i = 0; i < length_text + 10; i++){
        std::cout << "*";
    }
    std::cout << "\n\n";
}

//TODO: here is where you put the method call/main method/testing code along with a seperator
int main(int argc, char *argv[]) {
    std::string USAGE_ERROR = "Usage: " + std::string(argv[0]) + " [main_method_name.cpp]";

    bool zero_arg; // remember if no arguements given
    std::string input_main = ""; // which main is the user calling
    switch (argc) {
    case 1: // user did not specify a main to run
        zero_arg = true;
        break;
    case 2: // user gave a main to run
        zero_arg = false;
        input_main = std::string(argv[1]);
        break;
    default: // user is confused
        std::cout << USAGE_ERROR << std::endl;
        return 1;
        break;
    }

    bool has_run = false;
    // GIANT main method so that the project would actually compile and run lol - Troy

    //------------------------------------------------------------------------------------------------------------------
    if (input_main == "hash_test_main.cpp") {
        print_seperator("Code from hash_test_main.cpp main() here");
        hash_test_main_namespace::main();
        has_run = true;
    }
    //------------------------------------------------------------------------------------------------------------------
    if (input_main == "tL_test_main.cpp") {
        print_seperator("Code from tL_test_main.cpp main() here");
        tL_test_main_namespace::main();
        has_run = true;
    }
    //------------------------------------------------------------------------------------------------------------------
    // uci_main is the main method that needs to be called by GUI/user, so it should be the default to run if no are is given. 
    if (zero_arg || input_main == "uci_main.cpp") {
        if (!zero_arg) print_seperator("Code from uci_main.cpp main() here");
        uci_main_namespace::main();
        has_run = true;
    }
    //------------------------------------------------------------------------------------------------------------------
    if (input_main == "test_moves_main.cpp") {
        if (!zero_arg) print_seperator("Code from test_moves_main.cpp main() here");
        test_moves_main_namespace::main();
        has_run = true;
    }
    if (! has_run) { // input_main did not match any known main()
        std::cout << USAGE_ERROR << std::endl;
        return 1;
    }
    return 0;
}


