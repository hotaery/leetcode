package common

type IntArr []int

func (arr IntArr) Len() int           { return len(arr) }
func (arr IntArr) Less(i, j int) bool { return arr[i] > arr[j] }
func (arr IntArr) Swap(i, j int)      { arr[i], arr[j] = arr[j], arr[i] }