#! /bin/bash

age=33

if [[ $age -gt 18 || $age -lt 40 ]]
then
    echo edad valida
else
    echo edad invalida
fi