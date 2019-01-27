//author : xcj
//date   : 20190127
//problem: 最小的K个数
//method : 大顶堆，保存k个数，如果比堆顶小，入队然后出队堆顶。
/*
//STL priority_queue
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size() || !k) return vector<int>();
        priority_queue<int> pque;
        vector<int> ans;
        for(int i = 0; i < k; i++) pque.push(input[i]);
        for(int i = k; i < input.size(); i++) {
            if(pque.top() > input[i]) {
                pque.pop();
                pque.push(input[i]);
            }
        }
        while(!pque.empty()) {
            ans.push_back(pque.top());
            pque.pop();
        }
        return ans;
    }
};
*/

/*
//make_heap push_head pop_heap sort_heap
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size() || !k) return vector<int>();
        vector<int> ans(input.begin(), input.begin()+k);
        make_heap(ans.begin(), ans.end());
        for(int i = k; i < input.size(); i++) {
            if(ans[0] > input[i]) {
                pop_heap(ans.begin(), ans.end());    //被删除元素存放在最后
                ans[ans.size() - 1] = input[i];
                push_heap(ans.begin(), ans.end());   //需要先把元素放到最后，再调用push_head调整堆
            }
        }
        //sort_heap 把堆内元素按顺序排列
        return ans;
    }
};
*/

//手写堆
class Heap {
public:
    void push(int val) {
        data.push_back(val);
        int nod = data.size() - 1;
        while(nod > 0) {
            int p = (nod - 1) >> 1;
            if(val > data[p]) {
                swap(data[nod], data[p]);
                nod = p;
            }
            else return;
        }
    }
    void pop() {
        swap(data[0], data[data.size()-1]);
        data.pop_back();
        int p = 0;
        while(p < data.size()) {
            int l = (p << 1) + 1;
            int r = (p << 1) + 2;
            if(l >= data.size()) return;
            int maxval = data[l];
            int maxnod = l;
            if(r < data.size() && maxval < data[r]) {
                maxval = data[r];
                maxnod = r;
            }
            if(data[p] < maxval) {
                swap(data[p], data[maxnod]);
                p = maxnod;
            }
            else return;
        }
    }
    int top() {
        return data[0];
    }
    bool empty() {
        return data.empty();
    }
    int size() {
        return data.size();
    }
private:
    vector<int> data;
};

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size() || !k) return vector<int>();
        Heap pque;
        vector<int> ans;
        for(int i = 0; i < k; i++) pque.push(input[i]);
        for(int i = k; i < input.size(); i++) {
            if(pque.top() > input[i]) {
                pque.pop();
                pque.push(input[i]);
            }
        }
        while(!pque.empty()) {
            ans.push_back(pque.top());
            pque.pop();
        }
        return ans;
    }
};
