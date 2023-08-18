class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> solution;
        if(nums.size() == 0){
            solution.push_back(-1);
            solution.push_back(-1);
            return solution;
        }

        int
        n = nums.size(),
        l = -1,
        r = n,
        m = 0;

        while(l+1 < r){
            m = l+(r-l)/2;
            if(nums[m] < target){
                l = m;
            } else{
                r = m;
            }
        }
        (r-n && nums[r] == target) ? solution.push_back(r) : solution.push_back(-1);

        l = r-1, r = n;
        while(l+1 < r){
            m = l+(r-l)/2;
            if(nums[m] > target){
                r = m;
            } else{
                l = m;
            }
        }
        (l+1 && nums[l] == target) ? solution.push_back(l) : solution.push_back(-1);
        
        return solution;
    }
};