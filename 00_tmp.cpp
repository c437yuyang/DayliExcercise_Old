#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int arr[3] = { 1,2,3 };
	int *p = &arr[0];
	cout << *p + *p++ + *++p << endl;
	return 0;
}