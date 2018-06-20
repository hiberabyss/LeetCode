describe("ArrayRotate", function(){
	var rotate = require('../rotate-array.js').rotate;
	// Array.prototype.reverseRange = require('../rotate-array.js').reverseRange;
	var Array = require('../rotate-array.js').Array;

	it("array reverse range", function(){
		var nums = [1, 2, 3, 4, 5];
		nums.reverseRange(0, 3);
		expect(nums).toEqual([3, 2, 1, 4, 5]);
	});

	it("rotate array", function(){
		var nums = [1,2,3,4,5,6,7];
		rotate(nums, 3);
		expect(nums).toEqual([5,6,7,1,2,3,4]);
	});
});
