//author : xcj
//date   : 20190126
//problem: 包含min函数的栈
//method : 使用一个栈s1和辅助栈s2，当进行push操作时，入栈元素val，先把val放到栈s1中，
//当s2.empty()或这s2.top()<val时，将val放到s2，这时可以得到一个拥有完成元素的栈s1和
//一个拥有部分元素但从栈底到栈顶单调递减的栈s2；当进行min操作时，取(s2.empty()? s1.top()
//: min(s1.top(),s2.top()))则为当前栈中最小元素。进行pop操作时，当s1.top()==s2.top()
//时，同时出栈，否则只有s1出栈，这样才能保证两个栈的同步。

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if(s2.empty()) 
            s2.push(value);
        else if(s2.top() > value) 
            s2.push(value);
    }
    void pop() {
        if(s1.empty())
            return;
        s1.pop();
        if(s1.top() == s2.top())
            s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        if(!s2.empty())
            return std::min(s1.top(), s2.top());
        return s1.top();
    }
    stack<int> s1, s2;
};
