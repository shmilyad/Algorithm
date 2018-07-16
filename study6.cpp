/***********************
* 7/16
***********************/

// 长度为n的数组，所有数组在[0,n-1]
// 关键点：所有数字的范围，和下标对应
int Duplicate(vector<int> v) {
	if (v.size() == 0)
		return -1;
	for (int i=0; i<v.size(); i++)
		if (v[i]<0 || v[i]>v.size()-1)
			return -1;
	for (int i=0; i<v.size(); i++) {
		while (v[i] != i) {
			// v[i]的位置v[i]上已经存在其对应位
			if (v[i] == v[v[i]])
				return v[i];
			// 一次交换v[i]便可以出现在i的位置
			swap(v[i].v[v[i]]);  
		}
	}
	return -1;
	
}