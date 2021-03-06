//https://leetcode.com/problems/permutations/
class Solution {
public:
    
    void findAllPermutations(vector<int> &nums,vector<int> &freq,vector<vector<int>> &res,vector<int> &ds){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                findAllPermutations(nums,freq,res,ds);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
      
        findAllPermutations(nums,freq,res,ds);
        return res;
    }
};
