#! /bin/bash

./serverB &
sleep 1
for((i=0;i<25;i++))
do
    ./clienteB
done
kill %1

