#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    int appear;
    Node* next;
    Node(int d, int a) {
        data = d;
        appear = a;
        next = nullptr;
    }
    Node() {
        data = 0;
        appear = 0;
        next = nullptr;
    }
};

class List {
public:
    Node* first;
    Node allNode[10000];
    int size;

    List() {
        first = nullptr;
        size = 0;
    }

    Node* search(int d);
    void insert(int d);
    void temp(int temp[], int& count);
};

Node* List::search(int d) {
    Node* curr = first;
    while (curr != nullptr) {
        if (curr->data == d) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void List::insert(int d) {
    Node* newNode = search(d);
    if (newNode == nullptr) {
        if (first == nullptr) {
            allNode[0] = Node(d, 1);          
            size++;
            first = &allNode[0];
        } else {
            allNode[size] = Node(d, 1);
            allNode[size-1].next = &allNode[size];
            size++;
        }
    } else {
        newNode->appear++;
    }
}

void List::temp(int temp[], int& count) {
    Node* curr = first;
    while (curr != nullptr) {
        if (curr->appear == 1) {
            temp[count++] = curr->data;
        }
        curr = curr->next;
    }
}



void creatArray(string& line, int& i, int& n, int arr[10000]) {
    while (i < line.length()) {
        int sign = 1;
        if (line[i] == '-') {
            sign = -1;
            i++;
        }
        int num = 0;
        while (i < line.length() && line[i] >= '0' && line[i] <= '9') {
            num = num * 10 + (line[i] - '0');
            i++;
        }
        arr[n++] = sign * num;
        i++;
    }
}

void printAns(int temp[], int count) {
    if (count > 0) {
        cout << temp[0];
        for (int i = 1; i < count; i++) {
            cout << " " << temp[i];
        }
        cout << endl;
    }
}

void findUnique(string line) {
    int i = 0;
    int n = 0;
    int arr[10000];
    int temp[10000];
    int count = 0;
    creatArray(line, i, n, arr);

    List* list = new List();
    for (int i = 0; i < n; i++) {
        list->insert(arr[i]);
    }
    list->temp(temp, count);

    printAns(temp, count);
}

int main() {
    string line;
    getline(cin, line);
    while (line != "") {
        findUnique(line);
        getline(cin, line);
    }        
    return 0;
}