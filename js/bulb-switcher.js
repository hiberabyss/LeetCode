/**
 * @param {number} n
 * @return {number}
 */

var bulbSwitch = function(n) {
	var cnt = 0;
	for (var i = 1; i*i <= n; i++) {
		cnt++;
	}
	return cnt;
};

var bulbSwitch2 = function(n) {
	if (n <= 0) return 0;
	var bulbs = new Array(n);
	bulbs.fill(true);

	for (var i = 2, len = bulbs.length; i <= len; i++) {
		for (var j = i-1; j < len; j += i) {
			bulbs[j] = !bulbs[j];
		}
	}

	var cnt = 0;
	for (i = 0; i < len; i++) {
		if (bulbs[i]) cnt++;
	}
	return cnt;
};

module.exports = bulbSwitch;
