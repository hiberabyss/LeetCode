#
# [194] Transpose File
#
# https://leetcode.com/problems/transpose-file/description/
#
# shell
# Medium (21.71%)
# Total Accepted:    7.1K
# Total Submissions: 32.5K
# Testcase Example:  'a'
#
# Given a text file file.txt, transpose its content.
# 
# You may assume that each row has the same number of columns and each field is
# separated by the ' ' character.
# 
# Example:
# 
# If file.txt has the following content:
# 
# 
# name age
# alice 21
# ryan 30
# 
# 
# Output the following:
# 
# 
# name alice ryan
# age 21 30
# 
# 
# 
# 
#
# Read from the file file.txt and print its transposed content to stdout.

awk '{for (i = 1; i <= NF; i++) { if (NR == 1) L[i] = $i; else L[i] = L[i] " " $i}} END {for (i = 1; i <= length(L); i++) {print L[i]}}' file.txt
