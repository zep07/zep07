#include <iostream>
#include "PomodoroTracker/PomodoroTracker.h"

using namespace std;

int main() {
    PomodoroTracker tracker;
    int choice;

    while (true) {
        cout << "\n=== Study Time Tracker ===\n";
        cout << "1. Start Studying\n";
        cout << "2. Stop Studying\n";
        cout << "3. Show Today's Report\n";
        cout << "4. Start Pomodoro (25m Focus + 5m Break)\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";

        cin >> choice;

        if (cin.fail()) {
            // Input was not a number
            cin.clear(); // fix the error state
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Please enter a number between 1 to 5.\n";
            continue;
        }

        if (choice == 1) {
            tracker.startStudy();
        } else if (choice == 2) {
            tracker.stopStudy();
        } else if (choice == 3) {
            tracker.showReport();
        } else if (choice == 4) {
            tracker.startPomodoro();
        } else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
