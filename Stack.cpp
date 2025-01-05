#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

struct node{
    int data;
    node* next;
};

class mystack{
    private:
    node* head;
    
    public:
    mystack();
    int priority(char c);
    void push(char c);
    void pop();
    char top();
    bool empty();
    string infixtopostfix(string s);
    string infixtoprefix(string s);
    int posteval(string s);
    int preeval(string s);
    
};

mystack::mystack(){
    head = NULL;
}

int mystack::priority(char c){
    if(c == '^') return 4;
    else if(c == '*' || c == '/')  return 3;
    else if(c == '+' || c == '-') return 2;
    return 1;
}

void mystack::push(char c){
    node* temp = new node();
    temp->data = c;
    temp->next = head;
    head = temp;
}

void mystack::pop(){
    if(head == NULL){
        return ;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    
}

char mystack::top(){
    if(head == NULL){
        return '\0';
    }
    return head->data;
}

bool mystack::empty(){
    if(head == NULL){
        return true;
    }
    return false;
}

string mystack::infixtopostfix(string s){
    string ans="";
    for(char ch:s){
        if(isalnum(ch)){
            ans += ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            while(!empty() && top() != '('){
                ans += top();
                pop();
            }
            pop();
        }
        else{
            while(!empty() && priority(ch) <= priority(top())){
                 ans += top();
                 pop();
            }
            push(ch);
           
        }
        
    }
    while(!empty()){
        ans+=top();
        pop();
    }
    
    return ans;
}

string mystack::infixtoprefix(string s){
    reverse(s.begin(),s.end());
    for(char &ch:s){
        if(ch == '(') ch =')';
        else if(ch == ')') ch='(';
    }
    string ans = infixtopostfix(s);
    reverse(ans.begin(),ans.end());
    
    return ans;
}

int mystack:: posteval(string postfix){
    for(char ch :postfix){
        if(isalnum(ch)){
            push(ch-'0');
        }
        else{
            int op1 = top();
            pop();
            int op2 = top();
            pop();
            switch(ch){
                case '+':
                push(op2 + op1);
                break;
                case '-':
                push(op2 - op1);
                break;
                case '*':
                push(op2*op1);
                break;
                case '/':
                push(op2 / op1);
                break;
                case '^':
                push(pow(op2,op1));
                break;
            }
        }
    }
    return top();
}


int mystack:: preeval(string prefix){
    reverse(prefix.begin(),prefix.end());
    int ans = posteval(prefix);
    return ans;
}


int main(){
    string s = "(a*b+c)";
    mystack st;
    string postfix = st.infixtopostfix(s);
    string prefix = st.infixtoprefix(s);
    cout<<postfix<<endl;
    cout<<prefix<<endl;
    string postfixn;
    cin>>postfixn;
    cout<<st.posteval(postfixn);
    string prefixn;
    cin>>prefixn;
    cout<<st.preeval(prefixn);
    
    return 0;
}







