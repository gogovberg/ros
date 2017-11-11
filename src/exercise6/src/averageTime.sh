awk '{s+=$1} {i+=1} END {print s/i}' Time.txt

