package simulate 

// https://leetcode-cn.com/problems/compare-version-numbers/

const (
	 blank string = "0"
)

func getFirstRevison(version []byte) []byte {
	n := len(version) 
	if n == 0 {
		return []byte(blank)
	}
	end := 0 
	for {
		if end == n || version[end] == '.' {
			break
		}
		end++
	}
	return version[0:end]
}

func ignoreLeadingZeros(s []byte) []byte {
	n := len(s)
	start := 0
	for {
		if start == n || s[start] != '0' {
			break 
		}
		start++
	}
	if start == n {
		start--
	}
	return s[start:]
}

func compareRevision(lhs []byte, rhs []byte) int {
	lhsNz := ignoreLeadingZeros(lhs)
	rhsNz := ignoreLeadingZeros(rhs) 
	n1 := len(lhsNz)
	n2 := len(rhsNz) 
	if n1 < n2 {
		return -1
	} else if (n1 > n2) {
		return 1 
	}

	for i := 0; i < n1; i++ {
		if lhsNz[i] > rhsNz[i] {
			return 1 
		} else if (lhsNz[i] < rhsNz[i]) {
			return -1
		}
	}
	return 0
}

func compareVersion(version1 string, version2 string) int {
	versionByte1 := []byte(version1)
	versionByte2 := []byte(version2) 
	if len(versionByte1) == 0 && len(versionByte2) == 0 {
		return 0
	}

	for {
		if len(versionByte1) == 0 && len(versionByte2) == 0 {
			break
		}
		firstRevision1 := getFirstRevison(versionByte1)
		firstRevision2 := getFirstRevison(versionByte2) 

		ret := compareRevision(firstRevision1, firstRevision2)
		if ret != 0 {
			return ret 
		}
		if len(versionByte1) > 0 {
			versionByte1 = versionByte1[len(firstRevision1):]
			if len(versionByte1) > 0 {
				versionByte1 = versionByte1[1:]
			}
		}
		if len(versionByte2) > 0 {
			versionByte2 = versionByte2[len(firstRevision2):] 
			if len(versionByte2) > 0 {
				versionByte2 = versionByte2[1:]
			}
		}
	}
	return 0 
} 

