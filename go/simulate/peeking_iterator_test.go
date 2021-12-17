package simulate

import "testing"

func TestPeekingIterator(t *testing.T) {
	case1 := []int{1, 2, 3}	
	iter1 := &Iterator{
		data: case1,
		curr: 0,
	}
	pit1 := Constructor(iter1)

	v := pit1.next()
	if v != 1 {
		t.Errorf("next, expect=%d, actual=%d\n", 1, v)
	}

	v = pit1.peek()
	if v != 2 {
		t.Errorf("peek, expect=%d, actual=%d\n", 2, v)
	}

	v = pit1.next() 
	if v != 2 {
		t.Errorf("next, expect=%d, actual=%d\n", 2, v)
	}

	v = pit1.next() 
	if v != 3 {
		t.Errorf("next, expect=%d, actual=%d\n", 3, v)
	}	

	if pit1.hasNext() {
		t.Errorf("hasNext, expect=false, actual=true\n")
	}

	case2 := []int{1,2,3,4}
	iter2 := &Iterator{
		data: case2, 
		curr: 0,
	}
	pit2 := Constructor(iter2) 

	if pit2.hasNext() != true {
		t.Errorf("hasNext, expect=true, actual=false\n")
	}
	v = pit2.peek() 
	if v != 1 {
		t.Errorf("peek, expect=1, actual=%d\n", v)	
	}
	v = pit2.peek() 
	if v != 1 {
		t.Errorf("peek, expect=1, actual=%d\n", v)	
	}
	v = pit2.next() 
	if v != 1 {
		t.Errorf("peek, expect=1, actual=%d\n", v)	
	}
	v = pit2.next() 
	if v != 2 {
		t.Errorf("peek, expect=2, actual=%d\n", v)	
	}	
	v = pit2.peek() 
	if v != 3 {
		t.Errorf("peek, expect=3, actual=%d\n", v)	
	}
	v = pit2.peek() 
	if v != 3 {
		t.Errorf("peek, expect=3, actual=%d\n", v)	
	}
	v = pit2.next() 
	if v != 3 {
		t.Errorf("peek, expect=3, actual=%d\n", v)	
	}
	if pit2.hasNext() != true {
		t.Errorf("hasNext, expect=true, actual=false\n")
	}
	v = pit2.peek() 
	if v != 4 {
		t.Errorf("peek, expect=4, actual=%d\n", v)	
	}	
	if pit2.hasNext() != true {
		t.Errorf("hasNext, expect=true, actual=false\n")
	}
	v = pit2.next() 
	if v != 4 {
		t.Errorf("peek, expect=4, actual=%d\n", v)	
	}
	if pit2.hasNext() {
		t.Errorf("hasNext, expect=false, actual=true\n")
	}	
}