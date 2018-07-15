/*****************************
*	7/15
*****************************/
// 求出现在同一条直线最多点的个数

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 class Solution {
private:
	int gcb(int a.int b) {
		if (b == 0)	return a;
		else		return gcb(b,a%b);
	}
	
public:
    int maxPoints(vector<Point>& points) {
		int count = 0; // 返回值
		for(int i=0; i<points.size(); i++) {
			int cnt = 0; // 与当前点在一条直线的最大个数
			int samepoint = 0; // 相同的点
			map<pair<int,int>,int > m; // 用最简的(x,y)作为key值
			for(int j=i+1; j<points.size(); j++) {
				if (points[i].x == points[j].x
				 && points[i].y == points[j].y) {
					++samepoint;
				 }
				 else {
					int xdiff = points[i].x-points[j].x;
					int ydiff = points[i].y-points[j].y;
					int g = gcb(xdiff,ydiff);
					xdiff /= g;
					ydiff /= g;
					cnt = max(cnt,++m[make_pair(xdiff,ydiff)]);
				 }
			}
			count = max(count,cnt+samepoint+1);
		}
		return count;
	}
 }