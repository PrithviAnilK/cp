unordered_map<int, int> freq;
for(int i: arr)
{
	try
	{
		freq[i]++;
	}
	catch(int x)
	{
		freq[i] = 0;
	}
}
