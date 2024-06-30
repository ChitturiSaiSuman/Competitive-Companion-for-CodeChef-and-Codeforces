#!/bin/bash

# Paths to the Python and C++ programs
PYTHON_SCRIPT="Temp_Gen.py"
CPP_BINARY="Temp"

# Compile the C++ program only once
g++ -o $CPP_BINARY Temp.cpp -O2 -std=c++17
if [ $? -ne 0 ]; then
    echo "C++ compilation failed."
    exit 1
fi

# Incremental counter
counter=1

while true; do
    # Execute the Python script with the current counter as an argument
    python3 $PYTHON_SCRIPT $counter > STDIN

    # Execute the C++ program
    output=$(./$CPP_BINARY < STDIN)

    # Check if the C++ program printed anything
    if [ -n "$output" ]; then
        echo "C++ program output detected. Stopping the loop."
        echo "Output:\n$output"
        break
    fi

    # Increment the counter
    counter=$((counter + 1))
done
