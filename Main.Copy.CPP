#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>  // For usleep
#include "PomodoroTracker/PomodoroTracker.h"

using namespace std;

PomodoroTracker::PomodoroTracker() {
    studying = false;
    startTime = 0;
}

const char* PomodoroTracker::getTodayDate() {
    static char date[11];  // "YYYY-MM-DD"
    time_t now = time(0);
    tm* ltm = localtime(&now);
    sprintf(date, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    return date;
}

void PomodoroTracker::logStudyTime(int seconds) {
    FILE* file = fopen("study_log.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %d\n", getTodayDate(), seconds);
        fclose(file);
    } else {
        cout << "Error saving to file.\n";
    }
}

void PomodoroTracker::countdown(int seconds) {
    for (int i = seconds; i > 0; --i) {
        int mins = i / 60;
        int secs = i % 60;
        cout << "\rTime remaining: " << mins << "m " << secs << "s " << flush;

        // Slow down time by adding a microsecond delay
        usleep(1000000); // 100,000 microseconds = 0.1 seconds
    }
    cout << "\nTime's up!\n";
}

void PomodoroTracker::startStudy() {
    if (!studying) {
        time(&startTime);
        studying = true;
        cout << "Study session started!\n";
    } else {
        cout << "You're already studying.\n";
    }
}

void PomodoroTracker::stopStudy() {
    if (studying) {
        time_t endTime;
        time(&endTime);
        int duration = static_cast<int>(difftime(endTime, startTime));
        studying = false;
        logStudyTime(duration);
        cout << "Study stopped. Duration: " << duration << " seconds.\n";
    } else {
        cout << "You haven't started studying yet.\n";
    }
}

void PomodoroTracker::showReport() {
    FILE* file = fopen("study_log.txt", "r");
    if (file == NULL) {
        cout << "No log file found.\n";
        return;
    }

    char date[16];
    int seconds;
    int total = 0;
    const char* today = getTodayDate();

    while (fscanf(file, "%s %d", date, &seconds) != EOF) {
        if (strcmp(date, today) == 0) {
            total += seconds;
        }
    }

    fclose(file);

    int mins = total / 60;
    int secs = total % 60;

    cout << "\nToday's Total Study Time: " << mins << " minutes and " << secs << " seconds.\n";
}

void PomodoroTracker::startPomodoro() {
    cout << "\nStarting Pomodoro: 25 minutes of focused study time.\n";
    countdown(1 * 60);  // 25 minutes focus time

    cout << "\nBreak time! 5 minutes.\n";
    countdown(5 * 60);  // 5 minutes break time
}
