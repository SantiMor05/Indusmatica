#! /bin/bash

./serverC &
sleep 1
for((i=0;i<25;i++))
do
    ./clienteC
done
kill %1
