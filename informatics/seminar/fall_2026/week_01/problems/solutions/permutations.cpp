#include <cstdint>
#include <vector>

using namespace std;

class Solution {
private:
    void generate_permutations(const vector<int>& nums, vector<int>& current,
                               vector<uint8_t>& used,
                               vector<vector<int>>& permutations) {
        if (current.size() == nums.size()) {
            permutations.push_back(current);
            return;
        }

        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                current.push_back(nums[i]);
                used[i] = 1;

                generate_permutations(nums, current, used, permutations);

                current.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<uint8_t> used(nums.size(), 0);
        vector<vector<int>> permutations;

        generate_permutations(nums, current, used, permutations);
        return permutations;
    }
};