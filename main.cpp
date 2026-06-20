#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            Student s;
            cout << "Enter Roll Number: ";
            cin >> s.roll;

            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, s.name);

            cout << "Enter Marks: ";
            cin >> s.marks;

            students.push_back(s);
            cout << "Student Added Successfully!\n";
        }

        else if(choice == 2) {
            if(students.empty()) {
                cout << "No Records Found!\n";
            } else {
                cout << "\nStudent Records:\n";
                for(auto &s : students) {
                    cout << "Roll: " << s.roll
                         << ", Name: " << s.name
                         << ", Marks: " << s.marks << endl;
                }
            }
        }

        else if(choice == 3) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;

            bool found = false;
            for(auto &s : students) {
                if(s.roll == roll) {
                    cout << "Record Found!\n";
                    cout << "Name: " << s.name
                         << ", Marks: " << s.marks << endl;
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Student Not Found!\n";
        }

    } while(choice != 4);

    cout << "Thank You!\n";
    return 0;
}
