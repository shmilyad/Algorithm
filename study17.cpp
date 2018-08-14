/**************************
* 8/14
**************************/

// kmp算法

// 生成next数组
void GetMaxArray(string s,int* next,int size) {
    if( size == 1 ) {
        next[0] = -1;
        return;
    }

    next[0] = -1;
    next[1] = 0;
    int cn = 0,cur = 2;
    while( cur<size ) {
        if( s[cur]-1==s[cn] ) 
            next[cur++] = ++cn;
        else if( next[cn]>0 )
            cn = next[cn];
        else
            next[cur++] = 0;
    }   
}

int MyKmp(string s1,string s2) {
    if( s2.size()>s1.size() ) return -1;
    int next[s2.size()];
    GetNextArray( s2,next,sizeof(arr)/sizeof(arr[0]) );

    int i=0,j=0;
    while( i<s1.size()&&j<s2.size() ) {
        if( s1[i] == s2[j] ) {  //大家都加加
            i++;
            j++;
        }else if( next[j] > 0 ) //不相等 但是存在s1的后缀与s2的前缀相等(部分相等)
            j = next[j];
        else {   //大家完全不等
            i++;
            j = 0;
        }
    }

    return j==s2.size()?i-j:-1;
}

// 归并排序
void Merge(vector<int>& v,int left,int mid,int right) {
	vector<int> tmp(right-left+1);
	int i = left;
	int j = mid+1;
	int index = 0;
	while (i<=mid && j<=right) {
		if (v[i] < v[j]){
			tmp[index++] = v[i++];
		}else {
			tmp[index++] = v[j++];
		}
	}
	while (i <= mid) {
		tmp[index++] = v[i++];
	}
	while (j <= right) {
		tmp[index++] = v[j++];
	}
	for (int i=left; i<=right; i++)
		v[i] = tmp[i-left];
}

// [left,right]
void Merge_Sort(vector<int>& v,int left,int right) {
	if (left < right) {  //这个区间有元素 
		int mid = left + (right-left)/2;
		Merge_Sort(left,mid);
		Merge_Sort(mid+1,right);
		Merge(v,left,mid,right);
	}
}







