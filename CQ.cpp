#include<iostream>
using namespace std;

class CQ{
    private :
    int *arr;
    int size;
    int front;
    int rear;

    public:
    CQ(int size);
    void Enqueue(int val);
    void Dequeue();
    void display();
};

CQ::CQ(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1; 
    }

void CQ::Enqueue(int val){
    if((front == 0 && rear == size-1) || (rear = (front-1)%(size-1))){
        cout<<"Queue is full!!";
        return;
    }
    else if(front!=0 && rear == size-1){
        rear = 0;
    }
    else if(front==-1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    arr[rear] = val;
    cout<<"Element is successfully added!!"<<endl;
}

void CQ::Dequeue(){
    if(front == -1){
        cout<<"Cannot delete an element!!"<<<endl;
        return;
    }
    arr[front] = 0;
    else if(front==rear){
        
        front = rear = -1;
    }
    else if(front = size-1){
        
        front = 0;
    }
    else{
        front++;
    }
    cout<<"Element deleted Successfully!!"<<endl;

}

void CQ:: display(){
    for(int i:arr){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n ;
    cout<<"Size of the circular queue is :";
    cin>>n;
    CQ c(n);
    int ch;
    do{
    cout<<"\nMenu\n 1. Enqueue \n2. Dequeue \n3.Display \n4. Exit "<<endl;
    
    switch (ch)
    {
    case 1:
        cout<<"Enter element to Enqueue : ";
        int k;
        c.Enqueue(k);
        break;
    case 2:
        c.Dequeue();
        break;
    case 3:
    c.display();
    break;

    case 4:
        cout<<"Exitted succesfully!!"<<endl;
        break;
    default:
    cout<<"Invalid Chioice!!"<<endl;
        break;
    }
    }while (ch!=4);

}
 

