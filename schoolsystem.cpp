#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// -------- STRUCTURES --------
struct Student {
    int roll;
    string name;
    string school;
};

struct Teacher {
    int id;
    string name;
    string school;
    string subject;
};

// Arrays
Student students[MAX];
Teacher teachers[MAX];

// Counters
int studentCount = 0;
int teacherCount = 0;

// -------- SELECT SCHOOL FUNCTION --------
string chooseSchool() {
    int choice;

    cout << "\nSelect School:\n";
    cout << "1. School of Engineering\n";
    cout << "2. School of Design\n";
    cout << "3. School of Hotel Management\n";
    cout << "4. School of Medical Science\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: return "School of Engineering";
        case 2: return "School of Design";
        case 3: return "School of Hotel Management";
        case 4: return "School of Medical Science";
        default: return "Unknown School";
    }
}

// -------- ADD STUDENT --------
void addStudent() {
    cout << "\nEnter Roll Number: ";
    cin >> students[studentCount].roll;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, students[studentCount].name);

    students[studentCount].school = chooseSchool();
    studentCount++;

    cout << "\n✅ Student Added Successfully!\n";
}

// -------- ADD TEACHER --------
void addTeacher() {
    cout << "\nEnter Teacher ID: ";
    cin >> teachers[teacherCount].id;

    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, teachers[teacherCount].name);

    cout << "Enter Subject: ";
    getline(cin, teachers[teacherCount].subject);

    teachers[teacherCount].school = chooseSchool();
    teacherCount++;

    cout << "\n✅ Teacher Added Successfully!\n";
}

// -------- DISPLAY STUDENTS --------
void displayStudents() {
    if(studentCount == 0) {
        cout << "\n❌ No students available\n";
        return;
    }

    cout << "\n------ STUDENT LIST ------\n";

    for(int i=0; i<studentCount; i++) {
        cout << "\nStudent " << i+1 << endl;
        cout << "Roll: " << students[i].roll << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "School: " << students[i].school << endl;
    }
}

// -------- SEARCH STUDENT --------
void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    for(int i=0; i<studentCount; i++) {
        if(students[i].roll == roll) {
            cout << "\n✅ Student Found!\n";
            cout << "Roll: " << students[i].roll << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "School: " << students[i].school << endl;
            return;
        }
    }

    cout << "\n❌ Student Not Found!\n";
}

// -------- DELETE STUDENT --------
void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    for(int i=0; i<studentCount; i++) {
        if(students[i].roll == roll) {
            for(int j=i; j<studentCount-1; j++) {
                students[j] = students[j+1];
            }
            studentCount--;
            cout << "\n✅ Student deleted successfully!\n";
            return;
        }
    }
    cout << "\n❌ Student not found!\n";
}

// -------- MAIN MENU --------
int main() {
    int choice;

    do {
        cout << "\n======= UNIVERSITY SCHOOL MANAGEMENT =======\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Display All Students\n";
        cout << "4. Search Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: addTeacher(); break;
            case 3: displayStudents(); break;
            case 4: searchStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "\n✅ Program exited successfully!\n"; break;
            default: cout << "\n❌ Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}
