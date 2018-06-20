describe("AddDigtsSuite", function() {
	var addDigits = require('../add-digits');

    it("Positive Number", function() {
      expect(addDigits(38)).toBe(2);
    });
});
