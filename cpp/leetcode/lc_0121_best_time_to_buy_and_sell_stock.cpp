#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

int maxProfit_2Pointers(vector<int>& prices) {
    int left = 0;
    int right = 1;
    int max = 0;

    while (right < prices.size()) {

        if (prices[left] < prices[right]) {

            int current = prices[right] - prices[left];
            max = std::max(max, current);
        } else {
            left = right;
        }

        right++;
    }

    return max;
}

int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int max = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < min) {
            min = prices[i];
        } else if (prices[i] - min > max) {
            max = prices[i] - min;
        }
    }
    return max;
}
