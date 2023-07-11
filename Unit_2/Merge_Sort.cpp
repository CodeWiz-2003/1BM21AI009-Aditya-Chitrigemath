#include <iostream>
using namespace std;


void merge(int *A, int start, int mid, int end_){
	int nB = mid-start+1, nC = end_-mid, iB=0, iC=0, k=start;
	int B[nB];
	int C[nC];
	for(int i=0; i<nB; i++){
		B[i] = A[start+i];
	}
	for(int i=0; i<nC; i++){
		C[i] = A[mid+1+i];
	}

	while(iB<nB && iC<nC){
		if(B[iB]<=C[iC]){
			A[k] = B[iB];
			iB++;
		}
		else{
			A[k] = C[iC];
			iC++;
		}
		k++;
	}

	while(iB<nB){
		A[k] = B[iB];
		iB++;
		k++;
	}

	while(iC<nC){
		A[k] = C[iC];
		iC++;
		k++;
	}

}


void MergeSort(int *arr=NULL, int start=0, int end_=0){
		if(start>=end_)
			return;
		int mid = start+(end_-start)/2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid+1, end_);
		merge(arr, start, mid, end_);
	}

class Sorter{
public:
	void setArray(int *arr, int n){
		this->arr = arr;
		this->num_Items = n;
	}

	void getArray(){
		for(int j=0; j<this->num_Items; j++)
			cout<<this->arr[j]<<'\t';
		cout<<'\n'<<endl;
	}

	void Sort(){
		MergeSort(this->arr, 0, this->num_Items);
	}

	

private:
	int *arr;
	int num_Items;
};


int main(){
	int A[10] = {2, 12, 55, 8, 9, 10, 24, 6, 78, 23};
	Sorter S1;
	S1.setArray(A, 10);
	S1.getArray();
	S1.Sort();
	S1.getArray();
	return 0;
}