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
    ListNode*rev(ListNode*head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode*temp = rev(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }

    ListNode*kthNode(ListNode*temp,int k){
        k -= 1;
        while(temp != nullptr && k> 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp = head;
        ListNode*nextNode = nullptr;

        while(temp != nullptr){
            ListNode*kth = kthNode(temp,k);

            if(kth == nullptr){
                if(nextNode){
                    nextNode->next = temp;
                }
                break;
            }

            ListNode*Node = kth->next;
            kth->next = nullptr;
            rev(temp);

            if(temp == head){
                head = kth;
            }else{
                nextNode->next = kth;
            }

            nextNode = temp;
            temp = Node;
        }
        return head;
    }
};