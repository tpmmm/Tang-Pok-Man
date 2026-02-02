#include <bits/stdc++.h>
using namespace std;

class TreeNode {
private:
    int data;
    TreeNode* parent;
    vector<TreeNode*> children;
    friend class Tree;
public:
    TreeNode(int d, TreeNode* p) {
        data = d;
        parent = p;
    }
};

class Tree {
private:
    TreeNode* root;
public:
    Tree() {
        root = nullptr;
    }
    TreeNode* getNewNode(int d, TreeNode* p = nullptr);
    void addChildren(int d, TreeNode* node);
    TreeNode* search(TreeNode* root, int target);
    int getDepth(TreeNode* node);
    int lowestCommonAncestor(TreeNode* p, TreeNode* q);
};

TreeNode* Tree::getNewNode(int d, TreeNode* p) {
    TreeNode* newNode = new TreeNode(d, p);
    if (root == nullptr) {
        root = newNode;
    }
    return newNode;
}
void Tree::addChildren(int d, TreeNode* node) {
    TreeNode* newNode = getNewNode(d, node);
    node->children.push_back(newNode);
}

TreeNode* Tree::search(TreeNode* root, int target) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->data == target) {
        return root;
    }

    for (TreeNode* child : root->children) {
        TreeNode* result = search(child, target);
        if (result != nullptr) 
            return result;
    }
    return nullptr;
}

int Tree::getDepth(TreeNode* node) {
    int depth = 0;
    while (node) {
        ++depth;
        node = node->parent;
    }
    return depth - 1; 
}

int Tree::lowestCommonAncestor(TreeNode* p, TreeNode* q) {
    if (p == root && p == q) {
        return p->data;
    }
    TreeNode* a = p;
    TreeNode* b = q;

    int depthP = getDepth(p);
    int depthQ = getDepth(q);

    if (depthP > depthQ) {
        int diff = depthP - depthQ;
        while (diff--) a = a->parent;
    } else if (depthQ > depthP) {
        int diff = depthQ - depthP;
        while (diff--) b = b->parent;
    }

    while (a != b) {
        a = a->parent;
        b = b->parent;
    }

    return a->data; 
}

int main() {
    Tree myTree;
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int rData, numOfMembers;
        cin >> rData >> numOfMembers;
        TreeNode* root = myTree.getNewNode(rData);
        for (int j = 0; j < numOfMembers - 1; j++) {
            int data, ancestorData;
            cin >> data >> ancestorData;
            TreeNode* ancestor = myTree.search(root, ancestorData);
            myTree.addChildren(data, ancestor);
        }
        int d1, d2;
        cin >> d1 >> d2;
        TreeNode* node1 = myTree.search(root, d1);
        TreeNode* node2 = myTree.search(root, d2);
        cout << myTree.lowestCommonAncestor(node1, node2) << endl;
    }
    return 0;
}

// 1 7 12 3 7 10 7 4 7 8 3 12 3 6 8 5 8 9 5 1 12 11 4 2 4 6 12