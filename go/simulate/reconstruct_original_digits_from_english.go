package simulate

import "strconv"

// zero, one, two, three, four, five, six, seven, eight, nine
// e: 0, 1, 3, 5, 7, 8, 9
// g: 8
// f: 4, 5
// i: 5, 6, 8, 9
// h: 3, 8
// o: 0, 1, 2, 4
// n: 1, 7, 9
// s: 6, 7
// r: 0, 3, 4
// u: 4
// t: 2, 3, 8
// w: 2
// v: 5, 7
// x: 6
// z: 0

// 0: NUM(s, z)
// 1: NUM(s, n) - NUM(7) - 2*NUM(9)
// 2: NUM(s, w)
// 3: NUM(s, h) - NUM(8)
// 4: NUM(s, u)
// 5: NUM(s, f) - NUM(4)
// 6: NUM(s, x)
// 7: NUM(s, v) - NUM(5)
// 8: NUM(s, g)
// 9: NUM(s, i) - NUM(5) - NUM(6) - NUM(8)

func originalDigits(s string) string {
	m := make([]int, 26)
	for _, c := range s {
		idx := int(c - 'a')
		m[idx]++
	}

	arr := make([]int, 10)
	arr[0] = m[25]
	arr[2] = m[22]
	arr[4] = m[20]
	arr[6] = m[23]
	arr[8] = m[6]
	arr[3] = m[7] - arr[8]
	arr[5] = m[5] - arr[4]
	arr[7] = m[21] - arr[5]
	arr[9] = m[8] - arr[5] - arr[6] - arr[8]
	arr[1] = m[13] - arr[7] - 2*arr[9]

	var ans []byte
	for i, n := range arr {
		if n == 0 {
			continue
		}

		for j := 0; j < n; j++ {
			ans = strconv.AppendInt(ans, int64(i), 10)
		}
	}
	return string(ans)
}
