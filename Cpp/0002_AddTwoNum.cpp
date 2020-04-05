#include <iostream>

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *L1 = new ListNode(0);
        ListNode *L2 = new ListNode(0);
        L2->next=L1;
        L2=L2->next;
        int sum1=0;
        int sum2=0;
        while(l1!=NULL||l2!=NULL){
            ListNode *L3 = new ListNode(0);
            if(l1&&l2)
                sum2 = l1->val+l2->val;
            else if(!l1&&l2)
                sum2 = 0+l2->val;
            else if(!l2&&l1)
                sum2=l1->val+0;
            if(sum1>=10)
                sum2+=1;
            L3->val=sum2%10;
            sum1=sum2;
            L1->next=L3;
            L1=L1->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(sum1>=10){
            ListNode *L3 = new ListNode(1);
            L1->next=L3;
        }
        return L2->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

