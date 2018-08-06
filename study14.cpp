/************************
* 8/6
************************/
// 给定一个数组v和一个和sum，统计出所有和为sum的方案数

int GetCount(vector<int> v,int sum) {
	if (v.size() == 0)
		return 0;
	vector<long long> count(sum+1); //和为sum的方案数
	count[0] = 1;
	for (int i=0; i<v.size(); i++)
		for (int j=sum; j>=b[i]; j++)
			count[j] += count[j-b[i]]; // 和为j的方案数
	return count[sum];
}