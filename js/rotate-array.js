/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
Array.prototype.reverseRange = function(begin, end) {
	for (var i = begin, j = end-1; i<j; i++, j--) {
		var tmp = this[i];
		this[i] = this[j];
		this[j] = tmp;
	}
};

var rotate = function(nums, k) {
	if (nums.length < 1) return;
	k %= nums.length;

	nums.reverse();
	nums.reverseRange(0, k);
	nums.reverseRange(k, nums.length);
};

// var nums = [1,2];
// nums.reverseRange(0, 2);
// rotate(nums, 0);
// console.log(nums);

module.exports.rotate = rotate;
// module.exports.reverseRange = Array.prototype.reverseRange;
module.exports.Array = Array;
