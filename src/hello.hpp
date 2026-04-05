#pragma once
#include <string>
using namespace std;

// max limits for simplicity
const int MAX_STUDENTS = 50;
const int MAX_ASSIGNMENTS = 20;

// student struct
struct Student {
    string firstName;
    string lastName;
    string id;

    // -1 means not set
    int grades[MAX_ASSIGNMENTS];
};

class Gradebook {
private:
    Student students[MAX_STUDENTS];
    string assignmentNames[MAX_ASSIGNMENTS];
    int numStudents;
    int numAssignments;

public:
    // constructor
    Gradebook();

    void add_student(string first, string last, string studentID);
    void add_assignment(string name);
    void enter_grade(string studentName, string assignmentName, int grade);
    string report();
};