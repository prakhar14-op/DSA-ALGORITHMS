#include <vector>

using namespace std;
class solution{
private:
    void generatesubsets(int index,vector<int>& nums,vector<int>& current, vector<vector<int>>& result){
        // Base Case
        if(index == nums.size()){
            result.push_back(current);
            return;
        }
        //DECISION 1: excluding the element at the current index
        generatesubsets(index+1,nums,current,result);

        //DECISION 2: including the element at the current index
        current.push_back(nums[index]);
        generatesubsets(index+1,nums,current,result);
        //backtrack
        current.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generatesubsets(0,nums,current,result);
        return result;
    }
};