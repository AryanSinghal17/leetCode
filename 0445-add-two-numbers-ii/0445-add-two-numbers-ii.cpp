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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> n1;
        vector<int> n2;
        vector<int> ans;

        while (l1 != nullptr) {
            n1.push_back(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            n2.push_back(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        int i = n1.size() - 1;
        int j = n2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int p;
            if (i >= 0) {
                p = n1[i];
                i--;
            } else {
                p = 0;
            }

            int q;
            if (j >= 0) {
                q = n2[j];
                j--;
            } else {
                q = 0;
            }

            int sum = p + q + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
        }
        reverse(ans.begin(), ans.end());

        ListNode* h = nullptr;
        ListNode* t = nullptr;

        for (int n = 0; n < ans.size(); n++) {
            ListNode* newNode = new ListNode(ans[n]);
            if (h == nullptr) {
                h = newNode;
                t = newNode;
            } else {
                t->next = newNode;
                t = t->next;
            }
        }
        return h;
    }
};