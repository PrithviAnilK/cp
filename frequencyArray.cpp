unordered_map<int, int> freq;
for(int i: a)
{
	uf(!freq.count(i)) freq[i] = 0;
	freq[i]++;
}