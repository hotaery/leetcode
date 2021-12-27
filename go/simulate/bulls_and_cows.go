package simulate

import "strconv"

func getHint(secret string, guess string) string {
	bulls, cows := 0, 0
	n := len(secret)
	ans := make([]byte, 0)

	for i := 0; i < n; i++ {
		if secret[i] == guess[i] {
			bulls++
		}
	}

	if bulls == n {
		ans = strconv.AppendInt(ans, int64(bulls), 10)
		ans = append(ans, "A0B"...)
		return string(ans)
	}

	m := make(map[int]int, 0)
	for i := 0; i < n; i++ {
		if secret[i] == guess[i] {
			continue
		}
		a := int(secret[i] - '0')
		b := int(guess[i] - '0')
		m[a]++ 
		if m[a] <= 0 {
			cows++
		}
		m[b]--
		if m[b] >= 0 {
			cows++
		}
	}
	ans = strconv.AppendInt(ans, int64(bulls), 10)
	ans = append(ans, 'A')
	ans = strconv.AppendInt(ans, int64(cows), 10)
	ans = append(ans, 'B')
	return string(ans)
}
