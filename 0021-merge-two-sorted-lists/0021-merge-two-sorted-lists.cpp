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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* mergeHead = NULL;
        ListNode *prev = NULL;

        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
                if(mergeHead == NULL){
                    mergeHead = list2;
                    prev = mergeHead;
                }else{
                    prev->next = list2;
                    prev = list2;
                }
                list2 = list2->next;
            }else{
                if(mergeHead == NULL){
                    mergeHead = list1;
                    prev = list1;
                }else{
                    prev->next = list1;
                    prev = list1; 
                }
                list1 = list1->next;
            }
        }

        while(list1 != NULL){
            prev->next = list1;
            prev = list1;
            list1 = list1->next;
        }

        while(list2 != NULL){
            prev->next = list2;
            prev = list2;
            list2 = list2->next;
        }

        return mergeHead;
    }
};