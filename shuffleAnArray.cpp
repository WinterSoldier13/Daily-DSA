class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr= nums;
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = arr;
        random_shuffle(nums.begin(), nums.end());
        return nums;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */