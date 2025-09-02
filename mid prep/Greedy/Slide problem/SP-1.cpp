#include <iostream>          // Include input/output library for cin and cout
using namespace std;         // Use standard namespace to avoid writing std:: every time

int main() {
    int sticks, diamonds;    // Variables to store number of sticks and diamonds
    cout << "Enter number of sticks: ";  // Prompt user for sticks
    cin >> sticks;            // Read sticks
    cout << "Enter number of diamonds: "; // Prompt user for diamonds
    cin >> diamonds;          // Read diamonds

    int totalDollars = 0;     // Variable to store total dollars earned

    // Craft as many swords or shovels as possible
    while (true) {
        if (sticks >= 2 && diamonds >= 1) {   // Check if we can craft a shovel
            sticks -= 2;                       // Use 2 sticks
            diamonds -= 1;                     // Use 1 diamond
            totalDollars += 1;                 // Earn 1 dollar
        }
        else if (sticks >= 1 && diamonds >= 2) { // Check if we can craft a sword
            sticks -= 1;                         // Use 1 stick
            diamonds -= 2;                       // Use 2 diamonds
            totalDollars += 1;                   // Earn 1 dollar
        }
        else {                                   // Cannot craft any more tools
            break;                               // Exit the loop
        }
    }

    cout << "Total dollars Polycarp can earn: " << totalDollars << "\n"; // Print result

    return 0;  // End of program
}

