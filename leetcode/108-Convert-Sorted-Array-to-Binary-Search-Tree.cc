#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

       auto getBST = [](const vector<int>& v,
                        const size_t& start, const size_t& end)
       {
          if (start > end)
             return nullptr;
          else if (start == end)
             return new TreeNode(nums[start])
          size_t mid = (start + end)/2;
          return new TreeNode(nums[mid],
                              getBST(v, start, mid - 1),
                              getBST(v, mid + 1, end));
       };

       return getBST(nums, 0, nums.size() -1);
    }
};
