#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

//Creates an array of length len1 and len2 respectively at the runtime itself
    int *first=new int[len1];
    int *second=new int[len2];


//Copy To Two Broken arrays
    int mainArrayIndex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }   
    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

//Merge Two Sorted Arrays
    int index1=0,index2=0;
    mainArrayIndex=s;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }
    delete [] first;
    delete [] second;
}

void mergeSort(int *arr,int s,int e){

//BASE CASE
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);   //Sorting the left part of the array
    mergeSort(arr,mid+1,e); //Sorting the right part of the array
    merge(arr,s,e);    //Merging
}

int main(){
    int n;
    cout<<"Enter the size of the array: \n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    




    return 0;


}