package main

func addDigits(num int) int {
	if num < 10 {
		return num
	} else if num%9 == 0 {
		return 9
	}

	return num%9
}

func addDigits1(num int) int {
	for num > 9 {
		tmp := num
		res := 0
		for tmp > 0 {
			res += tmp % 10
			tmp /= 10
		}
		num = res
	}

	return num
}
