class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            map[nums[i]] = i;
            i++;
        }
        int lgstSq = 0;
        for (auto pair : map) {
            int crtSq = 0;
            if (map.find(pair.first - 1) == map.end()) {
                int j = 0;
                while (map.find(pair.first + j) != map.end()) {
                    j++;
                    crtSq++;
                }
            }
            lgstSq = max(lgstSq, crtSq);
        }
        return lgstSq;
    }
};
