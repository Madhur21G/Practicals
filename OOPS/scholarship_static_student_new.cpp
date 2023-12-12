#include <bits/stdc++.h>
using namespace std;

class scholarship {
public:
    static int no_scholarships;
    string scholarship_name;
    int income;
    int cgpa;
    int scholar_number;
public:
    void getdata() {
        cout << "Enter the name of the scholarship: ";
        cin >> scholarship_name;
        cout << "Enter the maximum income required to be eligible for scholarship: ";
        cin >> income;
        cout << "Enter the minimum cgpa required to be eligible for scholarship: ";
        cin >> cgpa;
        cout << "Enter the Scholarship id/number: ";
        cin >> scholar_number;
    }
    void display_data() {
        cout << "Name of the scholarship: " << scholarship_name << "\n";
        cout << "Minimum CGPA: " << cgpa << "\n";
        cout << "Scholarship ID: " << scholar_number << "\n";
    }
public:
    static void numberofscholarship() {
        cout << "No. of scholarships existing in the IT branch at Delhi Technological University: " << no_scholarships << "\n";
    }
    scholarship() {
        scholarship::no_scholarships++;
        this->getdata();
    }
    ~scholarship() {
        cout << scholarship_name << " was destroyed" << "\n";
    }
};

int scholarship::no_scholarships = 0;

class student {
public:
    string name;
    int cgpa;
    int income;

public:
    void getStudentDetails() {
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter student's CGPA: ";
        cin >> cgpa;
        cout << "Enter student's income: ";
        cin >> income;
    }

    bool isEligible(const scholarship& s) {
        if (cgpa >= s.cgpa && income <= s.income) {
            return true;
        }
        return false;
    }
};


int main() {
    {
        static scholarship sc1;
        sc1.display_data();
    }
    scholarship sc2;
    sc2.display_data();
    scholarship::numberofscholarship();
    student stu;
    stu.getStudentDetails();
    if (stu.isEligible(sc2)) {
        cout << stu.name << " is eligible for the " << sc2.scholarship_name << " scholarship." << endl;
    } else {
        cout << stu.name << " is not eligible for the " << sc2.scholarship_name << " scholarship." << endl;
    }
    return 0;
}
