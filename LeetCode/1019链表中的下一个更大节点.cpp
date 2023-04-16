/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        int max,n,top;
        stack<int> vecti;
        stack<int> s_max;
        vector<int> result;
        ListNode * temp = head;
        while(temp)
        {
            vecti.push(temp->val);
            temp = temp -> next;
        }
        n = vecti.size() - 1;
        max = vecti.top();
        vecti.pop();
        s_max.push(max);
        result.push_back(0);
        while(--n>= 0)
        {
            top = vecti.top();
            vecti.pop();
            max = s_max.top();
            while(!s_max.empty() && max <= top)
            {
                s_max.pop();
                if(!s_max.empty())
                    max = s_max.top(); 
            }
            if(!s_max.empty())
                result.insert(result.begin(),max);
            else
                result.insert(result.begin(),0);
            s_max.push(top);
        }
        return result;
    }
};