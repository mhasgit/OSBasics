#include <iostream>
#include <cmath>

using namespace std;

// Function to count the number of digits in the integer
int countDigits(int number) {
    // Handling the case where the number is 0
    if (number == 0) {
        return 1;
    }
    
    // Initialize the digit count to 0
    int count = 0;

    // Use abs() to ensure the loop works for negative numbers as well
    number = abs(number);
    
    // Loop to count digits
    while (number > 0) {
        count++;
        number /= 10; 
    }
    
    return count;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    
    // Calling the function and displaying the result
    cout << "The number of digits in " << number << " is " << countDigits(number) << "." << endl;
    
    return 0;
}
