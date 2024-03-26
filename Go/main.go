package main

import (
	"fmt"
	"math/rand"
	"time"
)

func producer(ch chan int) {
	i := 1
	for {
		ch <- i
		fmt.Printf("Produced %d\n", i)
		i++
		time.Sleep(time.Duration(rand.Intn(100)) * time.Millisecond)
	}
}

func consumer(ch chan int) {
	for {
		num := <-ch
		fmt.Printf("Consumed %d\n", num)
		time.Sleep(time.Duration(rand.Intn(100)) * time.Millisecond)
	}
}

func main() {
	ch := make(chan int, 5)

	go producer(ch)
	go consumer(ch)

	time.Sleep(2 * time.Second)

	close(ch)
}
