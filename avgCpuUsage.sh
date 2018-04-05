#!/bin/bash

COUNTER=0
while  [  $COUNTER -lt $1 ]; 
        do  
                CPU_ALL=100.00
                CPU_IDLE=$(mpstat -P ALL 1 1| awk '/Average:/ && $2 ~ /[a-z]/ {print $12}');
                CPU_IDLE=$(echo $CPU_IDLE | tr , .)
                CPU_USAGE=$( bc <<< "$CPU_ALL - $CPU_IDLE" )
                echo $CPU_USAGE >> $2
                let COUNTER=COUNTER+1 
        done
