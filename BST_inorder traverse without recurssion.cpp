#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int data) {
        this->val = data;
        this->left = this->right = nullptr;
    }
};
void iterate(TreeNode* root) {
    TreeNode* cur = root;
    stack<TreeNode*> s;
    while (!cur || !s.empty()) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        }
        else {
            cur = s.top();
            s.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
}
int main () {

}