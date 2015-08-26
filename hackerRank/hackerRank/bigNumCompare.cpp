#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n, k;
	cin >> n;
	long double **list = new long  double*[n];
	long double *logList = new long double[n];
	for (int i = 0; i < n; ++i) {
		list[i] = new long double[3];
		cin >> list[i][0] >> list[i][1];
		list[i][2] = logList[i] = list[i][1] * log10(list[i][0]);
	}
	cin >> k;
	cout.setf(ios::fixed);
	sort(logList, logList + n);
	for (int i = 0; i < n; ++i) {
		if (list[i][2] == logList[k - 1])   cout << int(list[i][0]) << " " << int(list[i][1]);
	}

	/*for (int i = 0; i < n; ++i) {
	cout << i << "th" << list[i][0] << " " << list[i][1] << " " << list[i][2] << endl;
	}*/
	//cout << "log list is  : ";
	//for (int i = 0; i < n; ++i) {
	//cout << logList[i] << "  ";
	//}
	/*if (a2 * log2(a) > b2 * log2(b)){
	cout << a << "is bigger";
	}*/
	//else cout << a << "is smaller";
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	cin >> n;
	return 0;
}
