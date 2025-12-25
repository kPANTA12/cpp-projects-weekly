#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdio>
using namespace std;

void typeWriter(string text, int delay_ms = 30) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
    cout << endl;
}

class Student {
private:
    string Name, Address, DOB, Email, Roll_no;
    long long Phone, Grade;

public:
    void input() {
        string details, buffer;
        do {
            cout << "Name: ";
            getline(cin, Name);
            cout << "Address: ";
            getline(cin, Address);
            cout << "Date of Birth: ";
            getline(cin, DOB);
            cout << "Email: ";
            getline(cin, Email);
            cout << "Roll Number: ";
            getline(cin, Roll_no);
            cout << "Phone Number: ";
            cin >> Phone;
            cout << "Grade: ";
            cin >> Grade;

            cout << "Name = " << Name << "\t Address = " << Address
                 << "\tEmail = " << Email
                 << "\tRoll Number = " << Roll_no
                 << "\tPhone = " << Phone
                 << "\tGrade = " << Grade << endl;

            cout << "Are These Details Are Ok: ";
            getline(cin, buffer);
            getline(cin, details);

        } while (details == "No" || details == "no" || details == "N" || details == "n");

        fstream out("file.txt", ios::out | ios::app);
        out << Name << "\t" << Address << "\t" << DOB << "\t"
            << Email << "\t" << Roll_no << "\t"
            << Phone << "\t" << Grade << endl;
        out.close();
    }
};

class Mark {
private:
    int n;
    float marks[50];
    string subject[50];

public:
    float input(const string& fileBase) {
        cout << "Enter Number Of Subjects: ";
        cin >> n;
        string filename = fileBase + ".txt";
        ofstream out(filename, ios::app);
        float total = 0;

        for (int i = 0; i < n; i++) {
            cout << "Enter Subject " << i + 1 << " and Marks: ";
            cin >> subject[i] >> marks[i];
            out << subject[i] << "\t" << marks[i] << endl;
            total += marks[i];
        }

        float avg = total / n;
        out << "AVERAGE " << avg << endl;
        out.close();
        return avg;
    }

    float readAverage(const string& filename) {
        ifstream in(filename);
        string key;
        float value = 0;

        while (in >> key >> value) {
            if (key == "AVERAGE") {
                in.close();
                return value;
            }
        }
        in.close();
        return 0;
    }

    void finalinput(const string& finalBase, const string& firstFile, const string& secondFile) {
        float finalAvg = input(finalBase);
        float firstAvg = readAverage(firstFile);
        float secondAvg = readAverage(secondFile);

        float totalPercentage = firstAvg * 0.20f + secondAvg * 0.20f + finalAvg * 0.60f;

        ofstream out(finalBase + ".txt", ios::app);
        out << "\n--- OVERALL RESULT ---\n";
        out << "First Terminal (20%) : " << firstAvg * 0.20f << endl;
        out << "Second Terminal (20%) : " << secondAvg * 0.20f << endl;
        out << "Final Exam (60%) : " << finalAvg * 0.60f << endl;
        out << "TOTAL PERCENTAGE : " << totalPercentage << "%\n";
        out.close();
    }
};

void AddNewStudent() {
    Student S;
    cout << "Enter the given details of Student: " << endl;
    S.input();
}

void AddDetails() {
    string roll;
    cout << "Enter Roll Number of Student: ";
    getline(cin, roll);

    ifstream in("file.txt");
    if (!in) {
        cout << "File not found!\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        string Name, Address, DOB, Email, Roll_no;
        long long Phone, Grade;

        stringstream ss(line);
        getline(ss, Name, '\t');
        getline(ss, Address, '\t');
        getline(ss, DOB, '\t');
        getline(ss, Email, '\t');
        getline(ss, Roll_no, '\t');
        ss >> Phone >> Grade;

        if (Roll_no == roll) {
            int choice;
            cout << "\nWhat You Want to ADD\n";
            cout << "1. First Terminal Exam Marks\n";
            cout << "2. Second Terminal Exam Marks\n";
            cout << "3. Final Exam Marks\n";
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Mark M;
            switch (choice) {
                case 1:
                    M.input(Name + "First");
                    break;
                case 2:
                    M.input(Name + "Second");
                    break;
                case 3:
                    M.finalinput(Name + "Final",
                                 Name + "First.txt",
                                 Name + "Second.txt");
                    break;
                default:
                    cout << "Invalid choice\n";
            }
            in.close();
            return;
        }
    }

    cout << "Student not found!\n";
    in.close();
}
void RemoveStudent() {
    string roll;
    cout << "Enter Roll Number of Student to Remove: ";
    getline(cin, roll);

    ifstream in("file.txt");
    ofstream out("temp.txt");

    if (!in) {
        cout << "File not found!\n";
        return;
    }

    bool found = false;
    string line;

    while (getline(in, line)) {
        string Name, Address, DOB, Email, Roll_no;
        long long Phone, Grade;

        stringstream ss(line);
        getline(ss, Name, '\t');
        getline(ss, Address, '\t');
        getline(ss, DOB, '\t');
        getline(ss, Email, '\t');
        getline(ss, Roll_no, '\t');
        ss >> Phone >> Grade;

        if (Roll_no == roll) {
            found = true;

            // Remove marks files (simple)
            remove((Name + "First.txt").c_str());
            remove((Name + "Second.txt").c_str());
            remove((Name + "Final.txt").c_str());

            continue; // skip writing this student
        }

        out << line << endl;
    }

    in.close();
    out.close();

    remove("file.txt");
    rename("temp.txt", "file.txt");

    if (found)
        cout << "Student removed successfully.\n";
    else
        cout << "Student not found!\n";
}

int main() {
    typeWriter("----Student Report Card System-------------");
    typeWriter("-------------------------------------------");
    typeWriter("1. Add New Student ");
    typeWriter("2. Add The Student New Details");
    typeWriter("3. Remove Student From Database");
        string choice;
        cout << "Enter Your Choice: ";
        getline(cin, choice);

        if (choice == "1") {
            AddNewStudent();
        } else if (choice == "2") {
            AddDetails();
        }else if (choice == "3") {
        RemoveStudent();
        }
    return 0;
}
