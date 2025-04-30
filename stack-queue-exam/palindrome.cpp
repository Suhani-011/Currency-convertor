#include<iostream>
using namespace std;
class Stack{
    public:
        int size;
        int count;
        int top;
        int *arr;

    Stack(int size){     
        this->arr = new int[size];
        this->size = size;
        this->top = -1;
        this->count = 0;
    }
    void push(int);
    void pop();
    void isPalindrome(string,int);
};
void Stack::push(int data){
    if(this->top == size - 1){
        cout << "\n------------------------\n";
        cout << "Stack is Full!";
        cout << "\n------------------------\n";
        return;
    }
    this->top++;
    this->arr[this->top] = data;
    this->count++;
    cout << "\n------------------------\n";
    cout << "Data Inserted Successfully!";
    cout << "\n------------------------\n";
}
void Stack::pop(){
    if(this->top == -1){
        cout << "\n------------------------\n";
        cout << "Stack is Empty!";
        cout << "\n------------------------\n";
        return;
    }

    this->arr[this->top] = 0;
    this->top++;
    this->count--;
    cout << "\n------------------------\n";
    cout << "Data Removed Successfully!";
    cout << "\n------------------------\n";
}
void Stack::isPalindrome(string name , int size){
    for(int i = 0; i< size;i++){
        push(name[i]);
    }

    for(int i = 0; i< size;i++){
        if(name[i] != this->top){
            cout <<"Not a Palindrome  "<<endl;
        }
    }
    pop();
    cout<<"Palindrome ";

}
int main(){
    string name;
    cout << "Enter the name :";
    cin >> name;
    int size = name.length();
    Stack stack(size);

    stack.isPalindrome(name,size);
}