/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
	var N = nums.length;
	if (N <= 1) return N;
	var dp = new Array(N);

	dp[0] = 1;
	var res = 1;
	for (var i = 1; i < N; i++) {
		dp[i] = 1;
		for (var j = 0; j < i; j++) {
			if (nums[i] > nums[j]) dp[i] = Math.max(dp[i], dp[j]+1);
		}
		res = Math.max(res, dp[i]);
	}

	return res;
};

module.exports = lengthOfLIS;
