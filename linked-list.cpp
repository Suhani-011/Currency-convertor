#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
    Node(){}
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList : public Node{
    public:
        int count;
        Node *head;

    LinkedList(){
        this->count = 0;
        this->head = NULL;
    }
    bool checkEmpty(){
        return (count == 0 || this->head == NULL)? true : false;
    }
    int insertAtStart(int data){
        Node *newNode = new Node(data);
        
        newNode->next = this->head;
        this->head = newNode;
        this->count++;

        cout << "\n----------------------------------\n";
        cout << "Data Inserted successfully !";
        cout << "\n----------------------------------\n";

    }
    int insertAtEnd(int data){
        Node *newNode = new Node(data);
        Node *temp = NULL;
        if(checkEmpty() == true){
            this->head = newNode;
        }else{
            temp = this->head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        this->count++;
        cout << "\n----------------------------------\n";
        cout << "Data Inserted successfully !";
        cout << "\n----------------------------------\n";  
    }
    void displayList(){
        Node *temp = NULL;
        temp = this->head;
        cout << "\n----------------------------------\n";  
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        cout << "NULL";
        cout << "\n----------------------------------\n";  
    }
    void deleteAtAny(int pos){
        Node *prev = NULL;
        Node *current = NULL;

        if(pos < 0 || count < pos){
            cout << "Invalid Position!"<<endl;
            return;
        }else{
            prev = this->head;
            current = this->head;
            if(pos == 0){
                this->head = head->next;
                delete current;
                current = NULL;
            }else{
                
                for(int i = 0 ; i < pos-1 ; i++){
                    prev = prev->next;
                }
                for(int i = 0 ; i < pos ; i++){
                    current = current->next;
                }

                prev->next = current->next;
                delete current;
                current = NULL;
                prev = NULL;
                delete prev;
                }

            this->count--;

            cout << "\n----------------------------------\n";
            cout << "Data Deleted successfully !";
            cout << "\n----------------------------------\n";  
        }
    }
    void SearchAtAny(int pos){
        Node *temp = NULL;
        temp = this->head;
        if(pos < 0 || count < pos){
            cout << "Invalid Position!"<<endl;
            return;
        }else{
            for(int i = 0; i < count ; i++){
                if(pos == i){
                    cout << temp->data;
                }
                temp = temp->next;
            }
        }
    }

};
int main(){
    LinkedList list;
    int choice;
    int data,pos;
    do{
        cout << "\n----------------------------------\n";
        cout << "Enter 1 to Insert At Start"<<endl;
        cout << "Enter 2 to Insert At End"<<endl;
        cout << "Enter 3 to Search a Node"<<endl;
        cout << "Enter 4 to Display the List"<<endl;
        cout << "Enter 5 to Delete at any position"<<endl;
        cout << "----------------------------------\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1 :{
                cout << "Enter the data you want to insert : ";
                cin >> data;

                list.insertAtStart(data);
                break;
            }
            case 2 :{
                cout << "Enter the data you want to insert : ";
                cin >> data;

                list.insertAtEnd(data);
                break;
            }
            case 3 :{
                cout << "Enter the position you want to see the data : ";
                cin >> pos;

                list.SearchAtAny(pos);
                break;
            }
            case 4 :{
                list.displayList();
                break;
            }
            case 5 :{
                cout << "Enter the position you want to delete : ";
                cin >> pos;

                list.deleteAtAny(pos);
                break;
            }
            case 0 :{
                cout << "Exiting Linked List Program !";
                break;
            }
        }
    }while(choice != 0);
}