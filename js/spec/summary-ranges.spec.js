describe("SummanryRanges", function(){
	var summaryRanges = require('../summary-ranges');

	it("return string array", function(){
		expect(summaryRanges([0,1,2,4,5,7])).toEqual(["0->2","4->5","7"]);
	});
});
