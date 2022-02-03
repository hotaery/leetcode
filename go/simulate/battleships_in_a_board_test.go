package simulate

import "testing"

func TestCountBattleships(t *testing.T) {
	aCase := [][]byte{
		{'X', '.', '.', 'X'},
		{'.', '.', '.', 'X'},
		{'.', '.', '.', 'X'},
	}
	expect := 2
	actual := countBattleships(aCase)
	if expect != actual {
		t.Errorf("countBattleships(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = [][]byte{
		{'.'},
	}
	expect = 0
	actual = countBattleships(aCase)
	if expect != actual {
		t.Errorf("countBattleships(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = [][]byte{
		{'X', 'X', 'X'},
	}
	expect = 1
	actual = countBattleships(aCase)
	if expect != actual {
		t.Errorf("countBattleships(%v), expect=%v, actual=%v", aCase, expect, actual)
	}
}
