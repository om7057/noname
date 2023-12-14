#include<iostream>
using namespace std;
int BinarySearch(int arr[], int n, int key){
int start=0;
int end=n-1;
int mid=start+((end-start)/2);
while(start<=end){
    if(arr[mid]==key){
        return mid;
    }
    if(key>arr[mid]){
       start=mid+1; 
    }
    else{
        end=mid-1;
    }
    mid=start+((end-start)/2);
}
return -1;

}
int main(){
    int n;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array in sorted order:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the element to be searched:"<<endl;
    cin>>key;
    cout<<"The element "<<key<<" is found at location "<<BinarySearch(arr,n,key)<<endl;
    return 0;
}