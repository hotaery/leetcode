package simulate

func canConstruct(ransomNote string, magazine string) bool {
	n := len(ransomNote)
	m := len(magazine)

	if n > m {
		return false
	}

	arr := make([]int, 26)
	for _, a := range magazine {
		idx := int(a - 'a')
		arr[idx]++
	}

	for _, a := range ransomNote {
		idx := int(a - 'a')
		if arr[idx] == 0 {
			return false
		}
		arr[idx]--
	}
	return true
}
