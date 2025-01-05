#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertIntoBST(node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}



void inorder(node *node)
{
    if (node)
    {
        inorder(node->left);
        cout << node->data << ' ';
        inorder(node->right);
    }
}

void preorder(node *node)
{
    if (node)
    {
        cout << node->data << ' ';
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(node *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << ' ';
    }
}

void search(node *root, int k)
{
    if (root == NULL)
        cout<< "Element not found!!"<<endl;
    if (root->data == k)
        cout<< "Element found!!"<<endl;
    if (root->data > k)
    {
        search(root->left, k);
    }
    if(root->data < k)
        {
            search(root->right, k);
        }
}

node *minVal(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *maxVal(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

node *deletefrombst(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // 1 right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletefrombst(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletefrombst(root->left, val);
        return root;
    }
    else
    {
        root->right = deletefrombst(root->right, val);
        return root;
    }
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

int depth(node* root){
    if(root == NULL) return 0;
    
    int lh = depth(root->left);
    int rh = depth(root->right);
    
    return  1+max(lh,rh);
}

void parentchild(node* root){
    if(root == NULL) return ;
    if(root->left || root->right){
    cout<<endl<<"Parent :"<<root->data<<endl;
    
    if(root->left){
    cout<<"Its Child 1 :"<<root->left->data<<endl;
    }
    if(root->right){
    cout<<"Its Child 2 :"<<root->right->data<<endl;
    }
    }
    parentchild(root->left);
    parentchild(root->right);
}

void leafnodes(node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    leafnodes(root->right);
    leafnodes(root->left);
}


void mirror(node* root, node*& mroot) {
    if (root == NULL) {
        mroot = NULL;
        return;
    }
    
    mroot = new node(root->data);

    
    mirror(root->left, mroot->right);
    mirror(root->right, mroot->left);
}

   


void copy(node* root,node*& croot){
    if(root == NULL) return ;
    int d = root->data;
    insertIntoBST(croot,d);
    copy(root->left,croot);
    copy(root->right,croot);
    
}


int main()
{
    node *root = NULL;
    int n;

    do
    {
        cout << "\n\nEnter 1. for insertion \n2.for Deletion \n3. for Searching \n4. for Inorder Traversal \n5. for Preorder Traversal \n6. for Postorder Traversal \n7. for Levelwise display of the tree \n8. for Depth of the tree \n9. for list of Parent and childs \n10. for Leaf Nodes of the tree \n11. for creating copy of the Tree  \n12. for Mirror Image of the Tree \n13. to Exit.\n" << endl;
        cin >> n;
        cout<<endl;
        switch (n)
        {
        case 1:
            cout << "Enter data to create BST : ";
            takeInput(root);
            break;
        case 2:
            cout<<"Enter the element to delete : ";
            int n;
            cin>>n;
            deletefrombst(root,n);
            cout<<"Element Deleted Successfully!!"<<endl;
            break;
        case 3:
            cout << "Enter the element to search : ";
            int k;
            cin >> k;
            search(root, k);
            break;

        case 4:
            cout << "Inorder Traversal : ";
            inorder(root);
            break;
        case 5:
            cout << "Preorder Traversal: ";
            preorder(root);
            break;
        case 6:
            cout << "Postorder Traversal: ";
            postorder(root);
            break;
        case 7:
	        cout<<"Levelwise Tree Traversal: "<<endl;
	        levelordertraversal (root); 
            break;
        case 8:
            cout<<"Depth of the tree is "<<depth(root)-1;
            break;
        case 9:
            cout<<endl<<"LIST : "<<endl;
            parentchild( root);
            break;
        case 10:
            cout<<"Leaf Nodes :";
            leafnodes(root);
            break;
        case 11:{
            node* croot = NULL ;
            copy(root,croot);
            cout<<"Original Tree : "<<endl;
            levelordertraversal(root);
            cout<<endl<<"Copy of the Tree : "<<endl;
            levelordertraversal(croot);
            
        }
        break;
        case 12:{
            node* mroot = root ;
            mirror(root,mroot);
            cout<<"Original Tree : "<<endl;
            levelordertraversal(root);
            cout<<"Mirror Image: "<<endl;
            levelordertraversal(mroot);
            cout<<endl<<"Inorder of mirror image : ";
            inorder(mroot);
            cout<<endl<<"Preorder of mirror image: ";
            preorder(mroot);
            cout<<endl<<"postorder of mirror image: ";
            postorder(mroot);
            
            
        }
        break;
        case 13:
            cout << "Exitted Successfully!!" << endl;
            break;
        default:
            cout << "Invalid Choice!!" << endl;
            break;
        }
    } while (n != 13);
    return 0;
}