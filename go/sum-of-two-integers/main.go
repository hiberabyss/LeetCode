package main

// https://en.wikipedia.org/wiki/Adder_%28electronics%29#Half_adder
// http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
// A B C # C = (A & B) || (C_in & (A ^ B)) 

func getSum(a int, b int) int {
	if b == 0 {
		return a
	}

	return getSum(a^b, (a&b) << 1)
}

func getSum1(a int, b int) int {
	res := uint(0)
	cb := uint(0)
	for i := uint(0); i < 64; i++ {
		ab := uint((1<<i) & a)
		bb := uint((1<<i) & b)
		res |= ab ^ bb ^ cb
		if (ab & bb) != 0 || (cb & (ab ^ bb)) != 0 {
			cb = (1<<(i+1))
		}
	}

	return int(res)
}
