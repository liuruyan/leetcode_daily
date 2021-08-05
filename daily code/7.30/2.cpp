#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int jinwei = 0,tmp =0,first = 1;
    ListNode* ans = new ListNode();
    ListNode* p = ans;
    while(l1&&l2){
        if(first){
            tmp = l1->val + l2->val;
            if (tmp >= 10) {p->val = tmp-10;jinwei = 1;}
            else{p->val = tmp;jinwei = 0;}
            first = 0;
        }
        else{
            ListNode* tmpnode = new ListNode();
            p->next = tmpnode; p = p->next;
            tmp = l1->val + l2->val;
            tmp = jinwei?tmp+1:tmp;
            if (tmp >= 10) {p->val = tmp-10;jinwei = 1;}
            else{p->val = tmp;jinwei = 0;}
        }
        
        l1 = l1->next;l2 = l2->next;    
    }
    if(l1){
        while(l1){
            ListNode* tmpnode = new ListNode();
            p->next = tmpnode; p = p->next;
            tmp = l1->val;
            tmp = jinwei?tmp+1:tmp;
            if (tmp >= 10) {p->val = tmp-10;jinwei = 1;}
            else{p->val = tmp;jinwei = 0;}
            l1 = l1->next;
        }
        if(jinwei){
            ListNode* tmpnode = new ListNode(1);
            p->next = tmpnode;
        }
    }
    else{
        while(l2){
            ListNode* tmpnode = new ListNode();
            p->next = tmpnode; p = p->next;
            tmp = l2->val;
            tmp = jinwei?tmp+1:tmp;
            if (tmp >= 10) {p->val = tmp-10;jinwei = 1;}
            else{p->val = tmp;jinwei = 0;}
            l2 = l2->next;
        }
        if(jinwei){
            ListNode* tmpnode = new ListNode(1);
            p->next = tmpnode;
        }
    }
    return ans;
}

ListNode* right(ListNode* l1, ListNode* l2){
    ListNode *ans = new ListNode(-1);
    ListNode *p = ans; int jinwei = 0;
    while(l1||l2||jinwei){
        int val1 = l1?l1->val:0;
        int val2 = l2?l2->val:0;
        int sum = (val1+val2+jinwei)%10;
        jinwei = (val1+val2+jinwei)/10;
        p->next = new ListNode(sum);
        l1 = l1?l1->next:nullptr;
        l2 = l2?l2->next:nullptr;
        p = p->next;
    }
    return ans->next;
}

int main(){


}