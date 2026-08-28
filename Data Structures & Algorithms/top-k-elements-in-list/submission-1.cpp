class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]].push_back(i);
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            int highestFreq = -1;
            int keyToRemove = -1;
            for (auto& pair : freq) {
                if ((int)pair.second.size() > highestFreq) {
                    highestFreq = pair.second.size();
                    keyToRemove = pair.first;
                }
            }
            result.push_back(keyToRemove);
            freq.erase(keyToRemove);
        }
        return result;
    }
};