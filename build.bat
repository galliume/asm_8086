:: C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat

@echo off

clang -D _CRT_SECURE_NO_WARNINGS chipset.c -o chipset.exe

pushd .
chipset.exe
popd