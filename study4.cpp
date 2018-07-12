/**************************
* 7/12
**************************/
// 求连续字数组的最大和

int GetMax(vector<int> v)
{
	int cur = v[0];  // 前一个位置的连续数组最大和
	int max = v[0];  // 最大和
	for (int i=1; i<v.size(); i++) {
		if (cur+v[i] > v[i])
			cur += v[i];
		else
			cur = v[i];
		
		if (cur > max)
			max = cur;
	}
	return max;
}
