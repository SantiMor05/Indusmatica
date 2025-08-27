#! /bin/bash

usuario=$1

while read line
do  
    #saned,alejandro
    cadena=${line##*:}
    if [[ $cadena == *alejandro* ]] 
    then 
        echo ${line%%:*}
    fi
done < ./group
