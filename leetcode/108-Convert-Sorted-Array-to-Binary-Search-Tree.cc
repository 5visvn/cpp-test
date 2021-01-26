#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

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

   TreeNode* getBst (const vector<int>& vec,
                     const int& start, const int& end)
   {
      if (start > end)
         return nullptr;
      else if (start == end)
         return new TreeNode(vec[start]);
      int mid = (start + end)/2;
      return new TreeNode(vec[mid],
                          getBst(vec, start, mid - 1),
                          getBst(vec, mid + 1, end));
   }

   TreeNode* sortedArrayToBST(vector<int>& nums) {
      return getBst(nums, 0, nums.size() -1);
   }

   int getBstHeight(TreeNode* root, int currentHeight = 1, int h = 1)
   {
      h = std::max(h, currentHeight);
      if (root->left)
         h = getBstHeight(root->left, currentHeight + 1, h);
      if (root->right)
         h = getBstHeight(root->right, currentHeight + 1, h);
      return h;
   }

   void printBst(TreeNode* node)
   {
      std::queue<TreeNode*> q1;
      std::queue<TreeNode*> q2;
      int height = getBstHeight(node);
      if (height == 0)
         return;
      int prefixs[height];
      int seperators[height];
      prefixs[0] = 0;
      seperators[0] = 1;
      for (int i = 1; i < height; ++i)
      {
         prefixs[i] = 2*prefixs[i-1] + 1;
         seperators[i] = 2* seperators[i-1] + 1 ;
      }

      int bst_max_size = 2 << (height - 1);
      cout << "max:" << bst_max_size << endl;
      int NUM_LEN = std::to_string(bst_max_size).size();

      auto getSpaces = [&NUM_LEN](int i){return string(i * NUM_LEN, ' ');};

      auto decodeQueue = [&]
         (std::queue<TreeNode*>& inq, std::queue<TreeNode*>& outq)
      {
         while (not inq.empty())
         {
            TreeNode* front = inq.front();
            inq.pop();
            auto spaces = getSpaces(seperators[height]);
            if (front)
            {
               cout << setw(NUM_LEN) << front->val << spaces;
               outq.push(front->left);
               outq.push(front->right);
            }
            else
            {
               cout << getSpaces(1) << spaces;
            }
         }
      };



      q1.push(node); // root node
      while (not q1.empty() && height > 0)
      {
         cout << height << getSpaces(prefixs[--height]);
         decodeQueue(q1, q2);
         cout << endl;

         if (height == 0)
            break;

         cout << height << getSpaces(prefixs[--height]);
         decodeQueue(q2, q1);
         cout << endl;
      }

   }
};

int main()
{
   size_t count = 51;
   vector<int> nums;
   nums.reserve(count);
   for (int i = 1; i <= count; ++i)
      nums.emplace_back(i);

   Solution s;
   TreeNode* bst = s.sortedArrayToBST(nums);

   s.printBst(bst);
   return 0;
}
