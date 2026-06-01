#include<vector>
using namespace std;
class Solution {
private:
    void findcombinations(int index,int target,vector<int>& candidates,vector<int>& current, vector<vector<int>>& result){
        //1. base case
        if(target==0){
            result.push_back(current);
            return;
        }

        //2. base case 
        if(target<0 || index==candidates.size()){
            return;
        }
        //dec 1
        current.push_back(candidates[index]);
        findcombinations(index,target-candidates[index],candidates,current,result);

        current.pop_back();
        //dec 2
        findcombinations(index+1,target,candidates,current,result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findcombinations(0,target,candidates,current,result);
        return result;
    }
};