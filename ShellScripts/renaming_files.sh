#!/bin/bash
for file in *.txt
do 
  mv "$file" "$file%.txt}_$(date +%F).txt" 
done 

Explanation:

- for file in *.txt -> Loop through all .txt files.
- mv -> move/rename 
- _$(date +%F) -> add today's date (example: _2025-04-25) 

Use case: When you want to organize old text files automatically.
