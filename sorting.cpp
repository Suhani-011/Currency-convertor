#include<iostream>
#include<vector>

using namespace std;
class Sort{
    public:

    void selectionSort(vector<int> &arr){
        for(int i = 0 ; i < arr.size()-1 ; i++){
            int minIdx= i;
            for(int j = i+1; j<arr.size();j++){
                while(arr[j] < arr[minIdx]){
                    minIdx = j;
                }
            }
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
    void mergeSort(vector<int> &arr, int low , int high){
        if(low >= high){
            return;
        }
        int mid = (low + high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    void merge(vector<int> &arr, int low ,int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low ; i <= high;i++){
            arr[i] = temp[i - low];
        }
    }
    void display(vector<int> &arr){
        for(int val : arr){
                cout << val << " ";
            }
        cout << endl;
    }
    int binarySearch(vector<int> &arr,int start,int end, int key){
        if(start > end){
            return -1;
        }

        int mid = (start + end)/2;

        if(key == arr[mid]){
            return mid;
        }else if(key < arr[mid]){
            return binarySearch(arr,0,mid,key);
        }else{
            return binarySearch(arr,mid+1,end,key);
        }
    }
};
int main(){
    Sort s1;
    int choice,size;
    do{
        cout<<"\n-------------------------\n";
        cout << "Enter 1 for Selection Sort\n";
        cout << "Enter 2 for Merge Sort\n";
        cout << "Enter 3 for Linear Search\n";
        cout << "Enter 4 for Binary Search\n";
        cout << "Enter 0 to Exit the Program!\n";
        cout<<"\n-------------------------\n";
        cout<<"Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter the size of array :";
                cin >> size;
                
                vector<int> arr(size);

                for(int i = 0 ; i < arr.size(); i++){
                    cout<<"Enter values : ";
                    cin >> arr[i];
                }
                cout<<"\n--------------BEFORE-----------\n";
                s1.display(arr);
                s1.selectionSort(arr);
                cout<<"\n--------------AFTER-----------\n";
                s1.display(arr);
                break;
            }
            case 2:{
                cout << "Enter the size of array :";
                cin >> size;
                
                vector<int> arr(size);

                for(int i = 0 ; i < arr.size(); i++){
                    cout<<"Enter values : ";
                    cin >> arr[i];
                }
                cout<<"\n--------------BEFORE-----------\n";
                s1.display(arr);
                s1.mergeSort(arr,0,arr.size()-1);
                cout<<"\n--------------AFTER-----------\n";
                s1.display(arr);
                break;
            }
            case 3:{
                 cout << "Enter the size of array :";
                cin >> size;
                
                vector<int> arr(size);

                for(int i = 0 ; i < arr.size(); i++){
                    cout<<"Enter values : ";
                    cin >> arr[i];
                }
                cout<<"\n--------------BEFORE-----------\n";
                s1.display(arr);
                int data;
                cout << "Enter the data you want to search : ";
                cin >> data;
                
                for(int i=0 ; i < arr.size() ; i++){
                    if(arr[i] == data){
                        cout << "Element Found at : " << i;
                        return 0;
                    }
                }
                cout << "Element Not Found !";
                break;
            }
            case 4:{
                cout << "Enter the size of array :";
                cin >> size;
                
                vector<int> arr(size);

                for(int i = 0 ; i < arr.size(); i++){
                    cout<<"Enter values : ";
                    cin >> arr[i];
                }
                    
                    s1.selectionSort(arr);
                    s1.display(arr);
                    int key;
                    cout << "\nEnter the key you want index for : ";
                    cin >> key;
                    
                    int idx = s1.binarySearch(arr,0,size-1,key);

                    if(idx == -1){
                        cout<<"\n-------------------------\n";
                        cout << "Element not Found !";
                        cout<<"\n-------------------------\n";
                    }else{
                        cout<<"\n-------------------------\n";
                        cout << "Yayy! Element found at Index : "<<idx;
                        cout<<"\n-------------------------\n";
                    }
                break;
            }
        }
    }while(choice !=0);
}