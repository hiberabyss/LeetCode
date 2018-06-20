describe("ContainsDuplicate", function(){
	var containsDuplicate = require('../contains-duplicate');

	it("should return false", function(){
		expect(containsDuplicate([])).toBe(false);
		expect(containsDuplicate([1,2,3])).toBe(false);
		expect(containsDuplicate([2, 1, 5, 3,])).toBe(false);
	});

	it("should return true", function(){
		expect(containsDuplicate([1, 1])).toBe(true);
		expect(containsDuplicate([1, 2, 1])).toBe(true);
	});
});
