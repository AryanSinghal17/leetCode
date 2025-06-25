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
    ListNode* reverseKGroup(ListNode* h, int k) {
        if(k == 0){
            return h;
        }

        vector<int>vec;
        ListNode*temp = h;

        while(temp!= nullptr){
            vec.push_back(temp->val);
            temp = temp->next;
        }

        int n = vec.size();
        for (int i = 0; i + k <= n; i += k) {
            reverse(vec.begin() + i, vec.begin() + i + k);
        }

        ListNode*head = nullptr;
        ListNode*tail = nullptr;

        for(int i = 0;i<n;i++){
            ListNode*data = new ListNode(vec[i]);
            if(head ==  nullptr){
                head = data;
                tail = data;
            }else{
                tail->next = data;
                tail = tail->next;
            }
        }

        return head;
    }
};