package simulate

func singleNumber(nums []int) []int {
	v := uint32(0)
	for _, i := range nums {
		v = v ^ uint32(i)
	}
	high := uint32(0)
	for v > 0 {
		v = v >> 1
		high++
	}
	high = 1 << (high-1)

	v1, v2 := uint32(0), uint32(0)
	for _, i := range nums {
		u := uint32(i)
		if u&high != 0 {
			v2 = v2 ^ u
		} else {
			v1 = v1 ^ u
		}
	}

	return []int{int(int32(v1)), int(int32(v2))}
}
