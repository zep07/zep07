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
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: tracker.startStudy(); break;
            case 2: tracker.stopStudy(); break;
            case 3: tracker.showReport(); break;
            case 4: tracker.startPomodoro(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}

