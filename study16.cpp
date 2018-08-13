/**************************
* 8/13
***************************/

// 网易编程题 塔

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	set<pair<int,int> >  s;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		s.emplace(x,i);
	}
	vector<pair<int,int> > res;
	
	while (k && s.size()>1 && s.rbegin()->first-s.begin()->first>1 ) {
		auto a = *s.begin(),b = *s.rbegin();
		s.erase(a);
		s.erase(b);
		a.first++;
		b.first--;
		s.insert(a);
		s.insert(b);
		res.emplace_back(b.second,a.second);
		k--;
	}
	cout << s.rbegin()->first-s.begin()->first << " " << res.size() << endl;
	for (auto it : res) 
		cout << it.first << " " << it.second << endl;
	return 0;
}