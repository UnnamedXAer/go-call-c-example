package main

// #cgo LDFLAGS: -L. -llibrary
// #include "tmp.h"
import "C"

import (
	"fmt"
	"unsafe"
)

type Foo struct {
	ptr unsafe.Pointer
}

// func NewFoo() Foo {
// 	var foo Foo
// 	foo.ptr = C.LIB_geMyFoo()
// }

func main() {
	fmt.Printf("\nresult: %v", C.getMyInt())
}
