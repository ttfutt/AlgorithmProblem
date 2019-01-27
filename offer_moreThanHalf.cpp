//author : xcj
//date   : 20190127
//problem: 数组中出现次数超过一半的数字
//method : 假设该数组符合题中所说的存在数字出现次数超过数组长度的一半，那么
//该数组必定符合特性：在数组中选择任意两个不同的数字并消除，重复此操作，那么剩
//下的数字必定为该数组的主元素。然后我们可以根据这特性得到的"主元素"遍历数组
//来确定出现次数是否超过数组长度的一半。

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int num, count = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(count == 0) {
                num = numbers[i];
                count = 1;
            }
            else if(num == numbers[i])
                count++;
            else 
                count--;
        }
        if(count*2 > numbers.size()) return num;
        if(count == 0) return 0;
        count = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(num == numbers[i]) count++;
        }
        if(count*2 > numbers.size()) return num;
        return 0;
    }
};
