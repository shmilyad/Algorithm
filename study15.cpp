/******************
* 8/7
*******************/

// 数字n的二进制1的个数

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while (n != 0)
         {
             n &= (n-1);
             count++;
         }
         return count;
     }
};