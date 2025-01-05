#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next=NULL){
            delete next;
            this->next=NULL;
        }
    }
    
    
};

void insertathead(Node* &head,int d){
    Node* temp =new Node(d);
    temp->next = head;
    head=temp;
}
void insertattail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail=temp;
    
}

void insertatposition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertathead(head,d);
        return;
    }
    else{
        Node* temp = new Node(d);
        Node* temp1=head;
        int cnt = 1;
        while(cnt<position-1){
            temp1=temp1->next;
            cnt++;
        }
        if(temp1->next=NULL){
            insertattail(tail,d);
            return;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
}

void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node = new Node(5);
    cout<<node->data<<endl;
    cout<<node->next<<endl;
    Node* head = node;
    Node* tail = node;
    insertathead(head,10);
    print(head);
    cout<<endl;
    insertathead(head,15);
    print(head);
    cout<<endl;
    insertattail(tail,89);
    print(head);
    cout<<endl;
    insertatposition(tail,head,3,50);
    print(head);
    return 0;
}