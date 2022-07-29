#!/bin/bash

files=( "main.c" "src/APNG.c" )
args=( "-O2" "-Wfatal-errors" "-Wno-unused-result" )

mkdir bin 2> /dev/null
gcc ${args[@]} ${files[@]} -o bin/apng || read