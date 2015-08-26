#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int select(vector <int> arr, int k) {//find kth smaller integer f array
	if (arr.size() <= 1) return arr[0];
	int groupSize = 3;
	vector <int> mediansOfGroups;
	for (int i = 0; i < arr.size(); i += groupSize) {
		int mGroupSize = (groupSize < arr.size() - i) ? groupSize : arr.size() - i;
		int *group = new int[mGroupSize];
		for (int j = 0; j < mGroupSize; ++j) group[j] = arr[i + j];

		sort(group, group + mGroupSize); //shayad bayad temp + gpsize -1 bedim // inja chon adad kame mishe ba o(n2) bedast ovord
		mediansOfGroups.push_back(group[mGroupSize / 2]);
		delete group;
	}
	int medianOfMedians = select(mediansOfGroups, mediansOfGroups.size() / 2);
	vector <int> smallers, biggers, equals;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] > medianOfMedians)   biggers.push_back(arr[i]);
		else if (arr[i] < medianOfMedians) smallers.push_back(arr[i]);
		else equals.push_back(arr[i]);
	}
	if (smallers.size() + equals.size() < k)    return select(biggers, k - smallers.size() - equals.size());
	else if (k > smallers.size() & k <= smallers.size() + equals.size())    return medianOfMedians;

	else    return select(smallers, k);


}
int main()
{
	int n;
	cin >> n;

	vector <int> arr(n);
	for (int i = 0; i < (int)n; ++i) {
		cin >> arr[i];
	}

	cout << select(arr, (arr.size() + 1) / 2);
	return 0;
}