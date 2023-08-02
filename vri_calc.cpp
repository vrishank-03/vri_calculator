#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return a / b;
}

// Function to perform the selected operation
double performOperation(double a, double b, char op) {
    switch (op) {
        case '+':
            return add(a, b);
        case '-':
            return subtract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
        default:
            throw runtime_error("Invalid operator. Supported operators are +, -, *, and /.");
    }
}

int main() {
    string input;
    double num1, num2, result;
    char op;

    cout << "Welcome to the Calculator!" << endl;

    while (true) {
        try {
            cout << "Enter an expression (e.g., 2 + 3): ";
            getline(cin, input);

            if (input == "exit") {
                cout << "Goodbye! Exiting the calculator." << endl;
                break;
            }

            stringstream ss(input);
            ss >> num1 >> op >> num2;

            if (ss.fail() || !ss.eof()) {
                throw runtime_error("Invalid input format. Please enter a valid expression.");
            }

            result = performOperation(num1, num2, op);
            cout << "Result: " << fixed << setprecision(2) << result << endl;

        } catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        } catch (...) {
            cerr << "An unexpected error occurred." << endl;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

