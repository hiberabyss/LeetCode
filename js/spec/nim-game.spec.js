describe("NimGameSuite", function(){
	var canWinNim = require('../nim-game.js');

	it("should win", function(){
		expect(canWinNim(1)).toBe(true);
		expect(canWinNim(2)).toBe(true);
		expect(canWinNim(3)).toBe(true);
	});

	it("should lose", function(){
		expect(canWinNim(0)).toBe(false);
		expect(canWinNim(4)).toBe(false);
		expect(canWinNim(8)).toBe(false);
	});
});
