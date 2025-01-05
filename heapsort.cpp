#include<iostream>
using namespace std;

class heap{
    
    public:
    
    void heapifymax(int arr[],int n,int i);
    void heapifymin(int arr[],int n,int i);
    void createheapmax(int arr[],int n);
    void createheapmin(int arr[],int n);
    void heapsortmax(int arr[],int n);
    void heapsortmin(int arr[],int n);
    void display(int arr[],int n);
};

void heap :: heapifymax(int arr[],int n,int i){
    int largest = i;
    int lchild = 2*i;
    int rchild = 2*i + 1;

    if(lchild < n && arr[lchild] > arr[largest]){
        largest = lchild;
    }

    if(rchild < n && arr[rchild] > arr[largest]){
        largest = rchild;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapifymax(arr,n,largest);
    }

}

void heap :: heapifymin(int arr[],int n,int i){
    int smallest = i;
    int lchild = 2*i;
    int rchild = 2*i + 1;

    if(lchild < n && arr[lchild] < arr[smallest]){
        smallest = lchild;
    }

    if(rchild < n && arr[rchild] < arr[smallest]){
        smallest = rchild;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapifymin(arr,n,smallest);

    }

}

void heap :: createheapmax(int arr[],int n){
    for(int i = n/2-1;i>=0;i--){
        heapifymax(arr,n,i);
    }

}

void heap :: createheapmin(int arr[],int n){
    for(int i = n/2-1;i>=0;i--){
        heapifymin(arr,n,i);
    }

}

void heap :: heapsortmax(int arr[],int n){
    createheapmax(arr,n);
    for(int i = n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapifymax(arr,i,0);
    }
}

void heap :: heapsortmin(int arr[],int n){
    createheapmin(arr,n);
    for(int i = n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapifymin(arr,i,0);
    }
}

void heap :: display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int ch;
    do{

    }while(ch!= );
    return 0;
}