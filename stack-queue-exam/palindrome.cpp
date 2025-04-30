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
        return;
    }
    this->top++;
    this->arr[this->top] = data;
    this->count++;

}
void Stack::pop(){
    if(this->top == -1){
        return;
    }

    this->arr[this->top] = 0;
    this->top++;
    this->count--;
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