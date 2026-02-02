#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int appear;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
        appear = 1;
    }
};

class Tree {
public:
    Node* root;
    Tree() {root = nullptr;}

    void insert(int d);
    void insert(Node* node, int d);
    Node* search(Node* node, int d);
    Node* search(int d);
};

void Tree::insert(int d) {
    if (root == nullptr) {
        root = new Node(d);
    } else {
        insert(root, d);
    }
}

void Tree::insert(Node* node, int d) {
    if (d < node->data) {
        if (node->left == nullptr) {
            node->left = new Node(d);
        } else {
            insert(node->left, d);
        }
    } else if (d > node->data) {
        if (node->right == nullptr) {
            node->right = new Node(d);
        } else {
            insert(node->right, d);
        }    
    } else {
        node->appear++;
    }
}

Node* Tree::search(Node* node, int d) {
    if (node == nullptr) {
        return nullptr;
    }
    if (d < node->data) {
        return search(node->left, d);
    } else if (d > node->data) {
        return search(node->right, d);
    } else {
        return node;
    }
}

Node* Tree::search(int d) {
    return search(root, d);
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

    Tree myTree;
    for (int i = 0; i < n; i++) {
        myTree.insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        Node* node = myTree.search(arr[i]);
        if (node->appear == 1) {
            temp[count++] = arr[i];
        }
    }

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