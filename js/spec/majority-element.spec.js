describe("majorityElement", function(){
	var majorityElement = require('../majority-element.js');

	it("return the majority", function(){
		expect(majorityElement([1, 3, 2, 1, 1])).toEqual(1);
	});

	it("retrun zero", function(){
		expect(majorityElement([1, 2, 1, 2])).toEqual(0);
	});
});
