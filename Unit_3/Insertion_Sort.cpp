#include <bits/stdc++.h>
using namespace std;

class Sorter{

public:
	void set_Array(int *Arr, int n){
		this->Arr = Arr;
		this->num_Items = n;
	}

	void print(){
		for(int i=0; i<this->num_Items; i++)
			cout<<this->Arr[i]<<"\t";
		cout<<'\n';
	}

	void Insertion_Sort(){
		int j, v;
		for(int i=1; i<this->num_Items; i++){
			j = i-1;
			v = this->Arr[i];
			while(j>=0 && this->Arr[j]>v){
				this->Arr[j+1] = this->Arr[j];
				j--;
			}
			this->Arr[j+1] = v;
		}
	}

private:
	int *Arr;
	int num_Items;
};


int main(){
	Sorter s;
	int arr[10] = {23, 4, 14, 56, 77, 43, 34, 19, 59, 67};
	s.set_Array(arr, 10);
	s.print();
	s.Insertion_Sort();
	s.print();
	return 0;
}
