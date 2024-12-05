#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class
class Game {
protected:
    int secretNumber;
    int maxAttempts;

public:
    Game(int maxAttempts) : maxAttempts(maxAttempts) {
        srand(time(0)); // Seed the random number generator
        secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    }

    virtual void play() = 0; // Pure virtual function
};

// Derived class
class NumberGuessingGame : public Game {
public:
    NumberGuessingGame(int maxAttempts) : Game(maxAttempts) {}

    void play() override {
        int guess;
        int attempts = 0;

        cout << "\nI have selected a number between 1 and 100. Can you guess it?" << endl;

        while (attempts < maxAttempts) {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > secretNumber) {
                cout << "The secret number is smaller than the number you have choosen! Try again." << endl;
            } else if (guess < secretNumber) {
                cout << "The secret number is grater than the number you have choosen! Try again." << endl;
            } else {
                cout << "Congratulations!You won the game.Game author @Sanzid Zaman....! "  << endl;
                return;
            }

            // Show remaining attempts
            cout << "Attempts remaining: " << maxAttempts - attempts << endl;
        }

        cout << "Sorry, you've used all your attempts. The number was " << secretNumber << "." << endl;
    }
};

// Function to get max attempts based on difficulty level
int getMaxAttempts(int difficulty) {
    switch (difficulty) {
        case 1: return 10; // Easy
        case 2: return 7;  // Medium
        case 3: return 5;  // semi hard
        case 4: return 3;  // Hard
        default: return 10; // Default to easy if invalid
    }
}
 
int main() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and 100. You'll have limited attempts based on the difficulty level you choose. Good Luck!" << endl;

    while (true) {
        cout << "\nChoose a difficulty level: " << endl;
        cout << "1. Easy (10 attempts)" << endl;
        cout << "2. Medium (7 attempts)" << endl;
        cout << "3. Semi hard (5 attempts)" << endl;
        cout << "4. Hard (3 attempts)" << endl;
        cout << "0. Exit" << endl;

        int difficultyChoice;
        cout << "Enter your choice: ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            cout << "Exiting the game. Thank you for playing!" << endl;
            break;
        } else if (difficultyChoice >= 1 && difficultyChoice <= 4) {
            int maxAttempts = getMaxAttempts(difficultyChoice);
            NumberGuessingGame game(maxAttempts);
            game.play();
        } else {
            cout << "Invalid choice. Please enter a valid option (0, 1, 2, 3 or 4)." << endl;
        }
    }

    return 0;
}
