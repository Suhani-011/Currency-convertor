#include<iostream>
#include<vector>
using namespace std;

class Calculator{
    public:
        int id;
        string name;

        Calculator(int id,string name){
            this->id = id;
            this->name = name;
        }

        void displayDetails(){
            cout<<"\nName : "<<name<<endl;
            cout<<"ID : "<<id<<endl<<endl;
        }
        int getID(){
            return this->id;
        }
};


int main(){
    vector <Calculator> memory;
    int choice;
    int id;
    string name;
    do{
        cout<<"\n-----------------------------\n";
        cout<<"Enter 1 to ADD Students to the list"<<endl;
        cout<<"Enter 2 to DISPLAY list of Students"<<endl;
        cout<<"Enter 3 to REMOVE a Student from list using ID"<<endl;
        cout<<"Enter 4 to SEARCH for a Student by ID"<<endl;
        cout<<"Enter 0 to EXIT Student Management Sysytem ."<<endl;
        cout<<"-----------------------------\n";
        cout<<"Enter your choice : ";
        cin>> choice;
        
        
        switch(choice){
            case 1:{
                cin.ignore();
                cout<<"Enter the name of Student :";
                getline(cin,name);
                cout<<"Enter the id of Student : ";
                cin >> id;
                memory.push_back(Calculator(id,name));
                
                cout<<"\n-----------------------------\n";
                cout<<"Data Inserted Successfully..."<<endl;
                cout<<"-----------------------------\n";
                break;
            }
            case 2:{
                if(memory.empty()){
                    cout << "There are no Students in the List!";
                }else{
                    for(int i = 0; i<memory.size();i++){
                        memory[i].displayDetails();
                    }
                }
                break;
            }
            case 3:{
                cout<<"Enter the ID of the Student you want to remove : ";
                cin>>id;
                int found = 0;
                for(int i=0; i<memory.size();i++){
                    if(memory[i].getID()== id){
                        memory.erase(memory.begin() + i);
                        found =1;
                    }
                }
                if(found == 0){
                    cout<<"ID not found";
                }else{
                    cout<<"\n-----------------------------\n";
                    cout<<"ID Removed Successfully..."<<endl;
                    cout<<"-----------------------------\n";
                }
                break;
            }
            case 4:{
                cout<<"Enter the ID of the Student to fetch the Details for : ";
                cin>>id;
                int found = 0;
                for(int i=0; i<memory.size();i++){
                    if(memory[i].getID()== id){
                        memory[i].displayDetails();
                        found = 1;
                    }
                }
                if(found == 0){
                    cout<<"\nID not found"<<endl;
                }
                break;
            }
            case 0:{
                cout<<"Thank You! Please Visit again...";
            }
            default:{
                cout << "Invalid Choice !";
                break;
            }
        }

    }while(choice != 0);
    return 0;
}