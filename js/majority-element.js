/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
	if (nums.length < 1) return 0;
    var k = 0, cnt = 0;
	for (var i = 0, len = nums.length; i < len; i++) {
		if (cnt === 0) k = i;
		if (nums[i] === nums[k]) cnt++;
		else cnt--;
	}

	nums.forEach(function(x) { if (x === nums[k]) cnt++; });
	if (2*cnt > nums.length) return nums[k];
	return 0;
};

module.exports = majorityElement;
