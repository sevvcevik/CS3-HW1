// Sevval Cevik
// Assignment 1 Part 2
// Due Date: September 11, 2026

#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <vector> 
#include <cmath>
#include <climits> 

using namespace std;

// I used size_t for for loops to avoid size_t warnings that I got for part1 with -Wall 
// Source for size_t: https://en.cppreference.com/cpp/types/size_t
// I didn't use size_t for the for loop in power function because b is also an unsigned int

unsigned long long int power(unsigned int a, unsigned int b) {

    unsigned long long int presult = 1; 
    // initialized to 1 because any number raised to the power of 0 is 1
    // if b is 0, the loop will not run and the function will return 1

    for (unsigned int i = 0; i < b; i++) {
        presult = presult * a;
    }

    return presult;
}

vector<int> vectorize_digits(unsigned long long n) {

    vector<int> digits;

    // https://www.geeksforgeeks.org/cpp/how-to-add-elements-in-a-vector-in-cpp/ 
    // (used to understand how to add elements to a vector in c++)
    
    // without this, 0 would produce an empty vector because the while loop only runs for values greater than 0
    if (n == 0) {
        digits.push_back(0);
        return digits;
    }

  
    while (n > 0) {
        int digit = n % 10;

        // % 10 finds digits right-to-left
        // that's why I used digits.insert(digits.begin()... to insert each digit at the beginning to preserve the original order
        digits.insert(digits.begin(), digit);
        n = n / 10;
    }

    return digits;
}


int sum_vector(vector<int> v) {

    int sum = 0;

    // https://www.geeksforgeeks.org/cpp/vector-size-in-cpp-stl/

    for (size_t i = 0; i < v.size(); i++) { 
        // used i < v.size() because first element of a vector is at index 0 and last element is at index v.size() - 1
        sum = sum + v[i];
    }

    return sum;
}


string vec_to_string(vector<int> vec) {

    string sresult = "[";

    for (size_t i = 0; i < vec.size(); i++) {

        sresult = sresult + to_string(vec[i]); 
        // https://www.geeksforgeeks.org/cpp/stdto_string-in-cpp/ (used this source to convert to a string in c++)

        if (i+1 < vec.size()) {
            sresult = sresult + ", ";
        }
    }

    sresult = sresult + "]";

    return sresult;
}

int main (int argc, char* argv[]) { 

    if (argc != 3) { // input should be in the form of ./power-digit-sum-2 <base> <exponent> so argc should be 3
        cout << "Please enter a base number and an exponent!" << endl;
        return 1;
    }

    string num1 = argv[1];
    string num2 = argv[2];

    if (num1.length() == 0 || num2.length() == 0) {
        cout << "Please enter integers only!" << endl;
        return 1;
    }


    for (size_t i = 0; i < num1.length(); i++) {

        if (num1[i] == '-') {
            cout << "Please enter a non-negative base number!" << endl;
            return 1;
        }

        if (num1[i] < '0' || num1[i] > '9') {
            cout << "Please enter integers only!" << endl;
            return 1;
        }
    }

  
    for (size_t i = 0; i < num2.length(); i++) {

        if (num2[i] == '-') {
            cout << "Please enter a non-negative exponent!" << endl;
            return 1;
        }

        if (num2[i] < '0' || num2[i] > '9') {
            cout << "Please enter integers only!" << endl;
            return 1;
        }
    }

    // I replaced atoi with strtoul because atoi works with signed integers and may cause issues with large values
    // Source used for strtoul: https://en.cppreference.com/cpp/string/byte/strtoul
    // I converted it to long first to check if the value is within the range of unsigned int before storing it in an unsigned int variable
    unsigned long blong = strtoul(num1.c_str(), NULL, 10);
    unsigned long elong = strtoul(num2.c_str(), NULL, 10);

    if (blong > UINT_MAX || elong > UINT_MAX) {
        cout << "Please enter numbers between 0 and " << UINT_MAX << "!" << endl;
        return 1;
    }

    unsigned int base = blong;
    unsigned int exponent = elong;


    // Used logarithms to detect overflow before power() performs the multiplication.
    if (base > 1 && exponent > 0) {

        double result_log = exponent * log10(base);
        double max_log = 64 * log10(2);

        if (result_log >= max_log) {
            cout << "The result of the power function is too large and would cause overflow!" << endl;
            return 1;
        }
    }

    unsigned long long int result_power = power(base, exponent);
    vector<int> digits = vectorize_digits(result_power);
    int sum = sum_vector(digits);


    cout <<  num1 << "^" << num2 << " = " << result_power << endl;
    cout << "Sum Of Digits: " << sum << endl;
    
	
	return 0;
}