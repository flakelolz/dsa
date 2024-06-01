#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map = {}; // value, index

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];

        if (map.count(diff)) {
            return {map[diff], i};
        }
        map[nums[i]] = i;
    }

    return {};
}
