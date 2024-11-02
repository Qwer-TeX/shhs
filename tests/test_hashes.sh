#!/bin/bash

# Function to run a test
run_test() {
    local input_file=$1
    local expected_hash=$2
    local hash_type=$3

    # Run the hashing program
    output=$(./shhs "$input_file")

    # Extract the hash from the output
    actual_hash=$(echo "$output" | grep "$hash_type" | awk '{print $2}')

    # Compare actual hash with expected hash
    if [ "$actual_hash" == "$expected_hash" ]; then
        echo "$hash_type test passed."
    else
        echo "$hash_type test failed. Expected: $expected_hash, Got: $actual_hash"
    fi
}

# Test input
echo "Hello, World!" > input.txt

# Read expected hashes from file
while read -r line; do
    # Skip empty lines and comments
    if [[ -z "$line" || "$line" =~ ^# ]]; then
        continue
    fi
    
    # Read hash type and expected value
    hash_type=$(echo "$line" | awk '{print $1}')
    expected_hash=$(echo "$line" | awk '{print $2}')

    # Run the test
    run_test "input.txt" "$expected_hash" "$hash_type"
done < expected_hashes.txt

# Cleanup
rm input.txt

echo "All tests completed."
