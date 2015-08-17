##################################################################################
# LeetCode : Word Frequency -- https://leetcode.com/problems/word-frequency/
# Coded in Aug 17th, 2015
#
# [Problem]
# Write a bash script to calculate the frequency of each word in a text file words.txt.
#
# For simplicity sake, you may assume:
#
# * words.txt contains only lowercase characters and space ' ' characters.
# * Each word must consist of lowercase characters only.
# * Words are separated by one or more whitespace characters.
#
# For example, assume that words.txt has the following content:
#
# the day is sunny the the
# the sunny is is
#
# Your script should output the following, sorted by descending frequency:
#
# the 4
# is 3
# sunny 2
# day 1
#
# Note:
# Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
#
# [show hint]
# Hint:
# Could you write it in one-line using Unix pipes?
##################################################################################
#! /bin/sh

# tr      : translate ' ' into '\n'
# sort    : sort by alphabet order (can't use sort -u here since no counter ouput)
# uniq -c : count for continuous same numbers and duplicate
# sort -r : reserve the output
# awk     : change the output format
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2, $1}'

