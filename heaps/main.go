package main

import "fmt"

type maxHeap struct {
	array []int
}

func (h *maxHeap) insert(key int) {
	h.array = append(h.array, key)
	h.maxHeapifyUp(len(h.array) - 1)
}

func (h *maxHeap) maxHeapifyUp(index int) {
	for h.array[parent(index)] < h.array[index] {
		h.swap(parent(index), index)
		index = parent(index)
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
	buildHeap := []int{10, 25, 35, 67, 45}
	for _, i := range buildHeap {
		max.insert(i)
		fmt.Println(max)
	}

}
