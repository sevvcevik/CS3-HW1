// Sevval Cevik
// Assignment 1
// Due Date: September 4, 2026

#include <iostream> // provides cout
#include <cstdlib>  // provides atoi 
#include <string> // needed to use string data type (Source: W3Schools)

using namespace std; // used instead of writing std::cout or std::cin every time

unsigned int power(unsigned short a, unsigned short b) { // function signature given in the assignment

    unsigned int presult = 1; // any number raised to the power of 0 is 1 so that's the initial value

    for (unsigned short i = 0; i < b; ++i) { 
        presult = presult * a;
    }

    return presult;
}

int main (int argc, char* argv[]) { 
    // Program takes the user input as command line arguments in the main() function
    // Source: https://www.teach.cs.toronto.edu/~ajr/209/notes/argv.html
    // argc: Argument count. How many things were typed on the command line, including the program's name.
    // argv: Argument vector holding the input. 
    // C++ was designed before std::string existed. 
    // Each argument is given to the program as a c-style string, which is basically a sequence of char characters.

    if (argc != 3) { // checking if the user entered the correct number of arguments
        cout << "Please enter a base number and an exponent!" << endl;
        return 1;
    }

    // argv[0] is the name of the program
    string num1 = argv[1];
    string num2 = argv[2];

    // Checking the base number
    for (int i = 0; i < num1.length(); ++i) { // going through each character of the string

        // Checking for negative numbers
        if (num1[i] == '-') {
            cout << "Please enter a non-negative base number!" << endl;
            return 1;
        }

        // Checking for non-integer characters
        if (num1[i] < '0' || num1[i] > '9') {
            cout << "Please enter integers only!" << endl;
            return 1;
        }
    }

    // Checking the exponent number
    for (int i = 0; i < num2.length(); ++i) { // going through each character of the string

        // Checking for negative numbers
        if (num2[i] == '-') {
            cout << "Please enter a non-negative exponent!" << endl;
            return 1;
        }

        // Checking for non-integer characters
        if (num2[i] < '0' || num2[i] > '9') {
            cout << "Please enter integers only!" << endl;
            return 1;
        }
    }

    // The maximum value of an unsigned short integer is 65535 (5 digits).
    // Checking if the values are too large
    if (num1.length() > 5 || num2.length() > 5) {
        cout << "Please enter a base number and an exponent with at most 5 digits!" << endl;
        return 1;
    }

    //Converting the strings to unsigned int to check maximum value of 65535
    // atoi() https://cplusplus.com/reference/cstdlib/atoi/
    unsigned int base = atoi(num1.c_str());
    unsigned int exponent = atoi(num2.c_str());

    //Checking if the values are bigger than 65535
    if (base > 65535 || exponent > 65535) {
        cout << "Please enter a base number and an exponent less than or equal to 65535!" << endl;
        return 1;
    }

    // Printing the input values after making sure they are valid
	cout << "Base number you entered: " << num1 << endl;
    cout << "Exponent you entered: " << num2 << endl;

    // Converting unsigned int to unsigned short for power function
    // I didn't get any error running this so I assumed we don't need additional casting.
    unsigned short a = base;
    unsigned short b = exponent;

    // Calling the power function
    unsigned int result_power = power(a, b);

    // Calculating the sum of the digits of the result
    unsigned int sum = 0;
    unsigned int temp = result_power;
    while (temp > 0) {
        sum = sum + (temp % 10);
        temp = temp / 10; 
    }

    // Printing the power result and the sum of its digits
    cout << "Result of " << num1 << "^" << num2 << " is: " << result_power << endl;
    cout << "Sum of the digits of " << result_power << " is: " << sum << endl;
    
	// Print c++ version, shows language standard
	cout << "version: " << __cplusplus << endl;
	
	return 0;
}

// I desperately needed this program an average of 0 times per day last week :)