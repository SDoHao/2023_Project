class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int maxq = 0,n = s.size();
        stack<int> sk;
        sk.push(-1);
        for(int i = 0;i < n;i++)
        {
            if(s[i] == '(')
                sk.push(i);
            else
            {
                sk.pop();
                if(sk.empty())
                    sk.push(i);
                else
                    maxq = max(maxq,i - sk.top());
            }
        }
        return maxq;
    }
};