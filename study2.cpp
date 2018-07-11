/***********************
* 7/11
***********************/

// 求最大回文串长度 Mancher算法

class Mancher {
	string MancherString(string s) {
		string ret;
		for(int i=0; i<s.size(); i++) {	
			ret += ('#'+s[i]);
		}
		ret += '#';
		return ret;
	}
public:
	static int MaxLcpLength(string s) {
		if (s.size() == 0)
			return 0;
		char mancherstr = MancherString(s); // 生成回文串
		vector<int> v; // 存储每个位置的回文半径
		v.reserve(mancherstr.size());
		int C = -1;  // 回文中心
 		int R = -1;  // 最大回文右边界
		int max = -1; // 最大回文长度
		for(int i=0; i<mancherstr.size(); i++) {
			//如果在最右回文半径内，利用对称信息
			v[i] = R > i? min(v[2*C-i],R-i):1; 
			while (i+v[i] < s.size()
				   && i-v[i] > -1) {
				if (mancherstr[i + v[i]] == mancherstr[i - v[i]])	
					v[i]++;
				else
					break;
			}
			// 更新信息
			if (i+v[i] > R) {
				R = i+v[i];
				C = i;
			}
			max = max(max,v[i]);
		}
		return max-1;
	}
};