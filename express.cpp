#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct treenode {
    char data;
    treenode* right;
    treenode* left;

    treenode(char d) : data(d), right(NULL), left(NULL) {}
};

class express {
public:
    bool isoperator(char c);
    treenode* ConstructFromPostfix(string& s);
    treenode* ConstructFromPrefix(string& s);
    void recinorder(treenode* t);
    void recpreorder(treenode* t);
    void recpostorder(treenode* t);
    void itinorder(treenode* t);
    void itpreorder(treenode* t);
    void itpostorder(treenode* t);
};

bool express::isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

treenode* express::ConstructFromPostfix(string& s) {
    stack<treenode*> st;
    for (char c : s) {
        if (isoperator(c)) {
            treenode* node = new treenode(c);
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
            st.push(node);
        } else {
            st.push(new treenode(c));
        }
    }
    return st.top();
}

treenode* express::ConstructFromPrefix(string& s) {
    reverse(s.begin(), s.end());
    return ConstructFromPostfix(s);
}

void express::recinorder(treenode* root) {
    if (root) {
        recinorder(root->left);
        cout << root->data << ' ';
        recinorder(root->right);
    }
}

void express::recpreorder(treenode* root) {
    if (root) {
        cout << root->data << ' ';
        recinorder(root->left);
        recinorder(root->right);
    }
}

void express::recpostorder(treenode* root) {
    if (root) {
        recinorder(root->left);
        recinorder(root->right);
        cout << root->data << ' ';
    }
}

void express::itinorder(treenode* root) {
    stack<treenode*> st;
    treenode* current = root;
    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << ' ';
        current = current->right;
    }
}

void express::itpreorder(treenode* root) {
    if (root == NULL) return;
    stack<treenode*> st;
    st.push(root);
    while (!st.empty()) {
        treenode* current = st.top();
        st.pop();
        cout << current->data << ' ';
        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
    cout << endl;
}

void express::itpostorder(treenode* root) {
    if (root == NULL) return;
    stack<treenode*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        treenode* current = st1.top();
        st1.pop();
        st2.push(current);
        if (current->left) st1.push(current->left);
        if (current->right) st1.push(current->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << ' ';
        st2.pop();
    }
    cout << endl;
}

int main() {
    express e;
    treenode* Postfixtree = NULL;
    treenode* Prefixtree = NULL;
    int choice;
    string post, pre;

    do {
        cout << "\nMenu\n1. Contruct from Postfix Expression \n2. Construct from Prefix Expression \n3.Recursive inorder traversal \n4.Recursive preorder traversal \n5.Recursive postorder traversal \n6.Iterative inorder traversal \n7.Iterative preorder traversal \n8.Iterative postorder traversal \n9.Exit\n\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Postfix Expression: ";
            cin >> post;
            Postfixtree = e.ConstructFromPostfix(post);
            cout << "Tree created Successfully!";
            break;

        case 2:
            cout << "Enter Prefix Expression: ";
            cin >> pre;
            Prefixtree = e.ConstructFromPrefix(pre);
            cout << "Tree created Successfully!";
            break;

        case 3:
            cout << "Recursive Inorder Traversal: ";
            e.recinorder(Postfixtree);
            cout << endl;
            break;

        case 4:
            cout << "Recursive Preorder Traversal: ";
            e.recpreorder(Postfixtree);
            cout << endl;
            break;

        case 5:
            cout << "Recursive Postorder Traversal: ";
            e.recpostorder(Postfixtree);
            cout << endl;
            break;

        case 6:
            cout << "Non-recursive Inorder Traversal: ";
            e.itinorder(Postfixtree);
            cout << endl;
            break;

        case 7:
            cout << "Non-recursive Preorder Traversal: ";
            e.itpreorder(Postfixtree);
            cout << endl;
            break;

        case 8:
            cout << "Non-recursive Postorder Traversal: ";
            e.itpostorder(Postfixtree);
            cout << endl;
            break;

        case 9:
            cout << "Exited Successfully!!" << endl;
            break;

        default: 
            cout << "Invalid Choice!!" << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}
