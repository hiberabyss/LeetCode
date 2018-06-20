/**
 * @constructor
 */
var Stack = function() {
	this.data = [];
	this.exchange = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
Stack.prototype.push = function(x) {
	if (this.data.length < 1) this.data.push(x);
	else {
		for (var i = 0, len = this.data.length; i < len; i++) {
			this.exchange.push(this.data.pop());
		}

		this.data.push(x);

		for (i = 0; i < len; i++) {
			this.data.push(this.exchange.pop());
		}
	}
};

/**
 * @returns {void}
 */
Stack.prototype.pop = function() {
	return this.data.shift();
};

/**
 * @returns {number}
 */
Stack.prototype.top = function() {
	if (this.data.length > 0) return this.data[0];
	return -1;
};

/**
 * @returns {boolean}
 */
Stack.prototype.empty = function() {
	return this.data.length === 0;
};

module.exports = Stack;
