#include <bits/stdc++.h>
using namespace std;

// maintain an iterator to the median of a multiset
// insert a new value and update the median accordingly

void insert_with_median_update(multiset<int>& s, int value,
                               multiset<int>::iterator& median)
{
    if (s.empty()) {
        s.insert(value);
        median = s.begin();
        return;
    }
    int median_value = *median;
    s.insert(value);
    int n = s.size();
    if (n & 1) {
        if (median_value > value) {
            median--;
        }
    } else {
        if (median_value <= value) {
            median++;
        }
    }
}

// to use

// init
// multiset<int> s;
// auto median = s.begin();

// update
// insert_with_median_update(s, value, median);