package simulate

import "strconv"

// https://leetcode-cn.com/problems/fizz-buzz/

func calSumOfDigit(v int, prevSum int) int {
	if v == 1 {
		return 1
	}

	prev := v - 1
	if prev%10 < 9 {
		return prevSum + 1
	}

	for prev > 0 {
		if prev%10 == 9 {
			prevSum -= 9
		} else {
			break
		}
		prev = prev / 10
	}
	return prevSum + 1
}

func fizzBuzz(n int) []string {
	arr3 := make([]int, 0)
	arr5 := make([]int, 0)
	arr35 := make([]int, 0)
	res := make([]string, n)

	sumOfDigit := 0
	for i := 1; i <= n; i++ {
		res[i-1] = strconv.Itoa(i)
		sumOfDigit = calSumOfDigit(i, sumOfDigit)
		lastDigit := i % 10
		if sumOfDigit%3 == 0 && (lastDigit == 0 || lastDigit == 5) {
			arr35 = append(arr35, i)
		} else if sumOfDigit%3 == 0 {
			arr3 = append(arr3, i)
		} else if lastDigit == 0 || lastDigit == 5 {
			arr5 = append(arr5, i)
		}
	}

	for _, i := range arr3 {
		res[i-1] = "Fizz"
	}
	for _, i := range arr5 {
		res[i-1] = "Buzz"
	}
	for _, i := range arr35 {
		res[i-1] = "FizzBuzz"
	}
	return res
}
