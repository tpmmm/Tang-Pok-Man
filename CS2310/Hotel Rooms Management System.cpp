#include <iostream>
#include <string>
using namespace std;

class Room {
public:
	string name;
	string floor;
	int price;
	int status;
	void set(string n, string f, int p, int s);
	void book(string name) {
		if (this->name == name && status == 1) {
			status = 0;
			cout << "Succeed!" << endl << endl;
		}
		else if (this->name == name && status == 0) {
			cout << "Sorry, the room is not available. Try again." << endl << endl;
		}
	}
	void checkout(string name) {
		if (this->name == name && status == 0) {
			status = 1;
			cout << "Thanks for using our services!" << endl << endl;
		}
		else if (this->name == name && status == 1) {
			cout << "This room is not booked yet!" << endl << endl;
		}
	}
	void print() {
		cout << name << " " << floor << " " << price << " " << status << endl;
	}
	bool operator>(const Room& r) {
		if (price > r.price) {
			return true;
		}
		else if (price == r.price && name.compare(r.name) > 0) {
			return true;
		}
		else {
			return false;
		}
	}
};
void Room::set(string n, string f, int p, int s) {
	name = n;
	floor = f;
	price = p;
	status = s;
}

class Hotel {
public:
	Room r;
	Room* rPtr;
	int num;
	Hotel() {
		rPtr = 0;
		num = 0;
	}
	Hotel(int n) {
		num = n;
		rPtr = new Room[num];
	}
	~Hotel() {
		delete[] rPtr;
		rPtr = NULL;
	}
	void setRoom(int idx, string n, string f, int p, int s) {
		if (idx >= 0 && idx < num) {
			rPtr[idx].set(n, f, p, s);
		}
	}
	void bookRoom(string rname) {
		for (int i = 0; i < num; i++) {
			if (rPtr[i].name == rname) {
				rPtr[i].book(rname);
			}
		}
	}
	void checkoutRoom(string rname) {
		for (int i = 0; i < num; i++) {
			if (rPtr[i].name == rname) {
				rPtr[i].checkout(rname);
			}
		}
	}
	void listRooms() {
		cout << "All rooms in the hotel:" << endl;
		sortRooms();
		for (int i = 0; i < num; i++) {
			rPtr[i].print();
		}
		cout << endl;
	}
private:
	void sortRooms() {
		Room temp;
		for (int i = 0; i < num; i++) {
			for (int j = num - 1; j > i; j--) {
				if (rPtr[j - 1] > rPtr[j]) {
					temp = rPtr[j - 1];
					rPtr[j - 1] = rPtr[j];
					rPtr[j] = temp;
				}
			}
		}
	}

};

// TODOs
int main() {
	int n;
	Room r;
	cout << "Input the number of rooms:" << endl;
	// TODOs
	cin >> n;
	Hotel h(n);
	string name, floor;
	int price, status;
	cout << "Input the information of each room (room name, floor, price, status):" << endl << endl;;
	for (int i = 0; i < n; i++) {
		cin >> name >> floor >> price >> status;
		h.setRoom(i, name, floor, price, status);
	}
	h.listRooms();
	string cmd, inf;
	do {
		cout << "Input the instruction:" << endl;
		cin >> cmd;
		if (cmd == "Book") {
			cin >> inf;
			// TODO: book using inf
			h.bookRoom(inf);
		}
		else if (cmd == "Return") {
			cin >> inf;
			// TODO: checkout using inf
			h.checkoutRoom(inf);
		}
		else if (cmd == "List") {
			// TODO:
			h.listRooms();
		}
		else if (cmd == "Leave") {
			// TODO:
			cout << "See you again!" << endl;
			break;
		}
	} while (true);
	return 0;
}