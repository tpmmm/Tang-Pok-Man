#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;

struct Date {
	int day;
	int month;
	int year;
};

struct Employee {
	int id;
	double salary;
	Date date;
};

struct Company {
	Employee employees[N];
	int num;
};

void hire(Company* c) {

	if (c->num == 10) {
		cout << "Department is full" << "\n\n";
	}
	else {
		cout << "Input Employee ID:" << "\n";
		cin >> c->employees[c->num].id;
		cout << "Input Salary:" << "\n";
		cin >> c->employees[c->num].salary;
		cout << "Input Date (dd mm yyyy):" << "\n\n";
		int d, m, y;
		cin >> d >> m >> y;
		c->employees[c->num].date.day = d;
		c->employees[c->num].date.month = m;
		c->employees[c->num].date.year = y;
		(c->num)++;
	}
}

void show(Company& c) {
	if (c.num == 0) {
		cout << "Department is empty" << "\n\n";
	}
	else {
		for (int i = 0; i < c.num; i++) {
			cout << setw(3) << setfill('0') << c.employees[i].id << " ";
			cout << fixed << setprecision(2) << c.employees[i].salary << " ";
			cout << c.employees[i].date.day << "-" << c.employees[i].date.month << "-" << c.employees[i].date.year << "\n";
		}
		cout << "\n";
	}
}

void transfer(Company& c) {
	cout << "Enter the ID to be transferred" << "\n";
	int remove;
	bool check = true;
	cin >> remove;
	for (int i = 0; i < c.num; i++) {
		if (c.employees[i].id == remove) {
			for (int j = i; j < c.num - 1; j++) {
				c.employees[j] = c.employees[j + 1];
			}
			(c.num)--;
			cout << "\n";
			check = false;
		}
	}
	if (check) {
		cout << "The ID cannot be found" << "\n";
		cout << "\n";
	}
}


void sort_id(Company& c) {
	for (int i = 0; i < c.num - 1; i++) {
		for (int j = 0; j < c.num - i - 1; ++j) {
			if (c.employees[j].id > c.employees[j + 1].id) {
				Employee temp = c.employees[j];
				c.employees[j] = c.employees[j + 1];
				c.employees[j + 1] = temp;
			}
		}
	}
}

void sort_salary(Company& c) {
	Employee temp;
    for(int i = 0; i < c.num - 1; i++){
        for(int j = c.num - 1; j > i; j--){
            if((c.employees[j].salary < c.employees[j - 1].salary) || (c.employees[j].salary == c.employees[j - 1].salary && c.employees[j].id < c.employees[j-1].id)){
                temp = c.employees[j];
                c.employees[j] = c.employees[j - 1];
                c.employees[j - 1] = temp;
            }
        }
    } 
}

void sort_date(Company& c) {
	Employee temp;
    for(int i = 0; i < c.num-1; i++){
        for(int j = c.num - 1; j > i ;j--){
            if((c.employees[j].date.year <= c.employees[j - 1].date.year && c.employees[j].date.month <= c.employees[j - 1].date.month && c.employees[j].date.day < c.employees[j - 1].date.day) || (c.employees[j].date.year == c.employees[j - 1].date.year && c.employees[j].date.month == c.employees[j - 1].date.month && c.employees[j].date.day == c.employees[j - 1].date.day && c.employees[j].id < c.employees[j - 1].id)){
                temp = c.employees[j];
                c.employees[j] = c.employees[j - 1];
                c.employees[j - 1] = temp;
            }

        }
    } 
}

void sort(Company& c) {
	int n = 0;
	while (n < 1 || n > 3) {
		cout << "1: Sort by ID" << "\n";
		cout << "2: Sort by Salary" << "\n";
		cout << "3: Sort by Date" << "\n";
		cin >> n;
		switch (n) {
		case 1:
			sort_id(c);
			break;
		case 2:
			sort_salary(c);
			break;
		case 3:
			sort_date(c);
			break;
		}

	}
	cout << "\n";
}

void listOptions(Company* c) {
	int opt = -1;
	while (opt != 0) {
		cout << "~~~~~~~~~Welcome!~~~~~~~~~~" << "\n"
			<< "0: Exit" << "\n"
			<< "1: Hire" << "\n"
			<< "2: Show" << "\n"
			<< "3: Transfer" << "\n"
			<< "4: Sort" << "\n"
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		cin >> opt;
		switch (opt) {
		case 0:
			cout << "Bye!" << "\n";
			break;
		case 1:
			hire(c);
			break;
		case 2:
			show(*c);
			break;
		case 3:
			transfer(*c);
			break;
		case 4:
			sort(*c);
			break;
		}
	}
}

void init(Company* c) {
	c->employees[c->num].id = 4;
	c->employees[c->num].salary = 10500;
	c->employees[c->num].date.day = 15;
	c->employees[c->num].date.month = 1;
	c->employees[c->num].date.year = 2012;
	(c->num)++;
	c->employees[c->num].id = 2;
	c->employees[c->num].salary = 20550;
	c->employees[c->num].date.day = 15;
	c->employees[c->num].date.month = 2;
	c->employees[c->num].date.year = 2017;
	(c->num)++;
	c->employees[c->num].id = 3;
	c->employees[c->num].salary = 10500;
	c->employees[c->num].date.day = 20;
	c->employees[c->num].date.month = 2;
	c->employees[c->num].date.year = 2021;
	(c->num)++;
	c->employees[c->num].id = 1;
	c->employees[c->num].salary = 30100;
	c->employees[c->num].date.day = 20;
	c->employees[c->num].date.month = 2;
	c->employees[c->num].date.year = 2021;
	(c->num)++;
}

int main() {
	Company comp;
	comp.num = 0;
	init(&comp);
	listOptions(&comp);
	return 0;
}