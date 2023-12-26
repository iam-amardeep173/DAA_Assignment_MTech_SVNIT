#include <iostream>
#include <stack>
#include <chrono>

bool isValidExpression(const std::string& input) {
    std::stack<char> symbolStack;

    for (char symbol : input) {
        if (!symbolStack.empty()) {
            char topSymbol = symbolStack.top();

            // Check the multiplication table for the pair
            if ((topSymbol == 'a' && symbol == 'b') ||
                (topSymbol == 'b' && symbol == 'c') ||
                (topSymbol == 'c' && symbol == 'a')) {
                symbolStack.pop();  // Pop the top symbol
            } else {
                symbolStack.push(symbol);  // Push the current symbol
            }
        } else {
            symbolStack.push(symbol);  // Push the current symbol
        }
    }

    // If the stack is empty, it is possible to parenthesize the string
    return symbolStack.empty();
}


int main() {
    //std::string input = "abbccca";
    std::string input;
    std::cout << "Enter the string of symbols: ";
    std::getline(std::cin, input);

    auto start = std::chrono::high_resolution_clock::now();

    if (isValidExpression(input)) {
        std::cout << "Yes, it is possible to parenthesize the string to get 'a'.\n";
    } else {
        std::cout << "No, it is not possible to parenthesize the string to get 'a'.\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}
