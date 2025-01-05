//insertion sort

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={10,9,8,6,40,90,12};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && temp<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}