#include <bits/stdc++.h>
using namespace std;

class Marksndancer;

class EastSide {
	int store_area;
	float apparel_cost;
	friend Marksndancer;
public:
	EastSide(int area, int cost) {
		store_area = area;
		apparel_cost = cost;
	}
	float get_cost() {return apparel_cost;}
	friend int total_area(class Marksndancer &m, class EastSide &e);
	friend void inc_cost(class Marksndancer &m, class EastSide &e);
};

class Marksndancer {
	int store_area;
	float furnishing_cost;
	bool sell_kids_furnishings;
	bool sell_other_furnishings;
public:
	Marksndancer(int area, int cost) {
		store_area = area;
		furnishing_cost = cost;
		sell_kids_furnishings = true;
		sell_other_furnishings = true;
	}
	float get_cost() {return furnishing_cost;}
	int use_eastside_area(EastSide &e) {
		this->store_area = this->store_area + e.store_area;
		return this->store_area;
	}
	void disable_other() {sell_other_furnishings = false;}
	friend int total_area(class Marksndancer &m, class EastSide &e);
	friend void inc_cost(class Marksndancer &m, class EastSide &e);
};

int total_area(class Marksndancer &m, class EastSide &e) {
	return m.store_area + e.store_area;
}

void inc_cost(class Marksndancer &m, class EastSide &e) {
	m.furnishing_cost *= 1.5;
	e.apparel_cost *= 1.5;
}

void menu(int* option) {
	static int i = 1;
	if (i == 1) cout << "Marksndancer and EastSide are merging !" << "\n";
	cout << "Please choose one of the following options : " << "\n";
	cout << "Option 1 : Merge and create new stores" << "\n";
	cout << "Option 2 : Share EastSide's space" << "\n";
	cout << "Option 3 : Display  kids furniture and apparel" << "\n";
	cout << "Option 4 : Exit" << "\n";
	cout << "\n";
	cin >> *option;
	i++;
}

int main() {
	Marksndancer marks(1000, 1500);
	EastSide east(500, 13000);
	while (true) {
		int option;
		menu(&option);
		if (option == 1) {
			int new_area = total_area(marks, east);
			cout << "New big store of " << new_area << " sq. metres can be opened" << "\n";
			if (new_area > 1200) {
				cout << "New store opened in a mall";
			}
			else cout << "New store opened in a retail showroom ";
		}
		else if (option == 2) {
			cout << "Marksndancer will share space of Eastside \n";
			int area = marks.use_eastside_area(east);
			cout << "Both share a " << area << " sq metres of space " << "\n";
			inc_cost(marks, east);
			cout << "New Cost of Marksndancer item : " << marks.get_cost() << "\n";
			cout << "New Cost of EastSide item : " << east.get_cost() << "\n";
		}
		else if (option == 3) {
			marks.disable_other();
			cout << "Marksdancer store now stores kids furnishings only " << "\n";
		}
		else if (option == 4) {
			cout << "Exit" << "\n";
			break;
		}
		else cout << "Invalid Option. Select again!";
	}
}