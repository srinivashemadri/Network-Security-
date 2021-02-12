#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector

using namespace std;

int main()
{
	int gfg[] = { 3,5,7,9 };

	vector<int> v(gfg, gfg + 4); // 5 6 7 7 6 5 5 6

	sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7

	vector<int>::iterator lower, upper;
	lower = lower_bound(v.begin(), v.end(), 3); 
	upper = upper_bound(v.begin(), v.end(), 9);

	cout << "lower_bound for 6 at position "
		<< (lower - v.begin() + 1) << '\n';
	cout << "upper_bound for 6 at position "
		<< (upper - v.begin() + 1) << '\n';

	return 0;
}