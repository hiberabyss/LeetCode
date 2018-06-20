describe("ValidAnagram", function(){
	var isAnagram = require('../valid-anagram.js').isAnagram;
	var strSort = require('../valid-anagram.js').strSort;

	it("string sort", function(){
		expect(strSort("anagram")).toEqual("aaagmnr");
	});

	it("is angaram", function(){
		expect(isAnagram("anagram", "nagaram")).toBeTruthy();
	});

	it("is not anagram", function(){
		expect(isAnagram("rat", "car")).toBeFalsy();
	});
});
