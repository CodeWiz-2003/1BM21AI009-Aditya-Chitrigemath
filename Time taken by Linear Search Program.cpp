#include <iostream>
#include <cstdlib>
#include <ctime>
#define BILLION 1000000000L
using namespace std;

class Searcher{
public:
	int Linear_Search(int key){
		int i, flag;
		//clock_t s, e;
		double t;
		//s = clock();
		for(i=0; i<this->num_Items; i++){
			if(this->arr[i]==key){
				flag = 1;
				break;
			}
		}
		//e = clock;
		//t = (e-s)/CLOCKS_PER_SEC;
		//printf("%f\n", t);
		if(flag==1)
			return i;

		return 1;
	}

	void set_Array(int *Array, int n){
		this->arr = Array;
		this->num_Items = n;
	}

	void get_Array(){
		cout<<"Number of Items in the array: "<<this->num_Items<<endl;
		for(int i=0; i<this->num_Items; i++){
			cout<<this->arr[i]<<'\t';
		}
	}

private:
	int *arr;
	int num_Items;
};

int *generator(int seed, int num_Items, int *arr){
	for(int i=0; i<num_Items; i++){
		srand(seed+i+2);
		arr[i] = rand();
	}
return arr;
}

void print(int *arr, int n){
	cout<<"Number of items in the array :"<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<'\t';
}



int main(){

struct timespec st, ed;
uint64_t diff;
int array[10] = {12, 34, 56, 78, 90, 123, 22, 89, 70, 10}, n = 100000;
int arr[n];
generator(12, n, arr);
//print(arr, n);
Searcher s1;
s1.set_Array(arr, n);
clock_gettime(CLOCK_MONOTONIC, &st);
s1.Linear_Search(arr[n/2]);
clock_gettime(CLOCK_MONOTONIC, &ed);
diff = BILLION * (ed.tv_sec - st.tv_sec) + ed.tv_nsec - st.tv_nsec;
cout<<"Time taken : "<<diff<<endl;
return 0;

}