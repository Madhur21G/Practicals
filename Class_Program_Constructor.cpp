//Edited Program with Copy Constructor (Not containing parameters i)

#include<bits/stdc++.h>
using namespace std;

class a {
private:
	int x;
public:
	a() {
		cout << "Default called \n";
	};
	a(int x1) {
        cout << "Parameterized called " << (x = x1) << endl;
    }
	a(const a &t2, int i) {
		cout << "Copy Constructor called " << i << endl;
		x = t2.x;
	}
	a(const a &t2) {
		cout << "Copy Constructor without i called " << (x = t2.x) << endl;
	}
	a ret_a(a t3, a *temp) { // Copy constructor without i called 30 -> in a t3
		temp->x = temp->x + 20;
		return *temp; // Copy constructor without i called 50 -> in return *temp
	}
	int getx() { return x; }
};

int main() {
	a t1(7);
	a t2(t1, 1);
	cout << "t1.x=" << t1.getx() << endl;
	cout << "t2.x=" << t2.getx() << endl;
	a one1;
	a t4(30);
	a temp(t4, 3); // Copy constructor called 3
	a result_new(one1.ret_a(t4, &temp), 2); // Copy constructor called 2
	cout << "Final Result: " << result_new.getx();
}