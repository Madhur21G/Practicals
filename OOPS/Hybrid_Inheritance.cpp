#include <bits/stdc++.h>
using namespace std;

class A{
public:
    A() {}
    int a;
    A(int x){
        a = x;
        cout << "A's constructor called" << "\n";
    }
};

class B : virtual public A{
public:
    B() {}
    B(int x) : A(x){
        a = 10 + x;
        cout << "B's constructor called" << "\n";
    }
    void get() { cout << a << "\n"; }
};

class C : public virtual A{
public:
    C() {}
    C(int x) : A(x){
        A();
        a = x + 10;
        cout << "C's constructor called" << "\n";
    }
};

class D : public B, public C{
public:
    D(int x) : C(x), B(x), A(x){
        C();
        B();
        a = x + 10;
        cout << "D's constructor called" << "\n";
    }
};

int main(){
    D temp(10);
    // temp.get();
    return 0;
}