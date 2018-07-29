/******************
* 7/29
*******************/
// 斐波那契数列
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 1)
            return n;
        
        int n0 = 0;
        int n1 = 1;
        for (int i=2; i<=n; i++)
        {
            int tmp = n1;
            n1 += n0;
            n0 = tmp;
        }
        
        return n1;
    }
};

// 青蛙变态跳台阶
class Solution {
public:
    // f(n) = f(1) + f(2) + ''' + f(n-1)
    // f(n-1) = f(1) + f(2) +  + f(n-2)
    // f(n) = 2f(n-1)
    int jumpFloorII(int number) {
        if (number <= 2)
            return number;
        int n = 2;
        int i = 3;
        while(i++ <= number)
            n *= 2;

        return n;
    }
};