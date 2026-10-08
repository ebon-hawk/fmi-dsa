#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
private:
    void generate_multiset_permutations(const vector<int>& nums,
                                        vector<int>& current,
                                        vector<uint8_t>& used,
                                        vector<vector<int>>& permutations) {
        if (current.size() == nums.size()) {
            permutations.push_back(current);
            return;
        }

        bool is_value_processed = false;
        int last_seen_value = -1;

        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (!used[i] &&
                (!is_value_processed || last_seen_value != nums[i])) {
                current.push_back(nums[i]);
                used[i] = 1;

                is_value_processed = true;
                last_seen_value = nums[i];

                generate_multiset_permutations(nums, current, used,
                                               permutations);

                current.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute_unique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<uint8_t> used(nums.size(), 0);
        vector<vector<int>> permutations;

        generate_multiset_permutations(nums, current, used, permutations);
        return permutations;
    }
};