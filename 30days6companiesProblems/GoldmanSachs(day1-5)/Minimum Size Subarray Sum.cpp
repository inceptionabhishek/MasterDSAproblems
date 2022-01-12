class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum_val=0;
        int len=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            sum_val += nums[i];
            while(sum_val>=target){
                len = min(len,i-left+1);
                sum_val-= nums[left];
                left++;
            }
        }
        return len==nums.size()+1 ? 0: len;
    }
};