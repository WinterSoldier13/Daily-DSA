vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}
vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}
vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    unordered_set<int> s;
    for (auto i = start; i < nums.size(); ++i) {
        if (res.empty() || res.back()[1] != nums[i])
            if (s.count(target - nums[i]))
                res.push_back({ target - nums[i], nums[i]});
        s.insert(nums[i]);
    }
    return res;
}