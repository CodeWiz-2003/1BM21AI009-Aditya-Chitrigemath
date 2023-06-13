#include <iostream>
using namespace std;


class Searcher{

public:
	int Linear_Search(int key){
		int i;
		for(i=0; i<this->num_Items; i++){
			if(this->arr[i]==key)
				return i;
		}
		return -1;
	}

	void set_Array(int *array, int n){
		this->arr = array;
		this->num_Items = n;
	}

	void get_Array(){
		cout<<"Number of elements:"<<this->num_Items<<endl;
		for(int i=0; i<this->num_Items; i++){
			cout<<this->arr[i]<<'\b';
		}
	}

private:
	int *arr;
	int num_Items;
};

int main(){
	int array[5] = {12, 34, 56, 78, 90};
	Searcher s;
	s.set_Array(array, 5);
	cout<<"Linear Search Result: "<<s.Linear_Search(56)<<endl;

	return 0;
}