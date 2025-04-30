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
    void display();
    bool isEmpty();
    bool isFull();
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
void Stack::display(){
    if(this->top == -1){
        cout << "\n------------------------\n";
        cout << "Stack is Empty...!";
        cout << "\n------------------------\n";
        return;
    }
    cout << "------"<<endl;
    for(int i=this->count-1; i>=0;i--){
        cout<<"| " << this->arr[i]<<" |"<<endl;
    }
    cout << "------"<<endl;
}
bool Stack::isFull(){
    return this->count == this->size? true : false;
}
bool Stack::isEmpty(){
    return this->top == -1? true : false;
}
int main(){
    Stack stack(5);
    int choice;
    do{
        cout << "\n------------------------\n";
        cout << "Enter 1 to PUSH" <<endl;
        cout << "Enter 2 to POP" <<endl;
        cout << "Enter 3 to DISPLAY" <<endl;
        cout << "Enter 4 to Check if Stack is Full" <<endl;
        cout << "Enter 5 to Check if Stack is Empty" <<endl;
        cout << "Enter 0 to EXIT"<<endl;
        cout << "\n------------------------\n";
        cout << "Enter your choice : ";
        cin >>choice;

        switch(choice){
            case 1:{
                int data;
                cout << "Enter the data you want to insert : ";
                cin >> data;


                stack.push(data);
                break;
            }
            case 2:{
                stack.pop();
                break;
            }
            case 3:{
                stack.display();
                break;
            }
            case 4:{
                if(stack.isFull() == true){
                    cout << "\n------------------------\n";
                    cout << "Stack is Full!";
                    cout << "\n------------------------\n";
                }else{
                    cout << "\n------------------------\n";
                    cout << "Stack is Not Full!";
                    cout << "\n------------------------\n"; 
                }
                break;
            }
            case 5:{
                if(stack.isEmpty() == true){
                    cout << "\n------------------------\n";
                    cout << "Stack is Empty!";
                    cout << "\n------------------------\n";
                }else{
                    cout << "\n------------------------\n";
                    cout << "Stack is Not Empty!";
                    cout << "\n------------------------\n"; 
                }
                break;
            }
            case 0:{
                cout << "Invalid Choice !";
                break;
            }
        }

    }while(choice != 0);

    return 0;
}