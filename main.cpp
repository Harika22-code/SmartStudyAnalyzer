#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    float studyHours;
    float mobileHours;
    float breakHours;
    float sleepHours;
    float productiveHours;
    int focusScore;
    char grade;

    void inputData()
    {
        cout << "\n===== ENTER STUDENT DETAILS =====\n";

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Study Hours: ";
        cin >> studyHours;

        cout << "Enter Mobile Usage Hours: ";
        cin >> mobileHours;

        cout << "Enter Break Hours: ";
        cin >> breakHours;

        cout << "Enter Sleep Hours: ";
        cin >> sleepHours;
    }

    void calculateProductivity()
    {
        productiveHours = studyHours - (breakHours * 0.5);

        focusScore = (studyHours * 12)
                     - (mobileHours * 2)
                     - (breakHours * 2);

        if (focusScore < 0)
        {
            focusScore = 0;
        }

        if (focusScore > 100)
        {
            focusScore = 100;
        }
        
        if (focusScore >= 90)
        {
            grade = 'A';
        }
        else if (focusScore >= 75){
            grade = 'B';
        }
        else if(focusScore >= 50){
            grade = 'C';
        }
        else
        {
            grade = 'D';
        }
    
    }

    void showSuggestions()
    {
    

        cout << "\n===== ANALYSIS & SUGGESTIONS =====\n";

        if (mobileHours > 5)
        {
            cout << "High mobile usage detected.\n";
            cout << "Suggestion: Reduce screen time during study hours.\n";
        }

        if (studyHours < 3)
        {
            cout << "Low study hours detected.\n";
            cout << "Suggestion: Create a proper study timetable.\n";
        }

        if (breakHours > 3)
        {
            cout << "Too many breaks detected.\n";
            cout << "Suggestion: Follow Pomodoro study technique.\n";
        }

        if (sleepHours < 6)
        {
            cout << "Insufficient sleep detected.\n";
            cout << "Suggestion: Sleep at least 6-8 hours.\n";
        }

        if (focusScore >= 80)
        {
            cout << "\nProductivity Level: EXCELLENT\n";
        }
        else if (focusScore >= 50)
        {
            cout << "\nProductivity Level: AVERAGE\n";
        }
        else
        {
            cout << "\nProductivity Level: NEEDS IMPROVEMENT\n";
        }
    }

    void displayReport()
    {
        cout << "\n===== FINAL REPORT =====\n";

        cout << "Student Name: " << name << endl;
        cout << "Study Hours: " << studyHours << endl;
        cout << "Mobile Usage Hours: " << mobileHours << endl;
        cout << "Break Hours: " << breakHours << endl;
        cout << "Sleep Hours: " << sleepHours << endl;

        cout << "Productive Study Hours: "
             << productiveHours << endl;

        cout << "Focus Score: "
             << focusScore << "/100" << endl;
        
        cout << "Grade:" << grade << endl;
    }
};

int main()
{
    Student s;

    s.inputData();

    s.calculateProductivity();

    s.showSuggestions();

    s.displayReport();

    cout << "\nThank You For Using Smart Study-Time Analyzer!\n";

    return 0;
}