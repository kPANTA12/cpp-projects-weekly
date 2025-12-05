#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    cout << "========================================" << endl;
    cout << "   Welcome to Number Guessing Game!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    bool playAgain = true;
    
    while (playAgain) {
        // Generate random number between 1 and 100
        int secretNumber = rand() % 100 + 1;
        int guess = 0;
        int attempts = 0;
        int maxAttempts = 10;
        
        cout << "I've picked a number between 1 and 100." << endl;
        cout << "You have " << maxAttempts << " attempts to guess it!" << endl;
        cout << endl;
        
        bool hasWon = false;
        
        while (attempts < maxAttempts && !hasWon) {
            cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " - Enter your guess: ";
            
            if (!(cin >> guess)) {
                cout << "Invalid input! Please enter a number." << endl;
                clearInputBuffer();
                continue;
            }
            
            attempts++;
            
            if (guess < 1 || guess > 100) {
                cout << "Please guess a number between 1 and 100!" << endl;
                cout << endl;
                continue;
            }
            
            if (guess < secretNumber) {
                cout << "Too low! Try again." << endl;
                cout << endl;
            } else if (guess > secretNumber) {
                cout << "Too high! Try again." << endl;
                cout << endl;
            } else {
                hasWon = true;
                cout << endl;
                cout << "🎉 Congratulations! You guessed it right!" << endl;
                cout << "The number was: " << secretNumber << endl;
                cout << "You won in " << attempts << " attempts!" << endl;
                cout << endl;
            }
        }
        
        if (!hasWon) {
            cout << endl;
            cout << "😔 Game Over! You've used all " << maxAttempts << " attempts." << endl;
            cout << "The number was: " << secretNumber << endl;
            cout << endl;
        }
        
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        
        if (choice != 'y' && choice != 'Y') {
            playAgain = false;
            cout << endl;
            cout << "Thanks for playing! Goodbye!" << endl;
        } else {
            cout << endl;
            cout << "Starting a new game..." << endl;
            cout << endl;
        }
    }
    
    return 0;
}
