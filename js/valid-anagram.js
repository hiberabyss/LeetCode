/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
function strSort(s) {
	var cnt = new Array(26);
	cnt.fill(0);

	for (var i = 0, len = s.length; i < len; i++) {
		cnt[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
	}

	var res = "";
	for (i = 0; i < 26; i++) {
		for (var j = 0; j < cnt[i]; j++) {
			res += String.fromCharCode(i + 'a'.charCodeAt(0));
		}
	}

	return res;
}
var isAnagram = function(s, t) {
	var ss = strSort(s);
	var st = strSort(t);
	return ss === st;
};

module.exports.isAnagram = isAnagram;
module.exports.strSort = strSort;
