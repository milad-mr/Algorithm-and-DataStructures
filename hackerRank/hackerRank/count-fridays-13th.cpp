#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count(int d, int m, int y_last) {
	int count = 0;

	int day = 1;//monday
				//int mount = 0;
	int day_per_month;
	for (int year = 1900;; ++year) {
		for (int month = 0; month < 12; month++) {
			if (month % 12 == 0) day_per_month = 31;
			else if (month % 12 == 1) {
				if (year == 1900)    day_per_month = 28;
				else if (year % 4 == 0)   day_per_month = 29;
				else    day_per_month = 28;
			}
			else if (month % 12 == 2) day_per_month = 31;
			else if (month % 12 == 3) day_per_month = 30;
			else if (month % 12 == 4) day_per_month = 31;
			else if (month % 12 == 5) day_per_month = 30;
			else if (month % 12 == 6) day_per_month = 31;
			else if (month % 12 == 7) day_per_month = 31;
			else if (month % 12 == 8) day_per_month = 30;
			else if (month % 12 == 9) day_per_month = 31;
			else if (month % 12 == 10) day_per_month = 30;
			else if (month % 12 == 11) day_per_month = 31;
			for (int i = 0; i < day_per_month; ++i) {
				if (i == 12 & day == 5)   count++;
				day++;
				day = day % 7;
				if (i == d - 1 && year == y_last && month == m - 1)  return count;
			}
		}
	}
	//cout <<"golabi";
	return -5;
}
int main() {
	int t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt) {
		int d1, m1, y1, d2, m2, y2;
		cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
		int c1 = count(d1, m1, y1);
		if (d1 == 13 && c1 - count(d1 - 1, m1, y1) == 1) {
			cout << count(d2, m2, y2) - c1 + 1 << endl;
		}
		else {
			cout << count(d2, m2, y2) - c1 << endl;
		}
		//cout << count(14, 3, 2015) - count(13, 3, 2015);
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}