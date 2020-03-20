unordered_map<int, int> freq;
for(int i: a)
{
	if(!freq.count(i)) freq[i] = 0;
	freq[i]++;
}