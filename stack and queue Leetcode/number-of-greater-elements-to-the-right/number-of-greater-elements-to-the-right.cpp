#include<bits/stdc++.h>
using namespace std;
#include <vector>

class Solution {
public:
    std::vector<int> count_NGE(std::vector<int>& arr, std::vector<int>& indices) {
        int n = indices.size();
        int m = arr.size();
        std::vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            int targetIndex = indices[i];
            int targetValue = arr[targetIndex];
            int count = 0;
            for(int j = targetIndex + 1; j < m; j++) {
                if(arr[j] > targetValue) {
                    count++;
                }
            }
            ans[i] = count;
        }
        
        return ans;
    }
};
