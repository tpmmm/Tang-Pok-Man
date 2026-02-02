#include <iostream>
#include <string>
using namespace std;

class ListNode {
private:
    int data;
    ListNode* next;
    friend class List;
public:
    ListNode(int d) {
        data = d;
        next = nullptr;
    }
};

class List {
private:
    ListNode* first;
    string name;
public:
    List(string n = "") {
        name = n;
        first = nullptr;
    }
    // void Print();
    void Initial(ListNode* newNode);
    void Insert(int position, ListNode* newNode);
    void Delete(int position);
    void Reverse(int start, int end);
    void Output(int position);
};

// void List::Print() {
//     ListNode* ptr = first;
//     cout << "List: ";
//     while (ptr != nullptr) {
//         cout << ptr->data << " ";
//         ptr = ptr->next;
//     }
//     cout << endl;
// }

void List::Initial(ListNode* newNode) {
    if (first == nullptr) {
        first = newNode;
    }
    else {
        ListNode* ptr = first;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void List::Insert(int position, ListNode* newNode) {
    if (position == 1) {
        ListNode* ptr = first;
        ptr = first->next;
        first->next = newNode;
        newNode->next = ptr;
    }
    else {
        ListNode* ptr = first;
        for (int i = 1; i < position; i++) {
            if (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            else {return;}
        }
        ListNode* temp = ptr->next;
        ptr->next = newNode;
        newNode->next = temp;
    }
}

void List::Delete(int position) {
    if (position == 1) {
        ListNode* temp = first;
        first = first->next;
        delete temp;
    }
    else {
        ListNode* ptr = first;
        for (int i = 1; i < position; i++) {
            if (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            else {return;}
        }
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}

void List::Reverse(int start, int end) {
    ListNode* dummy = new ListNode(0);
    dummy->next = first;
    ListNode* prev = dummy;

    for (int i = 1; i < start; i++) {
        prev = prev->next;
    }
    ListNode* curr = prev->next;
    ListNode* nextNode = nullptr;
    for (int i = 0; i < end - start; i++) {
        nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
    }
    if (start == 1) {
        first = dummy->next;
    }
    delete dummy;
}

void List::Output(int position) {
    if (position == 1) {
        cout << first->data;
    }
    else {
        ListNode* ptr = first;
        for (int i = 1; i < position; i++) {
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
}


int main() {
    List myList("Integers");
    int numberOfNodes;
    cin >> numberOfNodes;
    for (int i = 0; i < numberOfNodes; i++) {
        int temp;
        cin >> temp;
        ListNode* newNode = new ListNode(temp);
        myList.Initial(newNode);
    }
    int numOfOperation = 0;
    cin >> numOfOperation;
    int operation;
    for (int i = 0; i < numOfOperation; i++) {
        cin >> operation;
        switch (operation)
        {
        case 1:
        {
            int temp, position;
            cin >> position >> temp;
            ListNode* val = new ListNode(temp);
            myList.Insert(position, val);
            break;
        }
        case 2:
        {
            int position;
            cin >> position;
            myList.Delete(position);
            break;
        }
        case 3:
        {
            int start, end;
            cin >> start >> end;
            myList.Reverse(start, end);
        }
        break;
        case 4:
        {
            int position;
            cin >> position;
            myList.Output(position);
            break;    
        }
        default:
            break;
        }
        // myList.Print();
    }
    return 0;
}