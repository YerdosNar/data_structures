#!/usr/bin/env bash

gcc -o test test.c intList.c intStack.c intQueue.c -O0

./test

rm test
