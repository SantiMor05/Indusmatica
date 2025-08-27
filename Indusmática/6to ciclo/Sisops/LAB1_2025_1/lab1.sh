#! /bin/bash

n1=$1
n2=$2

echo "Resultado:"
while [ $n1 -le $n2 ]
do
    flagprimo=0
    x=2

    while [ $x -lt $n1 ]
    do
        if (($n1%$x == 0))  
        then
            flagprimo=1
            break
        fi
        x=$((x+1))
    done
    
    if [ $flagprimo -eq 1 ] 
    then
        echo $n1
    else
        echo "$n1 (primo)"
    fi  
    
    n1=$((n1+1))
done

echo "Los numero son $n1 y $n2" 





