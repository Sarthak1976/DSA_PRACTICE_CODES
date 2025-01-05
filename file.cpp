#include<iostream>
#include<fstream>
#include<string>

string rollNo,name,division;

class student{
    public:
    void addstudent();
    void displaylist();
    void deletestudent();
    void search();
    void modify();
};

void student :: addstudent(){
    ofstream file("Studentdata.txt",ios::app);
    if(file.is_open()){
        cout<<"Enter information of new student:"<<endl;
        cin.ignore();
        cout<<"Roll NO. : ";
        getline(cin,rollNo);
        cout<<"Name : ";
        getline(cin,name);
        cout<<"Division : ";
        getline(cin,division);

        file<<"\nRoll No:"<<rollNo<<"\nName:"<<name<<"\nDivision:"<<division<<endl;
        file.close();
        cout<<"Student added successfully!!"<<endl;

    }
    else{
        cout<<"Error opening file!!"<<endl;
    }
}

void student :: displaylist(){
    fstream file("Studentdata.txt");
    if(file.is_open){
        string line;
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
    }
    else{
        cout<<"Error opening file!"<<endl;
    }
}

void student :: deletestudent(){
    ifstream file("Studentdata.txt");
    ofstream newfile("temp.txt");

    string delr;
    cout<<"Enter Roll no of student to be deleted:";
    cin>>delr;

    bool found = false;
    if(file.is_open() && newfile.is_open()){
        string line;
        while(getline(file,line)){
            if(line.empty()){
                continue;
            }
            if(line.find("Roll No:"+delr) != string::npos){
                found = true;
                getline(file,line);
                getline(file,line);
                cout<<"Student with Roll no "<<delr<<" deleted successfully!!"<<endl;

            }
            else{
                newfile<<"\n"<<line<<endl;
                getline(file,line);
                newfile<<"\n"<<line<<endl;
                getline(file,line);
                newfile<<"\n"<<line<<endl;
            }
        }
        if(!found){
            cout<<"Student not found!"<<endl;
        }
        file.close();
        newfile.close();
        remove("Studentdata.txt");
        rename("temp.txt","Studentdata.txt");
    }
    else{
        cout<<"Error opening file!"<<endl;
    }
}

