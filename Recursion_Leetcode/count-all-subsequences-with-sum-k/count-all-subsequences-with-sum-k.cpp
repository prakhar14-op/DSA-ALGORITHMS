#include <vector>
using namespace std;

class Solution {
private:
    int countSubsequences(int index, int current_sum, int k, vector<int>& nums) {
        // Base Case
        if (index == nums.size()) {
            if (current_sum == k) {
                return 1;
            }
            return 0;
        }

        // Decision 1: EXCLUDE the current number
        // We move to the next index, and the sum stays exactly the same.
        int exclude_count = countSubsequences(index + 1, current_sum, k, nums);

        // Decision 2: INCLUDE the current number
        // We move to the next index, and add the current number to our sum.
        int include_count = countSubsequences(index + 1, current_sum + nums[index], k, nums);

        // Return the total valid paths found by both branches
        return exclude_count + include_count;
    }

public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        return countSubsequences(0, 0, k, nums);
    }
};