/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
	nums.sort();
	for (var i = 0, len = nums.length; i+1 < len; i++) {
		if (nums[i] == nums[i+1]) return true;
	}
	return false;
};

module.exports = containsDuplicate;
