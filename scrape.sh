#!/bin/bash

# Activate the virtual environment
source /home/suman/Competitive-Companion-for-CodeChef-and-Codeforces/.venv/bin/activate

# Run the Python script
python /home/suman/Competitive-Companion-for-CodeChef-and-Codeforces/Scrape.py

# Check the exit status of the Python script
if [ $? -eq 0 ]; then
    # If the script ran successfully, exit the terminal
    deactivate
    echo "Extraction Successful! Exiting ..."
    sleep 3
    exit
else
    # If the script was interrupted or failed, stay in the terminal
    echo "The script was interrupted or encountered an error."
fi