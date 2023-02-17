package main

// #cgo LDFLAGS: -lole32 -loleaut32
// #include "sys-volume-bridge.h"
import "C"

// https://blog.marlin.org/cgo-referencing-c-library-in-go
// https://stackoverflow.com/questions/50722026/how-to-get-and-set-system-volume-in-windows

import (
	"fmt"
	"os"
	"strconv"
	"unsafe"
)

type Foo struct {
	ptr unsafe.Pointer
}

func main() {
	args := os.Args[1:]
	if len(args) < 1 {
		fmt.Printf("current sound volume is %v\n", int(C.LIB_getSystemVolume()*100))
		return
	}

	argVolume, err := strconv.Atoi(args[0])
	if err != nil {
		panic(err)
	}

	if argVolume < 0 {
		panic("volume cannot be lesser than 0")
	}
	if argVolume > 100 {
		panic("volume cannot be greater than 100")
	}

	var prevVolume float32 = float32(C.LIB_getSystemVolume())
	fmt.Printf("previous volume: %v\n", prevVolume)

	// increaseResult := C.LIB_increaseSystemVolume()

	var newVolume float32 = float32(argVolume) / 100.0
	var c_newVolume C.float = C.float(newVolume)
	fmt.Printf("arg volume: %v, new volume: %v, c_volume: %v\n", argVolume, newVolume, c_newVolume)
	fmt.Print("setting new volume... ")
	setResult := C.LIB_setSystemVolume(c_newVolume)
	fmt.Printf("result: %v\n", setResult)

	updatedVolume := C.LIB_getSystemVolume()

	fmt.Printf("updated volume: %v, %v\n", int(updatedVolume*100), updatedVolume)
}
