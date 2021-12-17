package simulate

// https://leetcode-cn.com/problems/peeking-iterator/

type Iterator struct {
	data []int
	curr int
}

func (it *Iterator) hasNext() bool {
	return it.curr < len(it.data)
}

func (it *Iterator) next() int {
	v := it.data[it.curr]
	it.curr++
	return v
}

type PeekingIterator struct {
	it    *Iterator
	flag bool 
	val int	
}

func Constructor(iter *Iterator) *PeekingIterator {
	pit := &PeekingIterator{
		it:    iter,
	}
	if pit.it.hasNext() {
		pit.flag = true
		pit.val = pit.it.next()
	}
	return pit
}

func (p *PeekingIterator) hasNext() bool {
	return p.flag
}

func (p *PeekingIterator) next() int {
	ans := p.val 
	p.flag = p.it.hasNext() 
	if p.flag {
		p.val = p.it.next()	
	} 
	return ans 
}

func (p *PeekingIterator) peek() int {
	return p.val
}
