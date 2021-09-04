package main

import "fmt"

type maxHeap struct {
	array []int
}

//insert adds an element to the heap
func (h *maxHeap) insert(key int) {
	h.array = append(h.array, key)
	h.maxHeapifyUp(len(h.array) - 1)
}

//extract returns the largest key, and removes it from the heap
func (h *maxHeap) extract() int {
	extracted := h.array[0]
	l := len(h.array) - 1

	//when the array is empty
	if len(h.array) == 0 {
		fmt.Println("cannot extract because array length is 0")
		return -1
	}

	//take out the last index and put it the root
	h.array[0] = h.array[l]
	h.array = h.array[:l]

	h.maxHeapifyDown(0)

	return extracted
}

//will heapify from bottom top
func (h *maxHeap) maxHeapifyUp(index int) {
	for h.array[parent(index)] < h.array[index] {
		h.swap(parent(index), index)
		index = parent(index)
	}
}

//will heapify top to bottom
func (h *maxHeap) maxHeapifyDown(index int) {

	lastIndex := len(h.array) - 1
	l, r := left(index), right(index)
	childToCompare := 0

	//loop while index has at least one child
	for l <= lastIndex {
		if l == lastIndex { //left child is the only child
			childToCompare = l
		} else if h.array[l] > h.array[r] { // left child is larger
			childToCompare = l
		} else { //right child is larger
			childToCompare = r
		}
	}

	if h.array[index] < h.array[childToCompare] {
		h.swap(index, childToCompare)
		index = childToCompare
		l, r = left(index), right(index)
	} else {
		return
	}

}

//get the parent index
func parent(i int) int {
	return (i - 1) / 2
}

//get the left child index
func left(i int) int {
	return 2*i + 1
}

//get the right child index
func right(i int) int {
	return 2*i + 2
}

//swap keys in the array
func (h *maxHeap) swap(i1, i2 int) {
	h.array[i1], h.array[i2] = h.array[i2], h.array[i1]

}

func main() {
	max := &maxHeap{}
	fmt.Println(max)
	buildHeap := []int{10, 25, 35, 67, 45, 3, 23, 13, 24, 75, 62, 18, 14, 12}
	for _, i := range buildHeap {
		max.insert(i)
		fmt.Println(max)
	}

	for _, v := range buildHeap {
		max.extract()
		fmt.Println(v, max)
	}

}
