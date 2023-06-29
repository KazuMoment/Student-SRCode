#include <iostream>
using namespace std;

int limit;
int flag_search = 0;
int flag_continue = 0;
string code_search;
char choice_continue;


class Node {
public:
    string data_name;
    string data_SRcode;
    string data_subjectCode;
    string data_professor;
    string data_time;
    Node* next;
};

Node* head = NULL;

void InsertNode(string data_name, string data_SRcode, string data_subjectCode, string data_professor, string data_time) {
    Node* n, * current;

    n = new Node();
    n->data_name = data_name;
    n->data_SRcode = data_SRcode;
    n->data_subjectCode = data_subjectCode;
    n->data_professor = data_professor;
    n->data_time = data_time;
    n->next = head;
    head = n;
}

void StudentInput() {
    string data_name, data_SRcode, data_subjectCode, data_professor, data_time;
    for (int i = 0; i < limit; i++) {
        cout << "\n\n--Enter Student's Name " << i + 1 << " out of " << limit << "--" << endl;
        cin >> data_name;
        cout << "--Enter Student's SR Code " << i + 1 << " out of " << limit << "--" << endl;
        cin >> data_SRcode;
        cout << "--Enter Student's Subject Code " << i + 1 << " out of " << limit << "--" << endl;
        cin >> data_subjectCode;
        cout << "Enter Student's Professor " << i + 1 << " out of " << limit << "--" << endl;
        cin >> data_professor;
        cout << "--Enter Student's Subject Time " << i + 1 << " out of " << limit << "--" << endl;
        cin >> data_time;
        cout << endl;


        InsertNode(data_name, data_SRcode, data_subjectCode, data_professor, data_time);
    }
}

void AllStudents() {
    system("CLS");
    Node* current = head;
    int i = 0;
    cout << "All Student Details:" << endl;
    while (current != NULL) {
        cout << "\nStudent No. " << i + 1 << endl;
        cout << current->data_name << endl;
        cout << current->data_SRcode << endl;
        cout << current->data_subjectCode << endl;
        cout << current->data_professor << endl;
        cout << current->data_time << endl;
        current = current->next;
        i++;
    }
}

void OneStudent() {
    system("CLS");
    Node* current = head;
    cout << "Enter the SR Code to display one of the students' information: ";
    cin >> code_search;
    flag_search = 0;
    while (current != NULL) {
        if (code_search == current -> data_SRcode) {
            cout << "Student Details:" << endl;
            cout << current -> data_name << endl;
            cout << current -> data_SRcode << endl;
            cout << current -> data_subjectCode << endl;
            cout << current -> data_professor << endl;
            cout<< current -> data_time << endl;
            flag_search = 1;
            break;
        }
        current = current -> next;
    }

    if (flag_search == 0) {
        cout << "\nThe student with the inputted SR Code does not exist.";
    }
}

int main() {

    cout << "--Welcome to the Student Information Inputter!--" << endl;

    do {
        cout << "How many students' information will be inputted?" << endl;
        while (!(cin >> limit)) {
            cin.clear();
            cout << "You have entered an invalid input. Please try again.\t\t" << endl << endl;
            while (cin.get() != '\n');
        }
    } while (limit < 1);

    StudentInput();
    system("CLS");

    do {
        cout << "Would you like to see all students or see only one?" << "\n1.) All Students\n2.) One Student\n3.) Exit" << endl;
        cin >> choice_continue;

        if (choice_continue == '1') {
            AllStudents();
            cout << endl << endl;
        }
        else if (choice_continue == '2') {
            OneStudent();
            cout << endl << endl;
        }
        else if (choice_continue == '3') {
            cout << "\n\nThank you for using the Student Information Inputter! See you again!" << endl << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl << endl;
            flag_continue = 1;
        }

    } while (choice_continue == '1' || choice_continue == '2' || flag_continue == 1);

    return 0;
}
