#include<iostream>
using namespace std;

const int SIZE = 10; 

int main(){
	int arr[SIZE];
	int temp;
	
	// Fill array
	for (int i=0; i<SIZE; i++){
		cout<<"Enter "<<i+1<<" element of array ";
		cin>>arr[i];
		system ("cls");
	}
	// Show array before sort
	cout<<"Array before sorting"<<endl;
	for (int i=0; i<SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	// Sort
	for (int i=0; i<SIZE; i++){
		for (int j=0; j< SIZE -1; j++){
			if (arr[j]>arr[j+1]){
				temp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	// Show array after sort
	cout<<"Array after sorting"<<endl;
	for (int i=0; i<SIZE; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
} 
