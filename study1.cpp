/****************************
*	2018/7/10
****************************/

// 不用乘除和if，switch等控制语句求前n项和

/* 
*	方法1:
*	利用构造函数的自动调用和静态变量的性质进行实现
*/
class _Solution1 {
	public:
		_Solution1() {
			++n;
			sum += n;
		}
		
		static void Reset() {
			n = 0;
			sum = 0;
		}
		
		static int GetSum() {
			return sum;
		}
	private:
		static int n;
		static int sum;
};
int Solution1::n = 0;
int Solution1::sum = 0;

int Solution1(int n) {
	_Solution1::Reset();
	_Solution1 *P = new _Solution1[n];
	delete[] p;
	p = NULL;
	return _Solution1::GetSum();
}

/*
*	方法2:
*	公式 n*(n+1)/2 n*n+1利用sizeof数组获得，/2利用移位实现
*/

int Solution2(int n) {
	bool a[n][n+1];
	int ret = (sizeof(n)>>1);
	return ret;
}

/*
*	方法3:
*	利用 && 的特点和递归函数实现
*/

int Solution3(int n) {
	int sum = n;
	n && (sum += Solution3(n-1));
	return sum;
}