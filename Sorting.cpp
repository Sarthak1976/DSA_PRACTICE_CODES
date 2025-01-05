#include<bits/stdc++.h>
using namespace std;

class sorting{
    public:
    void selection_sort(int a[],int n){
        for(int i=0;i<n;i++){
            int min = i;
                for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
    
    for (int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
    
    void bubble_sort(int a[],int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    // int a[] = {13 46 24 52 20 9};
    int n;
    
    cout<<"Enter number of elments in the array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements to sort : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    sorting s;
    int ch;
    do{
    cout<<"\n\nEnter 1. to display the original array \n2. Slection sort \n3. Bubble sort"<<endl;
    
    cin>>ch;
    
    
    switch(ch){
    case 1:
    for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    break;
        
    case 2:
    s.selection_sort(a,n);
    break;
    
    case 3:
    s.bubble_sort(a,n);
    break;
    
    case 4:
    cout<<"Exitted !"<<endl;
    break;
    
    default:
    cout<<"Invalid choice!!"<<endl;
    }
    }while(ch!=4);
    
    return 0;
    
}