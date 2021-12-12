package simulate 

// https://leetcode-cn.com/problems/reverse-bits/ 

func reverseBits(num uint32) uint32 {
	ans := uint32(0) 
	for i := 0; i < 32; i++ {
		remain := num % 2
		num /= 2 
		ans = ans << 1 
		ans = ans | remain 
	}
	return ans 
}