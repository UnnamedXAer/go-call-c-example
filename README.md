#

Example of how to call C/Cpp functions from Go using _cgo_.

This app uses C++ code to change sound volume.

## build

see the [build](./build.ps1) file for the build command

```powershell
./build
```

the output is `a.exe`

## run

> get volume

`./a`

> to set volume pass percentage (eg. 0, 45, 100) as an argument

`./a 66`
