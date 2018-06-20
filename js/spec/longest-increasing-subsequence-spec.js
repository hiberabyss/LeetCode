describe("LIS", function(){
	var lengthOfLIS = require('../longest-increasing-subsequence');

	it("normal case", function(){
		var nums = [10, 9, 2, 5, 3, 7, 101, 18];
		expect(lengthOfLIS(nums)).toBe(4);
	});
});
