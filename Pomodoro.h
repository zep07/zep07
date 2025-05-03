#ifndef POMODORO_TRACKER_H
#define POMODORO_TRACKER_H

class PomodoroTracker {
private:
    bool studying;
    time_t startTime;
    const char* getTodayDate();  // Gets date like "2025-05-03"
    void logStudyTime(int seconds);
    void countdown(int seconds);  // Basic timer

public:
    PomodoroTracker();
    void startStudy();
    void stopStudy();
    void showReport();
    void startPomodoro();
};

#endif
