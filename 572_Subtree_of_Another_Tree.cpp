/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* a, TreeNode* b)
    {
        bool sameVal = a->val == b->val;
        bool ahasLeft = a->left;
        bool ahasRight = a->right;
        bool bhasLeft = b->left;
        bool bhasRight = b->right;
        if (sameVal && a->left == NULL && a->right == NULL && b->left == NULL && b->right == NULL)
        {
            return true;
        }
        else if (!sameVal)
        {
            return false;
        }
        if (sameVal && ahasLeft && bhasLeft)
        {
            if (bhasRight && ahasRight)
            {
                return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
            }
            else if (!ahasRight && !bhasRight)
            {
                return isSameTree(a->left, b->left);
            }
            else 
            {
                return false;
            }
        }
        else if (sameVal && ahasRight && bhasRight)
        {
            if (ahasLeft && bhasLeft)
            {
                return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
            }
            else if (!ahasLeft && !bhasLeft)
            {
                return isSameTree(a->right, b->right);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s || !t)
        {
            return false;
        }
        if (isSameTree(s, t))
        {
            return true;
        }
        else if (s->left || s->right)
        {
            if (s->left && s->right)
            {
                TreeNode* temp1 = s->left;
                TreeNode* temp2 = s->right;
                return isSubtree(temp1, t) || isSubtree(temp2,t);
            }
            else if(s->left && !(s->right))
            {
                return isSubtree(s->left, t);
            }
            else
            {
                return isSubtree(s->right, t);
            }
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution mysol;
    cout<<mysol.isSubtree(-12321)<<endl;
    return 0;
}