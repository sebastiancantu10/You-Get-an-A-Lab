#include "hello.hpp"
#include <iostream>
using namespace std;

Gradebook::Gradebook() {
    numStudents = 0;
    numAssignments = 0;

    // initialize all grades to -1 (not set)
    for (int s = 0; s < MAX_STUDENTS; s++) {
        for (int a = 0; a < MAX_ASSIGNMENTS; a++) {
            students[s].grades[a] = -1;
        }
    }
}

// add a new student
void Gradebook::add_student(string first, string last, string studentID) {
    if (numStudents >= MAX_STUDENTS) return;

    students[numStudents].firstName = first;
    students[numStudents].lastName = last;
    students[numStudents].id = studentID;
    numStudents++;
}

// add a new assignment
void Gradebook::add_assignment(string name) {
    if (numAssignments >= MAX_ASSIGNMENTS) return;
    assignmentNames[numAssignments] = name;
    numAssignments++;
}

// enter grade for a student for an assignment
void Gradebook::enter_grade(string studentName, string assignmentName, int grade) {
    int studentIndex = -1;
    int assignmentIndex = -1;

    // find student
    for (int s = 0; s < numStudents; s++) {
        string fullName = students[s].firstName + " " + students[s].lastName;
        if (fullName == studentName) {
            studentIndex = s;
            break;
        }
    }

    // find assignment
    for (int a = 0; a < numAssignments; a++) {
        if (assignmentNames[a] == assignmentName) {
            assignmentIndex = a;
            break;
        }
    }

    // if found, set grade
    if (studentIndex != -1 && assignmentIndex != -1) {
        students[studentIndex].grades[assignmentIndex] = grade;
    }
}

// create the report
string Gradebook::report() {
    string output = "Last_Name,First_Name,Student_ID";

    // add assignment headers
    for (int a = 0; a < numAssignments; a++) {
        output += "," + assignmentNames[a];
    }
    output += "\n";

    // add each student
    for (int s = 0; s < numStudents; s++) {
        output += students[s].lastName + "," + students[s].firstName + "," + students[s].id;

        for (int a = 0; a < numAssignments; a++) {
            int grade = students[s].grades[a];
            if (grade == -1) {
                output += ",none";
            } else {
                output += "," + to_string(grade);
            }
        }
        output += "\n";
    }

    return output;
}
