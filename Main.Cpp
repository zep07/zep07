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
        cout << "4. Start Pomodoro (25 min study + 5 min break)\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) tracker.startStudy();
        else if (choice == 2) tracker.stopStudy();
        else if (choice == 3) tracker.showReport();
        else if (choice == 4) tracker.startPomodoro();
        else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
