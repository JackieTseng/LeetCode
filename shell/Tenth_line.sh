# Solution One
#! /bin/sh
line=10
all=$(cat file.txt | wc -l)
file=file.txt
if [ $all -ge $line ];then
    sed "$line p;d" $file
fi

# Solution Two
sed -n 10p file.txt
sed '10!d' file.txt
sed '10q;d' file.txt

# Solution Three
tail -n+10 file.txt | head -1

#Solution Four
awk 'NR == 10' file.txt
awk 'NR == 10{print $0}' file.txt
awk 'FNR == 10'  file.txt
