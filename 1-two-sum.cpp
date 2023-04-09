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
      if (sum == target)
        break;
      else if (sum < target)
        i++;
      else
        j--;
    }
    int values[] = {copy[i], copy[j]};
    vector<int> ans(2);
    for (int loop = 0; loop <= 1; loop++) {
      int prev_i = loop == 0 ? NUMS_SIZE : i;
      i = NUMS_SIZE;
      while (--i >= 0)
        if (values[loop] == nums[i] && i != prev_i) {
          ans[loop] = i;
          break;
        }
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