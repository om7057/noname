#include<iostream>
using namespace std;




int main(){
     int n;
     cout<<"Enter the size of the array\n";
     cin>>n;
     int arr[n];
     cout<<"Enter the array elemetns\n";
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     for(int i=0;i<n;i++){
        int minIndex=i;     
        for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minIndex]){
                    minIndex=j;
                }
        }
        swap(arr[minIndex],arr[i]);
     }

    for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
    }



    return 0;
}