/*
Solved 9 Apr 2023 by Karim Elmasry
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time
complexity?

TIME COMPLEXITY: 7ms, beats 95.65%
MEMORY: 10.5 MB, beats 48.94%
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    const int NUMS_SIZE = nums.size();
    vector<int> copy = nums;
    sort(copy.begin(), copy.end());
    int i = 0, j = NUMS_SIZE - 1;
    while (i <= j) {
      int sum = copy[i] + copy[j];
      if (copy[i] + copy[j] == target)
        break;
      else if (sum < target)
        i++;
      else
        j--;
    }
    vector<int> ans(2);
    int k;
    for (k = 0; k < NUMS_SIZE; k++)
      if (copy[i] == nums[k]) {
        ans[0] = k;
        break;
      }
    int prev_k = k;
    for (k = 0; k < NUMS_SIZE; k++)
      if (copy[j] == nums[k] && k != prev_k) {
        ans[1] = k;
        break;
      }
    return ans;
  }
};
int main() {
  Solution a;
  vector<pair<vector<int>, int>> tests = {
      {{2, 7, 11, 15}, 9}, {{3, 2, 4}, 6}, {{3, 3}, 6}};
  for (int i = 0; i <= 2; i++) {
    vector<int> nums = tests[i].first;
    int target = tests[i].second;
    vector<int> ans = a.twoSum(nums, target);
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
  return 0;
}