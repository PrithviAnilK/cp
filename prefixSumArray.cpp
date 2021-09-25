#include <bits/stdc++.h>
using namespace std;

/*
	Used to create a prefix array from array arr,
	Parameters:- the array from which the prefix array is to be made,
	Returns prefix array.
*/
vector<int> createPrefixArray(vector<int> &arr)
{
	int n = arr.size();
	vector<int> pref(n);
	pref[0] = arr[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + arr[i];
	}
	return pref;
}

/*
	Computes the sum from index 'l' to 'r' in O(1).
	Parameters:- index l and r, prefix array
	Returns sum from index l to r.
*/
int sumLR(int l, int r, vector<int> &pref)
{
	return l == 0 ? pref[r] : pref[r] - pref[l - 1];
}
