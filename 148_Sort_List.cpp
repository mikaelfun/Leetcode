/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    ListNode* mergeList(ListNode* l, ListNode* r)
    {
        int out = l->val>r->val?r->val:l->val;
        ListNode* start = new ListNode(out);
        int sizeL = 0;
        int sizeR = 0;
        ListNode* iter = l;
        while (iter)
        {
            sizeL++;
            iter = iter->next;
        }
        iter = r;
        while (iter)
        {
            sizeR++;
            iter = iter->next;
        }
        int k = 0;
        int j = 0;
        ListNode* iterL = l->val>r->val?l:l->next;
        ListNode* iterLb = l->val>r->val?l:l->next;
        ListNode* iterR = r->val>l->val?r:r->next;
        ListNode* iterRb = r->val>l->val?r:r->next;
        ListNode* iterCurr = start;
        while (iterL || iterR)
        {
            if (!iterL && iterR)
            {
                iterCurr->next = iterR;
                return start;
            }
            else if (!iterR && iterL)
            {
                iterCurr->next = iterL;
                return start;
            }
            else if (iterL->val < iterR->val)
            {
                iterCurr->next = new ListNode(iterL->val);
                iterL = iterL->next;
                iterCurr = iterCurr->next;
            }
            else if (iterL->val > iterR->val)
            {
                iterCurr->next = new ListNode(iterR->val);
                iterR = iterR->next;
                iterCurr = iterCurr->next;
            }
            else
            {
                iterCurr->next =new ListNode(iterR->val);
                iterR = iterR->next;
                iterCurr = iterCurr->next;
                iterCurr->next =new ListNode(iterL->val);
                iterL = iterL->next;
                iterCurr = iterCurr->next;
            }
        }
        return start;
    }
    ListNode* sortList(ListNode* head) {
        //mergesort
        int size = 0;
        ListNode* iter = head;
        while (iter)
        {
            size++;
            iter = iter->next;
        }
        if (size == 1 || size == 0)
        {
            return head;
        }
        if (size == 2)
        {
            iter = head->next;
            if (head->val > iter->val)
            {
                ListNode* out = new ListNode(iter->val);
                out->next =new ListNode(head->val);
                return out;
            }
        }
        else
        {
            ListNode* l,*r,*iter, *out;
            int i = 0;
            l = head;
            iter = head;
            for (i = 0; i<size/2 - 1; i++)
            {
                iter = iter->next;
            }
            r = iter->next;
            iter->next = NULL;
            
            l = sortList(l);
            r = sortList(r);
            out = mergeList(l,r);
            return out;
        }
    }
};

int main()
{
    Solution mySol;
    ListNode a(1);
    ListNode b(3);
    ListNode c(7);
    ListNode d(8);
    ListNode e(2);
    ListNode f(5);
    ListNode g(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    mySol.sortList(&a);
    ListNode* temp = &a;
    for (int i = 0; i<7; i++)
    {
        cout<<temp->val<<endl;
        temp= temp->next;
    }
        
    return 0;
}