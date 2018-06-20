describe("BulbSwitch", function(){
	var bulbSwitch = require('../bulb-switcher.js');

	it("after switch", function(){
		expect(bulbSwitch(3)).toBe(1);
	});
});
