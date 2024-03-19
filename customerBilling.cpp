#include <iostream>

using namespace std;

const int MAX_CUSTOMERS = 100; // Maximum number of customers

int main() {
    // Prices
    const int price_mango = 20;
    const int price_orange = 10;
    const int price_banana = 5;

    // Arrays to store the quantities for each fruit per customer
    int Mango[MAX_CUSTOMERS];
    int Orange[MAX_CUSTOMERS];
    int Banana[MAX_CUSTOMERS];

    // Number of customers
    int num_customers;
    cout << "Enter the number of customers: ";
    cin >> num_customers;

    // Input validation for number of customers
    if (num_customers > MAX_CUSTOMERS || num_customers < 1) {
        cout << "Invalid number of customers. Max allowed is " << MAX_CUSTOMERS << ".\n";
        return 1;
    }

    // Input loop for each customer
    for (int i = 0; i < num_customers; i++) {
        cout << "Enter the number of mangoes for customer " << i + 1 << ": ";
        cin >> Mango[i];
        cout << "Enter the number of oranges for customer " << i + 1 << ": ";
        cin >> Orange[i];
        cout << "Enter the number of bananas for customer " << i + 1 << ": ";
        cin >> Banana[i];
    }

    cout << "Customer No. Mangoes Oranges Bananas Total Bill\n";

    // Calculation and display loop
    for (int i = 0; i < num_customers; i++) {

        int total_bill = (Mango[i] * price_mango) + (Orange[i] * price_orange) + (Banana[i] * price_banana);
        

        cout << i + 1 << " " << Mango[i] << " " << Orange[i] << " " << Banana[i] << " Rs. " << total_bill << "\n";
    }

    return 0;
}
