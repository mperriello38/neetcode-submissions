class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        int i = 0;

        while(i < nums.size()) {
            if(map.find(nums[i]) != map.end()) {
                return true;
            }
            map[nums[i]] = i;
            i++;
        }
        return false;
    }
};