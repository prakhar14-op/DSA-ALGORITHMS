#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                h = mid - 1;  // move left
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;  // move right
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};