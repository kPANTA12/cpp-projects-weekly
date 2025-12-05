#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber(int max) {
    return rand() % max + 1;
}

void playGame(int maxNumber, int maxAttempts) {
    int number = generateRandomNumber(maxNumber);
    int guess, attempts = 0;
    cout << "Guess the number between 1 and " << maxNumber << ":\n";

    while(attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        if(guess == number) {
            cout << "Congratulations! You guessed in " << attempts << " attempts.\n";
            return;
        } else if(guess < number) {
            cout << "Too low!\n";
        } else {
            cout << "Too high!\n";
        }
    }
    cout << "Sorry! The number was " << number << ".\n";
}

int main() {
    srand(time(0));
    char choice;
    do {
        int level;
        cout << "Choose difficulty: 1-Easy, 2-Medium, 3-Hard: ";
        cin >> level;

        switch(level) {
            case 1: playGame(50, 10); break;
            case 2: playGame(100, 7); break;
            case 3: playGame(200, 5); break;
            default: cout << "Invalid choice!\n"; break;
        }

        cout << "Play again? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    return 0;
}
