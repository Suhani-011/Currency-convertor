#include<iostream>
using namespace std;

class BankAccount{
    public:
        int accNo;
        string name;
        float balance;

        void createAccount(int accNo , string name , float balance){

            this->accNo = accNo;
            this->name = name;
            this->balance = balance;
    
            cout<<"\n-------------------------"<<endl;
            cout<<"Account Created Successfully !"<<endl;
            cout<<"-------------------------"<<endl;
        };

    void deposit(double amount){
        if(amount < 0){
            balance += amount;
            
            cout<<"\n-------------------------"<<endl;
            cout<<"Amount Deposited Successfully !"<<endl;
            cout<<"-------------------------"<<endl;

        }else{
            cout<<"Invalid Amount !";
        }
    }
    void withdraw(double amount){
        if(amount < balance){
            balance -= amount;
            
            cout<<"\n-------------------------"<<endl;
            cout<<"Amount Deposited Successfully !"<<endl;
            cout<<"-------------------------"<<endl;

        }else if(amount > balance){
            cout<<"Insufficient Balance !";
        }
         else{
            cout<<"Invalid Amount !";
        }
    }
    void displayDetails(){
        cout << "Account Holder name : "<< this->name<<endl;;
        cout << "Account Number : "<< this->AccNo<<endl;;
        cout << "Account Balance: "<< this->balance<<endl;;
    }
        

};
class SavingsAccount : public BankAccount{
    public:
        int interestRate = 5;

        int calculateInterest(){
            float interest = (balance * interestRate)/100;
            return interest;
        };
        void getAccounNo(){
            return accNo;
        };

};
class CurrentAccount : public BankAccount{
    void getAccounNo(){
        return accNo;
    };

};
class FixedDepositAccount : public BankAccount{
    int interestRate = 5;
    void getAccounNo(){
        return accNo;
    };
    int calculateInterest(){
        int time;
        cout<<"Enter the duration in months : ";
        cin>>time;
        float interest = (balance * interestRate * time)/100;
        return interest;
    };

};

int main(){
    const int maxAcc = 5;
    SavingsAccount s1[maxAcc];
    CurrentAccount c1[maxAcc];
    FixedDepositAccount f1[maxAcc];
    int Acc = 0 ;
    int accNo,amount;
    string name;
    int choice;
    bool found = false;
    do{
        cout<<"\n----------------------------"<<endl;
        cout<<"Enter 1 to open a SAVINGS ACCOUNT !"<<endl;
        cout<<"Enter 2 to open a CURRENT ACCOUNT !"<<endl;
        cout<<"Enter 3 to open a FIXED DEPOSIT ACCOUNT !"<<endl;
        cout<<"Enter 4 to DEPOSIT MONEY !"<<endl;
        cout<<"Enter 5 to WITHDRAW MONEY !"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"\n Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter Account no : ";
                cin>>accNo;

                cin.ignore();

                cout<<"Enter Account Holder Name : ";
                getline(cin,name);

                cout<<"Enter the amount : ";
                cin >> amount;

                s1[Acc].createAccount(accNo , name , amount);
                Acc ++;
                break;
            }
            case 2:{

                cout<<"Enter Account no : ";
                cin>>accNo;

                cin.ignore();

                cout<<"Enter Account Holder Name : ";
                getline(cin,name);

                cout<<"Enter the amount : ";
                cin >> amount;

                c1[Acc].createAccount(accNo , name , amount);
                Acc ++;

                break;
            }
            case 3:{
                cout<<"Enter Account no : ";
                cin>>accNo;

                cin.ignore();

                cout<<"Enter Account Holder Name : ";
                getline(cin,name);

                cout<<"Enter the amount : ";
                cin >> amount;

                f1[Acc].createAccount(accNo , name , amount);
                Acc ++;
                break;
            }
            case 4:{

                cout<<"Enter your Account No : ";
                cin >> accNo;
                for(int i = 0; i < Acc ; i++){
                    found = false;
                    if(s1.getAccountNo() == accNo){
                        cout<<"Enter the amount : ";
                        cin>>amount;
                        found = true;
                    }else if(c1.getAccountNo() == accNo){
                        cout<<"Enter the amount : ";
                        cin>>amount;
                        found = true;
                    }else if(f1.getAccountNo() == accNo){
                        cout<<"Enter the amount : ";
                        cin>>amount;
                        found = true;
                    }
                    if(!found){
                        cout<<"Invalid account Number...";
                    }else{
                        if(s1.getAccountNo() == accNo){
                            s1[accNo].deposit(amount);
                        }else if(c1.getAccountNo() == accNo){
                            c1[accNo].deposit(amount);
                        }else if(f1.getAccountNo() == accNo){
                            f1[accNo].deposit(amount);
                        }
                    }
                }

                break;
            }
            case 5:{
                cout<<"Enter your Account No : ";
                cin >> accNo;
            
                for(int i = 0; i < Acc ; i++){
                    found = false;
                    if(s1.getAccountNo() == accNo){
                        cout<<"Enter the amount : ";
                        cin>>amount;
                        found = true;
                    }else if(c1.getAccountNo() == accNo){
                        cout<<"Enter the amount : ";
                        cin>>amount;
                        found = true;
                    }else if(f1.getAccountNo() == accNo){
                        cout<<"Enter the amount : ";
                        cin>>amount;
                        found = true;
                    }
                    if(!found){
                        cout<<"Invalid account Number...";
                    }else{
                        if(s1.getAccountNo() == accNo){
                            s1[accNo].withdraw(amount);
                        }else if(c1.getAccountNo() == accNo){
                            c1[accNo].withdraw(amount);
                        }else if(f1.getAccountNo() == accNo){
                            f1[accNo].withdraw(amount);
                        }
                    }
                }
                break;
            }
            case 0:{
                cout << "Exiting Banking System ! Thank You ....";
                break;
            }

                
        }

    }while(choice != 0);


}