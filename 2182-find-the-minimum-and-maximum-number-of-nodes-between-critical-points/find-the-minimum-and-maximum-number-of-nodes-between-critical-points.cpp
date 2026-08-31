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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        ListNode * prev = head;
        ListNode * curr = head->next;
        ListNode * next = curr->next;
        vector<int> index;
        int ind = 1;
        while(next != NULL){
            if(curr->val < prev->val && curr->val < next->val) index.push_back(ind);
            else if(curr->val > prev->val && curr->val > next->val) index.push_back(ind);
            ind++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        int size = index.size();
        if(size<2) return {-1,-1};
        int maxi = index[size-1] - index[0];
        int mini = maxi;
        for(int i=1;i<size;i++){
            mini = min(mini,index[i]-index[i-1]);
        }
        return {mini,maxi};
    }
};