#! /bin/bash

./serverA &
sleep 1
for((i=0;i<25;i++));do
    ./clienteA
done;
kill %1
