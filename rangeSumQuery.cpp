class NumArray {
public:
vector<int> prefixSum;
NumArray(vector<int>& nums) {
	int n = nums.size();
	if(n != 0){
		prefixSum.emplace_back(nums[0]);
		for(int i=1; i<n; i++)
			prefixSum.emplace_back(prefixSum[i-1]+nums[i]);
	}
}

int sumRange(int i, int j) {
	if(i == 0)
		return prefixSum[j];
	return prefixSum[j] - prefixSum[i-1];
}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */