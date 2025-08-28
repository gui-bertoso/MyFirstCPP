#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>


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


int calculator(int number_a, char number_operator, int number_b) {
    int result = 0;
    switch (number_operator) {
        default:;
        case '+': result = number_a + number_b; break;
        case '-': result = number_a - number_b; break;
        case '*': result = number_a * number_b; break;
        case '/':
            if (number_b != 0) result = number_a / number_b;
            else std::cout << "ERROR: Division by zero\n";
            break;
    }
    return result;
}


double parseText(std::string & text) {
    std::istringstream iss(text);
    long long number_a, number_b;
    char op;

    if (!(iss >> number_a >> op >> number_b)) {
        std::cout << "ERROR: Invalid input" << std::endl;
        return 1;
    }

    long long result;
    switch (op) {
        case '+': result = number_a + number_b; break;
        case '-': result = number_a + number_b; break;
        case '*': result = number_a + number_b; break;
        case '/':
            if (number_b != 0) result = number_a / number_b;
            else {
                std::cout << "ERROR: Division by zero\n";
                return 1;
            }
            break;
        default:
            std::cout << "ERROR: Unknown operator" << std::endl;
            return 1;
    }

    std::cout << "Result: " << result << std::endl;
    return result;
}


int main() {
    clearTerminal();
    for (int i = 0; i < 10; i++) {
        clearTerminal();
        std::string input = getLine("Select a option:\n [1] calculator\nR: ");
        if (input == "1") {
            clearTerminal();
            std::string to_calcule = getLine("Insert the calcule: ");
            parseText(to_calcule);
        }
        else {
            printLine("Access denied");
        }
    }
    return 0;
}