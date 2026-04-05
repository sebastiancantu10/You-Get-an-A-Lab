This program is a simple Gradebook. It allows users to add students, add assignments, input grades and print a report.
You can do the following:
Add a student (first name, last name, student ID)
Add an assignment (assignment name)
Enter a grade for a student on an assignment
Print a formatted report of all students and their grades

The program works by using arrays to store data. 
An array of Student objects stores the student's information.
Another array stores the assignment names.
If there is no grade then the program will store it as -1 and print "none".

How to Use the Gradebook
1.) Create a Gradebook object:
Gradebook gradebook;
2.) Add students:
gradebook.add_student("first name", "last name", "ID");
3.) Add assignments:
gradebook.add_assignment("assignment");
4.) Enter grades:
gradebook.enter_grade("firstName lastName", "assignment", score as an int);
5.) Print the report:
cout << gradebook.report();
