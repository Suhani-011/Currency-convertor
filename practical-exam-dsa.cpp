#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
    int size;
    int count;
    int top;
    int* arr;

    Stack(int size) {
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
        this->count = 0;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int data) {
        if (this->top == size - 1) {
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

    void pop() {
        if (this->top == -1) {
            cout << "\n------------------------\n";
            cout << "Stack is Empty!";
            cout << "\n------------------------\n";
            return;
        }
        this->top--;
        this->count--;
        cout << "\n------------------------\n";
        cout << "Data Removed Successfully!";
        cout << "\n------------------------\n";
    }

    void display() {
        if (this->top == -1) {
            cout << "\n------------------------\n";
            cout << "Stack is Empty...!";
            cout << "\n------------------------\n";
            return;
        }
        cout << "------" << endl;
        for (int i = this->top; i >= 0; i--) {
            cout << "| " << this->arr[i] << " |" << endl;
        }
        cout << "------" << endl;
    }

    bool isEmpty() {
        return this->count == 0;
    }

    bool isFull() {
        return this->count == this->size;
    }
};

class Sort {
public:
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

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
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->count++;

        cout << "\n-----------------------------\n";
        cout << "Data Inserted Successfully !";
        cout << "\n-----------------------------\n";
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            this->head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
        this->count++;
        cout << "\n-----------------------------\n";
        cout << "Data Inserted Successfully !";
        cout << "\n-----------------------------\n";
    }

    void insertAtAny(int data, int pos) {
        if (pos < 0 || pos > count) {
            cout << "Invalid Position!";
            return;
        }

        Node* newNode = new Node(data);
        if (pos == 0 || head == NULL) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
        cout << "\n-----------------------------\n";
        cout << "Data Inserted Successfully !";
        cout << "\n-----------------------------\n";
    }

    void updateAtAny(int data, int pos) {
        if (pos < 0 || pos >= count) {
            cout << "Invalid Position!";
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos; i++) temp = temp->next;
        temp->data = data;

        cout << "\n-----------------------------\n";
        cout << "Data Updated Successfully !";
        cout << "\n-----------------------------\n";
    }

    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is already Empty !";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        cout << "\n-----------------------------\n";
        cout << "Node Deleted Successfully!";
        cout << "\n-----------------------------\n";
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
    Stack stack(5);
    LinkedList l1;
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
                    cout << "1. PUSH\n2. POP\n3. DISPLAY\n4. Check Full\n5. Check Empty\n0. EXIT\n";
                    cout << "------------------------\n";
                    cout << "Enter your choice : ";
                    cin >> menuch;

                    switch (menuch) {
                        case 1: {
                            int data;
                            cout << "Enter data to insert: ";
                            cin >> data;
                            stack.push(data);
                            break;
                        }
                        case 2:
                            stack.pop();
                            break;
                        case 3:
                            stack.display();
                            break;
                        case 4:
                            cout << (stack.isFull() ? "Stack is Full!" : "Stack is Not Full!") << endl;
                            break;
                        case 5:
                            cout << (stack.isEmpty() ? "Stack is Empty!" : "Stack is Not Empty!") << endl;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid Choice!" << endl;
                    }
                } while (menuch != 0);
                break;
            }

            case 2: {
                do {
                    cout << "\n-----------------------------\n";
                    cout << "1. Insert at Start\n2. Insert at End\n3. Insert at Position\n";
                    cout << "4. Update at Position\n5. Delete at Start\n6. Display\n0. EXIT\n";
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
