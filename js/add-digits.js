msg = "Hello, world";

var addDigits = function(num) {
  if (num < 10) return num;
  var res = 0;
  while (num > 0) {
	res += num % 10;
	num = Math.floor(num/10);
  }
  return addDigits(res);
};

// console.log(addDigits(38));
module.exports = addDigits;
