#include <iostream>
#include <tuple>
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

int calcule(int number_a, char op, int number_b) {
    int result = 0;
    switch (op) {
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

std::tuple<long long, char, long long> parseToNumbersAndOperator(const std::string & text) {
    std::istringstream iss(text);
    long long number_a, number_b;
    char op;

    if (!(iss >> number_a >> op >> number_b)) {
        std::cout << "ERROR: Invalid text" << std::endl;
        return {0, '?', 0};
    }

    return {number_a, op, number_b};
}

void calculator() {
    while (true) {
        std::string input = getLine("Insert a count: ");
        auto [nb_a, op, nb_b] = parseToNumbersAndOperator(input);
        std::cout << "Result: " << calcule(nb_a, op, nb_b) << std::endl;
    }
}

int main() {
    clearTerminal();
    for (int i = 0; i < 10; i++) {
        clearTerminal(); // Not's work, Why not' working?, I don't know
        std::string input = getLine("Select a option:\n [1] calculator\n [2] it's par?\nR: ");
        if (input == "1") {
            clearTerminal(); // Not's work, Why not' working?, I don't know, Again
            std::string to_calcule = getLine("Insert the calcule: ");
            auto [nb_a, op, nb_b] = parseToNumbersAndOperator(to_calcule);
            std::cout << "Result: " << calcule(nb_a, op, nb_b) << std::endl;
        }
        else if (input == "2") {
            clearTerminal();
        }
        else {
            printLine("Access denied");
        }
    }
    return 0;
}