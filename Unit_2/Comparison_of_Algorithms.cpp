#include <iostream>
using namespace std;

int Linear_Search(int *arr, int n, int key){
		int index, boc=0;
		for(int i=0; i<n; i++){
			if(arr[i]==key)
				index = i;
			boc++;
		}
		cout<<"Number of times basic operation was executed for Linear Search:"<<boc<<endl;
		return -1;
	}

int Bin_Search(int *arr, int n, int element){
	int low=0, high = n-1, mid=0, boc=0;
	while(low<=high){
		mid = (high+low)/2;
		if(arr[mid]<element)
			low = mid+1;
		else if(arr[mid]>element)
			high = mid-1;
		else return mid;
	boc++;
	}
	cout<<"Number of times basic operation was executed for Binary Search:"<<boc<<endl;
	return -1;


}


void Sel_Sort(int *arr, int n){
	int k, tmp, boc=0;
	for(int i=0; i<=n-2; i++){
		k=i;
		for(int j=0; j<=n-1; j++){
			boc++;
			if(arr[j]<arr[k]){
				k=j;
				tmp=arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
		}
	}
cout<<"Number of times basic operation was executed for Selection Sort:"<<boc<<endl;
}



void gen_arr(int *arr, int n){
for(int i=0; i<n; i++){
	arr[i] = n-i;
	}
}



int main(){
	int n=100;
	int arr[n];
for(int i=1; i<n; i++){
		gen_arr(arr, n);
		Linear_Search(arr, n, 40);
		Bin_Search(arr, n, 40);
		Sel_Sort(arr, i);
	}
	return 0;
}
