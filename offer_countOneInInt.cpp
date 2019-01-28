//author : xcj
//date   : 20190129
//problem: 整数中1出现的次数
//method : 实在没想出来，参考某大神的做法。

 /*
      我们从低位到高位求每位1出现的次数，累加求和即可
        例如：求0~abcde中1的个数，现在我们求c这一位中1出现的次数，其他位雷同
        有两部分组成
        第一部分：ab * 100，表示当ab这两位在0~ab-1范围内时，de可以从0~99取值
          第二部分：如果c>1时，当ab为ab时1的个数为0~99
                  如果c=1时，当ab为ab时1的个数为de + 1
                如果c<0时，当ab为ab是1的个数为0
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum = 0;
        int e = 1;
        while(n / e) {
            sum += n / (e * 10) * e;    //第一部分
            int c = n / e % 10;         //第二部分
            if(c > 1) sum += e;
            else if(c == 1) sum += n % e + 1;
            e *= 10;
        }
        return sum;
    }
};
