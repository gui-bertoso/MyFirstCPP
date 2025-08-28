#include <iostream>
#include <cstdlib>
#include <string>

void printLine(const std::string & text) {
    std::cout << text << std::endl;
    // To simplify print text in terminal
}

std::string getLine(const std::string & msg) {
    std::string input;
    std::cout << msg;
    std::getline(std::cin, input);
    return input;
    // To simplify get input text in terminal
}

// Lower security, uses an external terminal
//void clearTerminal() {
    // To simplify a terminal clear
//#ifdef _WIN32
    //system("cls"); // To Windows terminal clear
//#else
    //system("clear"); // To linux terminal clear
//#endif
//}

void clearTerminal() {
    std::cout << "\033[2J\033[H";
}


int main() {
    for (int i = 0; i < 10; i++) {
        clearTerminal();
        std::string input = getLine("Select a option:\n [1] calculator\nR: ");
        if (input == "1") {
            printLine("Access granted");
        }
        else {
            printLine("Access denied");
        }
    }
    return 0;
}