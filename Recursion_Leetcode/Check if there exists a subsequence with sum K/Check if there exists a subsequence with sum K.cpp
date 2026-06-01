#include <vector>

using namespace std;

class Solution {
private:
    bool checkSubsequence(int index, int current_sum, int k, vector<int>& nums) {
        // Base Case
        if (index == nums.size()) {
            if (current_sum == k) {
                return true;
            }
            return false;
        }
        // Decision 1: INCLUDE the current number
        // We check this branch first. If it returns true, we enter the if-block 
        // and instantly return true to the parent, completely skipping Decision 2.
        if (checkSubsequence(index + 1, current_sum + nums[index], k, nums) == true) {
            return true; 
        }

        // Decision 2: EXCLUDE the current number
        // We only ever reach this line if the Include branch completely failed (returned false).
        if (checkSubsequence(index + 1, current_sum, k, nums) == true) {
            return true;
        }
        // If both the Include and Exclude branches returned false, this is a dead end.
        return false;
    }

public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return checkSubsequence(0, 0, k, nums);
    }
};