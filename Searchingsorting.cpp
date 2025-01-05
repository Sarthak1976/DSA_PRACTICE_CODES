#include<bits/stdc++.h>
using namespace std;

class seit {

private:
    int rn;
    float sgpa;
    string name;

public:
    // Default constructor
    seit() {
        rn = 0;
        name = "";
        sgpa = 0.0;
    }

    // Parameterized constructor
    seit(int rn, string name, float sgpa) {
        this->rn = rn;
        this->name = name;
        this->sgpa = sgpa;
    }

    // Method to input data for a single student
    void setdata() {
        cout << "Enter Roll No, Name, and SGPA: ";
        cin >> rn;
        cin.ignore();  // Clear the newline left by 'cin'
        getline(cin, name);  // Read the name with spaces
        cin >> sgpa;
    }

    // Method to display data for a single student
    static void display(seit stu[], int size)  {
        cout<<"Roll no. \t"<<"Name \t"<<"SGPA \t"<<endl;
        for(int i=0;i<size;i++){
            cout<<stu[i].rn<<" "<<stu[i].name<<" "<<stu[i].sgpa<<endl;
            
        }
    }

    // Method to sort students based on roll number using bubble sort
    static void rollbubblesort(seit stu[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (stu[j].rn > stu[j + 1].rn) {
                    // Swap entire objects
                    swap(stu[j], stu[j + 1]);
                }
            }
        }
    }
    
    static void nameinsertsort(seit stu[],int size){
        for(int i=1;i<size;i++){
            string key = stu[i].name;
            int keyrn = stu[i].rn;
            float keysgpa = stu[i].sgpa;
            int j=i-1;
            while(j>=0 && stu[j].name>key){
                stu[j+1].name = stu[j].name;
                stu[j+1]=stu[j];
                j--;
            }
            stu[j+1].name=key;
            stu[j+1].rn=keyrn;
            stu[j+1].sgpa=keysgpa;
        }
    }

    static int partition(seit stu[],int s,int e){
        float pivot = stu[s].sgpa ;
        int cnt = 0;
        for(int i=s+1;i<=e;i++){
            if(stu[i].sgpa>=pivot)
                cnt++;
        }
        int correctindex = s+cnt;
        swap(stu[s],stu[correctindex]);

        int i=s,j=e;
        while(i<correctindex && j>correctindex){
            while(stu[i].sgpa>stu[correctindex].sgpa){
                i++;
            }
            while(stu[j].sgpa<stu[correctindex].sgpa){
                j--;
            }
            if(i<correctindex && j>correctindex){
                swap(stu[i++],stu[j--]);
            }
        }
        return correctindex;
    }

    static void topperquicksort(seit stu[],int s,int e){
        //base case
        if(s>=e)
            return;

        int p = partition(stu,s,e);

        topperquicksort(stu,s,p-1);
        topperquicksort(stu,p+1,e);
    }
    
    static void sgpasearch(seit stu[],int size,float key){
        int m=0;
        for(int i=0;i<size;i++){
            if(key==stu[i].sgpa){
                cout<<"Roll no. : "<<stu[i].rn<<"\n Name : "<<stu[i].name<<"\nSGPA : "<<stu[i].sgpa<<endl;
                m=1;
            }
            
        }
        if(m==0)
            cout<<"No such record found !!"<<endl;
            
    }
    
    static void namesearch(seit stu[],int size,string key){
        nameinsertsort(stu,size);
        int m=0;
        int s=0;
        int e=size-1;
        int mid = (s+e)/2;
        while(s<=e){
            if (stu[mid].name==key){
                 cout<<"Roll no. : "<<stu[mid].rn<<"\nName : "<<stu[mid].name<<"\nSGPA : "<<stu[mid].sgpa<<endl;
                 m=1;
                 break;
            }
            else if(stu[mid].name>key){
                e=mid-1;
            }
            else if(stu[mid].name<key){
                s =mid+1;
            }
            mid = (s+e)/2;
        }
        if (m==0)
            cout<<"No such Record Found!!"<<endl;
    } 
};

int main() {
    int size;
    cout << "Enter the number of students you want to add to the database: ";
    cin >> size;

    // Create an array of 'size' objects
    seit stu[size];
     int ch;
    
    do{
    cout<<"\nEnter \n 1 for Adding student to database\n 2 for display of database\n 3 for Roll no. wise sorting \n 4 for Alphabetical Sorting \n 5 for Topper List \n 6 for Searching a student by his or her SGPA \n 7 for Searching a student by name \n 8 for Exit\n"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
    // Input data for each student
    for (int i = 0; i < size; i++) {
        stu[i].setdata();
    }
    break;
    case 2:

    // Display students
    seit::display(stu,size);
    break;
    
    case 3:
    // Sort students by roll number
    seit::rollbubblesort(stu, size);
    cout<<"Sorted acoording to roll no. !!"<<endl;
    break;
    
    case 4:

    //Sort Students by their name
    seit::nameinsertsort(stu,size);
    
    cout<<"Alphabetical sorting done!!"<<endl;
    break;
    
    case 5:
    
    //topper list by quicksort
    seit::topperquicksort(stu,0,size-1);
    cout<<"Sorted according to sgpa!!"<<endl;
    break;
    
    case 6:{
    cout<<"Enter the sgpa to search : ";
    float inp ;
    cin>>inp;
    seit::sgpasearch(stu,size,inp);
    
    break;
    }
    
    case 7:{
    cout<<"Enter the name you want to search : ";
    string key;
    cin>>key;
    seit::namesearch(stu,size,key);
    
    break;
    }
    case 8:
    cout<<"Exitted Successfully!!"<<endl;
    break;
    
    default :
    cout<<"Enter Correct Choice!!"<<endl;
    
    }
    }while(ch!=8);

    return 0;
}
