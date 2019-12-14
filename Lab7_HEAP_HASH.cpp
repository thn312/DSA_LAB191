#include <iostream>
#include <fstream>
using namespace std;

void reheapDown(int* arr, int pos, int lastPos){
    // TODO
int left = 2*pos + 1;
int right =  2*pos +2;
int max;
if(left <= lastPos){
    if((right <= lastPos) && (arr[left] < arr[right])) max = right;
    else max = left;

    if(arr[max] > arr[pos]){
        swap(arr[max],arr[pos]);
        reheapDown(arr,max,lastPos);
    }
}

}

bool deleteHeap(int* arr, int last, int& data){
    // TODO
if(last < 0) return false;
data = arr[0];
arr[0] = arr[last];
last = last -1;
reheapDown(arr,0,last);
return true;

}
bool isMaxHeap(int* arr, int pos, int last){
    // TODO
if (pos > (last - 2)/2) 
    return true; 

if (arr[pos] >= arr[2*pos + 1] && arr[pos] >= arr[2*pos + 2] && 
    isMaxHeap(arr, 2*pos + 1, last) && isMaxHeap(arr, 2*pos + 2, last)) 
    return true; 
  
return false; 
}

int hash1(int key){
    // TODO
return key % 997 + 1;
}

int hash2(int key){
    // TODO
int i1 = key % 10;
	int i2 = (key / 100) % 10;
	int i3 = (key / 1000) % 10;
	return i1 * 100 + i2 * 10 + i3;
}

int hash3(int key){
    // TODO
	int i1 = key % 1000;
	int i2 = key/1000 % 1000;
	int i3 = key / 1000000;
	return (i1 + i2 + i3)%1000;
}

int hash4(int key){
    // TODO
return (2016 * key + 11) % 997 + 1;
}

int f1(string str) {
	// TODO
int i = str.length();
	int sum = 0;
	int n = stoi(str);
	while (i != 0) {
		int pow = 1;
		for (int j = 0; j < i - 1; j++) {
			pow = pow*(n%10);
		}
		sum += 7*pow;
		n = n/10;
		i--;
	}
	return sum%7719;
}

int Kmax(int* arr, int N) {
		int pos = N / 2 - 1;
	while (pos >= 0) {
		reheapDown(arr,pos, N - 1);
		pos = pos - 1;
	}
	int last = N - 1;
	while (last > 0) {
		swap(arr[0], arr[last]);
		last = last - 1;
		reheapDown(arr,0, last - 1);
	}

	return arr[N-5];
}


int main(int argc, char* argv[]){
	return 0;
}
