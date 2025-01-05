#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    
    
};

node* buildTree(node* root){
        cout<<"Enter data to insert in node : "<<endl;
        int d;
        cin>>d;
        root = new node(d);
        
        if(d == -1) return NULL;
        
        cout<<"Enter data to enter at left of "<<d<<endl;
        root->left = buildTree(root->left);
        cout<<"Enter data to enter at right of "<<d<<endl;
        root->right = buildTree(root->right);
        return root;
    }
    
void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void recinorder(node* root){
    if(root==NULL) return;
    recinorder(root->left);
    cout << root->data<<" " ;
    recinorder(root->right);
}

void recpreorder(node* root){
    if(root==NULL) return;
    cout << root->data<<" " ;
    recpreorder(root->left);
    recpreorder(root->right);
}

void recpostorder(node* root){
    if(root==NULL) return;
    recpostorder(root->left);
    recpostorder(root->right);
    cout << root->data<<" " ;
}

void itinorder(node* root){
    stack<node*>st;
    node* n = root;
    while(true){
        if(n != NULL){
            st.push(n);
            n = n -> left;
        }
        else{
            if(st.empty()) break;
            n = st.top();
            st.pop();
            cout<<n->data<<" ";
            n = n->right;
        }
    }
}

void itpreorder(node* root){
    if (root == NULL) return;
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right){
            st.push(root->right);
        }
        if(root->left){
            st.push(root->left);
        }
    }
}

void itpostorder(node* root){
    stack<node*>st;
    node* cur = root;
    while(cur!=NULL || !st.empty()){
        if(cur!=NULL){
            st.push(cur);
            cur=cur->left;
        }
        else{
            node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
            
                }
            }
            else{
                cur = temp;
            }
        }
    }
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<endl;
    levelordertraversal(root);
    
    cout<<endl<<"The Recursive Inorder traversal is : ";
    recinorder(root);
    
    
    cout<<endl<<"The Recursive Preorder traversal is : ";
    recpreorder(root);
    
    
    
    cout<<endl<<"The Recursive Postorder traversal is : ";
    recpostorder(root);
    
    cout<<endl<<"The Iterative Inorder traversal is : ";
    itinorder(root);
    
    cout<<endl<<"The Iterative Preorder traversal is : ";
    itpreorder(root);
    
    cout<<endl<<"The Iterative Postorder traversal is : ";
    itpostorder(root);
    
    return 0;
}

