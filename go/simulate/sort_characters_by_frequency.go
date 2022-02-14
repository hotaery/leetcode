package simulate

import (
	"sort"
)

type sortArr struct {
	cnt map[byte]int
	arr []byte
}

func (arr sortArr) Len() int { return len(arr.arr) }
func (arr sortArr) Less(i, j int) bool {
	if arr.cnt[arr.arr[i]] != arr.cnt[arr.arr[j]] {
		return arr.cnt[arr.arr[i]] > arr.cnt[arr.arr[j]]
	} 
	return arr.arr[i] < arr.arr[j]
}
func (arr sortArr) Swap(i, j int) {
	arr.arr[i], arr.arr[j] = arr.arr[j], arr.arr[i]
}

func frequencySort(s string) string {
	cnt := make(map[byte]int)

	for _, c := range s {
		cnt[byte(c)]++
	}
	
	arr := sortArr{
		cnt: cnt,
	}
	for k, _ := range cnt {
		arr.arr = append(arr.arr, k)
	}
	sort.Sort(arr) 

	idx := 0
	sByte := []byte(s)
	for _, c := range arr.arr {
		for i := 0; i < arr.cnt[c]; i++ {
			sByte[idx] = c
			idx++ 
		}
	}

	return string(sByte)
}