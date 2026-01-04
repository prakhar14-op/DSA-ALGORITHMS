#include<iostream>
#include<vector>
using namespace std;

// method 1
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int d_count=0;
        int summ=0;
        vector<int> d_arr;
        int n=nums.size();
        for (int i=0;i<n;i++){
            d_count = 0;
            d_arr.clear();
            for(int j=1;j<=nums[i];j++){
                if(nums[i]%j==0){
                    d_count++;
                    int number_to_add=j;
                    d_arr.push_back(number_to_add);
                }
            }
            if(d_count==4){
                summ +=accumulate(d_arr.begin(), d_arr.end(), 0);
               
            }
        
        }
        return summ;
    }
};

// method 2
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;

        for (int num : nums) {
            int d_count = 0;
            int d_sum = 0;

            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    int d1 = i;
                    int d2 = num / i;

                    if (d1 == d2) {
                        d_count++;
                        d_sum += d1;
                    } else {
                        d_count += 2;
                        d_sum += d1 + d2;
                    }
                }
                if (d_count > 4) break;
            }

            if (d_count == 4) {
                total_sum += d_sum;
            }
        }

        return total_sum;
    }
};



