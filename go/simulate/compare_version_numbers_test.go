package simulate

import "testing"

func TestCompareVersionNumber(t *testing.T) {
	version1 := "1.01"
	version2 := "1.001"

	ret := compareVersion(version1, version2)
	if ret != 0 {
		t.Errorf("v1=%s,v2=%s,actual=%d,expect=%d\n", version1, version2, ret, 0)
	}

	version1 = "1.0"
	version2 = "1.0.0"
	ret = compareVersion(version1, version2)
	if ret != 0 {
		t.Errorf("v1=%s,v2=%s,actual=%d,expect=%d\n", version1, version2, ret, 0)	
	}

	version1 = "0.1"
	version2 = "1.1"
	ret = compareVersion(version1, version2)
	if ret != -1 {
		t.Errorf("v1=%s,v2=%s,actual=%d,expect=%d\n", version1, version2, ret, -1)	
	}	

	version1 = "1.0.1"
	version2 = "1"
	ret = compareVersion(version1, version2)
	if ret != 1 {
		t.Errorf("v1=%s,v2=%s,actual=%d,expect=%d\n", version1, version2, ret, 1)	
	}	

	version1 = "7.5.2.4"
	version2 = "7.5.3"
	ret = compareVersion(version1, version2)
	if ret != -1 {
		t.Errorf("v1=%s,v2=%s,actual=%d,expect=%d\n", version1, version2, ret, -1)	
	}	
}
