// Pranav Pramod
// 11/25/2024
// Papa Pranav's Pizzeria
// Extra: Allowed the user to enter a quantity for num of pizzas


#include <iostream>
#include <string>
using namespace std;

double calculatePrice(char type, int numOfTop);
void displayReceipt(int quantities[], int toppings[]);

int main()
{
    char input;
    int numOfToppings, numOfPizzas;
    string menuItems[2] = {"Little Ansh Supreme", "King Ansh Supreme"};
    int quantities[2] = {0, 0};
    int toppings[2] = {0, 0};  

    // Shop Name
    printf("🍕======Papa Pranav's Pizzeria======🍕");

    // Run the code while the user does not input 'n'
    printf("\nTHE MENU\n");

    for (int i = 0; i < 2; i++) {
        cout << i << ". " << menuItems[i] << endl;
    }

    cout << "\nEnter an option ('n' to checkout): ";
    cin >> input;

    while (input != 'n') {
        // Input validation
        while (input != '0' && input != '1' && input != 'n') {
            cout << "Invalid option. Please enter '0', '1', or 'n': ";
            cin >> input;
        }

        if (input == 'n') {
            break;
        }

        // Get the number of pizzas and toppings
        cout << "How many pizzas would you like to order? ";
        cin >> numOfPizzas;

        cout << "Quantity of Toppings: ";
        cin >> numOfToppings;

        // Update the quantities and toppings
        switch (input) {
            case '0':
                quantities[0] += numOfPizzas;
                toppings[0] += numOfToppings * numOfPizzas;
                break;
            case '1':
                quantities[1] += numOfPizzas;
                toppings[1] += numOfToppings * numOfPizzas;
                break;
            default:
                break;
        }

        printf("\nTHE MENU\n");

        // Display the menu
        for (int i = 0; i < 2; i++) {
            cout << i << ". " << menuItems[i] << endl;
        }

        cout << "\nEnter an option ('n' to checkout): ";
        cin >> input;
    }

    // Print final receipt
    displayReceipt(quantities, toppings);

    return 0;
}

// Calculate the price of the pizza
double calculatePrice(char type, int numOfTop) {
    if (type == '0') {
        return 10.99 + (double)(numOfTop * 3);
    } else {
        return 12.99 + (double)(numOfTop * 3);
    }
}


// Display the receipt
void displayReceipt(int quantities[], int toppings[]) {
    double total = 0.0;
    cout << "\nFinal Receipt:\n";
    if (quantities[0] > 0) {
        double price = quantities[0] * 10.99 + toppings[0] * 3.00;
        cout << "Little Ansh Supreme: " << quantities[0] << " X 10.99 + " << toppings[0] << " toppings = " << price << endl;
        total += price;
    }
    if (quantities[1] > 0) {
        double price = quantities[1] * 12.99 + toppings[1] * 3.00;
        cout << "King Ansh Supreme: " << quantities[1] << " X 12.99 + " << toppings[1] << " toppings = " << price << endl;
        total += price;
    }
    cout << "Total: $" << total << endl;
    cout << "Thank you for shopping at Papa Pranav's Pizzeria!";
}