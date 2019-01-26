//author : xcj
//date   : 20190126
//problem: 二维数组中的查找
//method : 从左下角开始搜索，将当前元素cur和目标元素target进行比较，若cur > target，
//则往上搜索；若cur < target，则往右搜索；若cur == target，则return ture。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        
        if(array.empty() || array[0].empty())
            return false;
        
        int n = array.size();
        int m = array[0].size();
        
        int i, j;
        i = n - 1;
        j = 0;
        while(i >= 0 && j < m) {
            if(array[i][j] == target)
                return true;
            else if(array[i][j] < target)
                ++j;
            else
                --i;
        }
        
        return false;
    }
};
