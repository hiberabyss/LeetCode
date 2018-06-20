/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  var cnt = 0;
  for (var i = 0, N = nums.length; i < N; i++) {
	if (nums[i] === 0) cnt++;
	else if (cnt) {
	  nums[i-cnt] = nums[i];
	  nums[i] = 0;
	}
  }
};

var nums = [0, 1, 0, 3, 12];
moveZeroes(nums);
console.log("hello: " + nums);

