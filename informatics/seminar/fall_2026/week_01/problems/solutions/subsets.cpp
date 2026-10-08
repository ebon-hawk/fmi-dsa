#include <vector>

using namespace std;

class Solution {
private:
    void generate_subsets(const vector<int>& nums, unsigned int i,
                          vector<int>& current, vector<vector<int>>& subsets) {
        if (i == nums.size()) {
            subsets.push_back(current);

            return;
        }

        current.push_back(nums[i]);
        generate_subsets(nums, i + 1, current, subsets);

        current.pop_back();
        generate_subsets(nums, i + 1, current, subsets);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> subsets;

        generate_subsets(nums, 0, current, subsets);
        return subsets;
    }
};