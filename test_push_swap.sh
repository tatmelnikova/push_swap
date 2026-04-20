#!/bin/bash

EXEC=./push_swap

echo "===== VALID TEST ====="
ARG="4 67 3 87 5"
echo "Input: $ARG"
$EXEC --complex $ARG
echo "----------------------"

echo "===== INVALID TESTS ====="

# 1. Non-numeric parameters
echo "Test: Non-numeric input"
OUTPUT=$($EXEC 1 2 a 4 2>&1)
if [ "$OUTPUT" = "Error" ]; then
    echo "✅ Passed"
else
    echo "❌ Failed (Output: $OUTPUT)"
fi
echo "----------------------"

# 2. Duplicate numbers
echo "Test: Duplicate numbers"
OUTPUT=$($EXEC 1 2 3 2 2>&1)
if [ "$OUTPUT" = "Error" ]; then
    echo "✅ Passed"
else
    echo "❌ Failed (Output: $OUTPUT)"
fi
echo "----------------------"

# 3. Number greater than INT_MAX
echo "Test: INT overflow"
OUTPUT=$($EXEC 1 2 2147483648 2>&1)
if [ "$OUTPUT" = "Error" ]; then
    echo "✅ Passed"
else
    echo "❌ Failed (Output: $OUTPUT)"
fi
echo "----------------------"

# 4. No arguments
echo "Test: No arguments"
OUTPUT=$($EXEC 2>&1)
if [ -z "$OUTPUT" ]; then
    echo "✅ Passed (No output)"
else
    echo "❌ Failed (Output: $OUTPUT)"
fi
echo "----------------------"

echo "===== DONE ====="