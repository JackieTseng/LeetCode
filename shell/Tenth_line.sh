##################################################################################
# LeetCode : Tenth Line -- https://leetcode.com/problems/tenth-line/
# Coded in Aug 10th, 2015
#
# [Problem]
# How would you print just the 10th line of a file?
#
# For example, assume that file.txt has the following content:
#
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
#
# Your script should output the tenth line, which is:
# Line 10
#
# [show hint]
# Hint:
# 1. If the file contains less than 10 lines, what should you output?
# 2. There's at least three different solutions. Try to explore all possibilities.
##################################################################################

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
