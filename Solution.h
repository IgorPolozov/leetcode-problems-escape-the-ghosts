////https://leetcode.com/problems/escape-the-ghosts/description/
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using std::vector;
//the task is easy and resolved in single line of std code which beats 100% by speed. And memory is high becouse, - yes, std is std :)
class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		
		auto cmp = [&target](const vector<int> left, const vector<int> right) {

			return  std::abs(target[0] - left[0]) + std::abs(target[1] - left[1]) <
				std::abs(target[0] - right[0]) + std::abs(target[1] - right[1]);
		};

		auto minghost = std::min_element(ghosts.begin(), ghosts.end(), cmp);
					

		return  std::abs(target[0]) + std::abs(target[1]) <
			std::abs(target[0] - (*minghost)[0]) + std::abs(target[1] - (*minghost)[1]);
	}
};
