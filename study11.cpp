/***********************
* 8/1
************************/
// 给定三角形数组，求最短和
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len=triangle.size();
        if(len==0)
            return 0;
        for(int i=len-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                //当前节点为，当前节点加上下一层节点左右相邻的最小值
                triangle[i][j]+=
				(triangle[i+1][j]<triangle[i+1][j+1] ? 
				triangle[i+1][j]:triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};