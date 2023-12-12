// Virtual Function 
// Virtual Destructor

#include <bits/stdc++.h>
using namespace std;

class DTU {
public:
    string roll_no;
    static int cws;
    DTU() {
        cws = 0;
    }
    virtual void project() = 0;
    virtual void evaluation() = 0;
    virtual ~DTU() {
        // Virtual destructor
    }
};

class IT : public DTU {
public:
    void project() {
        cout << "Project submitted by IT Student" << "\n";
        cws = 25;
    }
    void evaluation() {
        cout << "Final Score after submitting project: " << cws << "\n";
    }
};

class ME : public DTU {
public:
    void project() {
        cout << "Project submitted by Mechanical Student" << "\n";
        cws = 25;
    }
    void evaluation() {
        cout << "Final Score after submitting project: " << cws << "\n";
    }
};

int DTU::cws = 0;

int main() {
    DTU* itStudent = new IT;
    DTU* meStudent = new ME;

    itStudent->project();
    itStudent->evaluation();

    meStudent->project();
    meStudent->evaluation();

    // delete itStudent;
    // delete meStudent;

    return 0;
}
