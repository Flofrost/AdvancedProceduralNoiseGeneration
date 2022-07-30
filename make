#!/bin/bash

files=( "main.c" "src/APNG.c" )
args=( "-O2" "-Wfatal-errors" "-Wno-unused-result" )
libs=( "-lm" )

mkdir bin 2> /dev/null
gcc ${files[@]} ${args[@]} ${libs[@]} -o bin/apng || read