package simulate

import "testing"

func TestFizzBuzz(t *testing.T) {
	expect := []string{"1", "2", "Fizz"}
	actual := fizzBuzz(3)
	if len(actual) != len(expect) {
		t.Fatalf("fizzBuzz(3), length mismatch, expect=%v, actual=%v", len(expect), len(actual))
	}

	for i := 0; i < len(actual); i++ {
		if expect[i] != actual[i] {
			t.Errorf("fizzBuzz(3), value mismatch, expect=%v, actual=%v", expect, actual)
		}
	}

	expect = []string{"1", "2", "Fizz", "4", "Buzz"}
	actual = fizzBuzz(5)
	if len(actual) != len(expect) {
		t.Fatalf("fizzBuzz(5), length mismatch, expect=%v, actual=%v", len(expect), len(actual))
	}

	for i := 0; i < len(actual); i++ {
		if expect[i] != actual[i] {
			t.Errorf("fizzBuzz(5), value mismatch, expect=%v, actual=%v", expect, actual)
		}
	}

	expect = []string{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"}
	actual = fizzBuzz(15)
	if len(actual) != len(expect) {
		t.Fatalf("fizzBuzz(15), length mismatch, expect=%v, actual=%v", len(expect), len(actual))
	}

	for i := 0; i < len(actual); i++ {
		if expect[i] != actual[i] {
			t.Errorf("fizzBuzz(15), value mismatch, expect=%v, actual=%v", expect, actual)
		}
	}
}
