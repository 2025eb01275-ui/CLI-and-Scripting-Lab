#!/bin/bash

mkdir -p backup

processed=0
duplicates=0
backedup=0

> report.txt
> errors.txt

for file in submissions/*; do
    if [ -f "$file" ]; then
        processed=$((processed + 1))

        filename=$(basename "$file")

        if [ -f "backup/$filename" ]; then
            echo "Duplicate file: $filename" >> report.txt
            duplicates=$((duplicates + 1))
        else
            cp "$file" backup/ 2>>errors.txt
            if [ $? -eq 0 ]; then
                backedup=$((backedup + 1))
            fi
        fi
    fi
done

echo "Files Processed: $processed" >> report.txt
echo "Duplicate Files: $duplicates" >> report.txt
echo "Files Backed Up: $backedup" >> report.txt

echo "Task Completed."
