/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode(0);
        ListNode* temp = out;
        ListNode* lastMinusOne;
        int adder = 0;
        while (l1 || l2)
        {
            int a = (l1)?(l1->val):0;
            int b = l2?(l2->val):0;
            temp->val = (a + b + adder < 10) ? (a + b + adder) : (a + b + adder - 10);
            adder =  (a + b + adder < 10) ? 0:1;
            temp->next = new ListNode(0);
            lastMinusOne = temp;
            temp = temp->next;
            l1 = (l1)? (l1->next): NULL;
            l2 = (l2)? (l2->next): NULL;
        }
        if (adder == 1)
        {
            temp->val = 1;
        }
        else
        {
            delete temp;
            lastMinusOne->next = NULL;
        }
        return out;
    }
};
int main()
{
    /*
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution mysol;
    ListNode* output = mysol.addTwoNumbers(l1, l2);
    cout<<output->val<<endl;
    cout<<output->next->val<<endl;
    cout<<output->next->next->val<<endl;
    cout<<output->next->next->next->val<<endl;
    */
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(8);
    ListNode* l2 = new ListNode(1);
    Solution mysol;
    ListNode* output = mysol.addTwoNumbers(l1, l2);
    
    cout<<output->val<<endl;
    cout<<output->next->val<<endl;
    
    output = mysol.addTwoNumbersMy(l1,l2);
    cout<<endl;
    cout<<output->val<<endl;
    cout<<output->next->val<<endl;
    //cout<<output->next->next->val<<endl;
    return 0;
}