#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class Sort {
public:
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high){
            return;
        }

        int mid = (low + high) / 2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high){
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void display(vector<int>& arr) {
        for (int val : arr) {
            cout << val << " ";
        }
        cout << "\n-----------------------------\n";
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    int count;
    Node* head;

    LinkedList() {
        this->head = NULL;
        this->count = 0;
    }

    void insertAtStart(int data) {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;

        this->count++;

        cout <<"\n-------------------------------\n";
        cout <<"Data Inserted Successfully !";
        cout <<"\n-------------------------------\n";
    }
     bool checkEmpty(){
            return (this->count == 0 || this->head == NULL) ? true : false;
    }
    void insertAtEnd(int data) {
         Node *newNode = new Node(data);
            if(checkEmpty() ==  true){
                this->head = newNode;
            }else{
                Node *temp = NULL;
                temp = head;
                if(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            this->count++;

            cout <<"\n-------------------------------\n";
            cout <<"Data Inserted Successfully !";
            cout <<"\n-------------------------------\n";
    }

    void insertAtAny(int data, int pos) {
        Node *newNode = new Node(data);
            Node *temp = this->head;

            if(pos < 0 || this->count < pos){
                cout << "Invalid position...";
                return;
            }

            if(checkEmpty() ==  true || pos == 0){
                newNode->next = this->head;
                this->head = newNode;
            } else{
                for(int i = 0; i < pos-1 ;i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;

                cout <<"\n-------------------------------\n";
                cout <<"Data Inserted Successfully !";
                cout <<"\n-------------------------------\n";
            }

            this->count++;
    }

    void updateAtAny(int data, int pos) {
        Node *temp = this->head;

        if(pos < 0 || this->count < pos){
            cout << "Invalid position...";
            return;
        }
        for(int i = 0; i < pos ;i++){
            temp = temp->next;
        }
        temp->data = data;

        cout <<"\n-------------------------------\n";
        cout <<"Data Updated Successfully !";
        cout <<"\n-------------------------------\n";
    }

    void deleteAtStart() {
        if(checkEmpty() ==  true ){
                cout << "The List is already Empty!";
                return;
        }
        else{
            Node *temp = this->head;
            this->head = head->next;
            delete temp;
            temp = NULL;

            cout <<"\n-------------------------------\n";
            cout <<"Data Deleted Successfully !";
            cout <<"\n-------------------------------\n";
        }
    }

    void display() {
        Node* temp = this->head;
        cout << "\n-----------------------------\n";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
        cout << "\n-----------------------------\n";
    }
};

int main() {
    int choice, menuch;
    LinkedList l1;
    stack<int> st;
    Sort s1;

    do {
        cout << "\n-----------------------------\n";
        cout << "Enter 1 to perform STACK operations\n";
        cout << "Enter 2 to perform LINKED LIST operations\n";
        cout << "Enter 3 to perform MERGE SORT\n";
        cout << "Enter 0 to EXIT\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                do {
                    cout << "\n------------------------\n";
                    cout << "Enter 1 to PUSH" << endl;
                    cout << "Enter 2 to POP" << endl;
                    cout << "Enter 3 to DISPLAY" << endl;
                    cout << "------------------------\n";
                    cout << "Enter your choice : ";
                    cin >> menuch;

                    switch (menuch) {
                        case 1: {
                            int data;
                            cout << "Enter data to insert: ";
                            cin >> data;
                            st.push(data);
                            break;
                        }
                        case 2:
                            st.pop();
                            break;
                        case 3:
                            
                            break;
                        case 0:
                            break;
                    }
                } while (menuch != 0);
                break;
            }

            case 2: {
                do {
                    cout << "\n-----------------------------\n";
                    cout << "Enter 1 to Insert at Start" << endl;
                    cout << "Enter 2 to Insert at End" << endl;
                    cout << "Enter 3 to Insert at Position" << endl;
                    cout << "Enter 4 to Update at Position" << endl;
                    cout << "Enter 5 to Delete at Start" << endl;
                    cout << "Enter 6 to Display" << endl;
                    cout << "Enter 0 to EXIT" << endl;
                    cout << "-----------------------------\n";
                    cout << "Enter your choice : ";
                    cin >> menuch;

                    switch (menuch) {
                        case 1: {
                            int data;
                            cout << "Enter data: ";
                            cin >> data;
                            l1.insertAtStart(data);
                            break;
                        }
                        case 2: {
                            int data;
                            cout << "Enter data: ";
                            cin >> data;
                            l1.insertAtEnd(data);
                            break;
                        }
                        case 3: {
                            int data, pos;
                            cout << "Enter data: ";
                            cin >> data;
                            cout << "Enter position: ";
                            cin >> pos;
                            l1.insertAtAny(data, pos);
                            break;
                        }
                        case 4: {
                            int data, pos;
                            cout << "Enter new data: ";
                            cin >> data;
                            cout << "Enter position to update: ";
                            cin >> pos;
                            l1.updateAtAny(data, pos);
                            break;
                        }
                        case 5:
                            l1.deleteAtStart();
                            break;
                        case 6:
                            l1.display();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid Choice!" << endl;
                    }
                } while (menuch != 0);
                break;
            }

            case 3: {
                int size;
                cout << "Enter array size: ";
                cin >> size;

                vector<int> arr(size);
                for (int i = 0; i < size; i++) {
                    cout << "Enter value: ";
                    cin >> arr[i];
                }

                cout << "\n-----------BEFORE SORTING-------------\n";
                s1.display(arr);
                s1.mergeSort(arr, 0, arr.size() - 1);
                cout << "\n-----------AFTER SORTING-------------\n";
                s1.display(arr);
                break;
            }

            case 0:
                cout << "Thank you for using DSA operations!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}