#ifndef POMODORO_TRACKER_H
#define POMODORO_TRACKER_H

#include <ctime>

class PomodoroTracker {
private:
    bool studying;
    time_t startTime;
    const char* getTodayDate();  // Get current date in "YYYY-MM-DD" format
    void logStudyTime(int seconds);  // Save study session to file
    void countdown(int seconds);  // Countdown timer with delays

public:
    PomodoroTracker();  // Constructor
    void startStudy();  // Start a study session
    void stopStudy();   // Stop a study session
    void showReport();  // Show total study time today
    void startPomodoro();  // Start Pomodoro (25 min study, 5 min break)
};

#endif
