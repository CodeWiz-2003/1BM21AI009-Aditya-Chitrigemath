#include <stdio.h>

typedef struct{
	int *arr;
	int key;
}s;


int Binary_Search(s S1, int first, int last){
	int mid = (first+last)/2;
	if(first==last-1)
		if(S1.arr[last]!= S1.key && S1.arr[first]!=S1.key)
			return -1;
		else if(S1.arr[first]==S1.key)
			return first;
		else return last;
	else if(S1.key<S1.arr[mid])
		return Binary_Search(S1, first, mid);
	else if(S1.key>S1.arr[mid])
		return Binary_Search(S1, mid, last);
	else return mid;
}

int Linear_Search(s S1, int num_Items){
		int i;
		for(i=0; i<num_Items; i++){
			if(S1.arr[i]==S1.key)
				return i;
		}
		return -1;
	}


int main(){
	int arr[5] = {12, 34, 56, 78, 90};
	s S1;
	S1.arr = arr;
	S1.key = 12;
	printf("Binary Search Result : %d\n", Binary_Search(S1, 0, 4));
	printf("Linear Search Result : %d\n", Linear_Search(S1, 5));
	S1.key = 90;
	printf("Binary Search Result : %d\n", Binary_Search(S1, 0, 4));
	printf("Linear Search Result : %d\n", Linear_Search(S1, 5));
	S1.key = 78;
	printf("Binary Search Result : %d\n", Binary_Search(S1, 0, 4));
	printf("Linear Search Result : %d\n", Linear_Search(S1, 5));
	S1.key = 5809;
	printf("Binary Search Result : %d\n", Binary_Search(S1, 0, 4));
	printf("Linear Search Result : %d\n", Linear_Search(S1, 5));
	return 0;
}