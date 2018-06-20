/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
	var res = [];

	for (var i = 0, j = 0; j < nums.length; j++) {
		if (j + 1 == nums.length || nums[j+1] != nums[j] + 1) {
			if (i === j) res.push(String(nums[i]));
			else res.push(String(nums[i]) + "->" + String(nums[j]));
			i = j+1;
		}
	}

	return res;
};

module.exports = summaryRanges;
