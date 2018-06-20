/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */

var containsNearbyAlmostDuplicate = function(nums, k, t) {
  var N = nums.length;
  if (N <= 1 || k < 1) return false;

  var pairs = [];

  for (var i = 0; i < N; i++) {
	pairs.push([nums[i], i]);
  }

  pairs.sort(function(a, b) { return a[0] - b[0]; });

  for (i = 0; i < N; i++) {
	var j = i+1;
	while (j < N) {
	  if (Math.abs(pairs[i][0] - pairs[j][0]) > t) break;
	  if (Math.abs(pairs[i][1] - pairs[j][1]) <= k) return true;
	  j++;
	}
  }

  return false;
};

{
  var nums = [4, 2];
  console.log(containsNearbyAlmostDuplicate(nums, 2, 3));
}

{
  var nums = [-1, -1];
  console.log(containsNearbyAlmostDuplicate(nums, 1, -1));
}
