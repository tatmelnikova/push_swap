#!/bin/bash

EXEC=./push_swap
CHECKER=./checker_linux

echo "===== VALID TEST ====="
ARG="4 67 3 87 5"
echo "Input: $ARG"
$EXEC --complex $ARG
echo "----------------------"

echo "===== INVALID TESTS ====="

# 1. Non-numeric parameters
echo "Test: Non-numeric input"
OUTPUT=$($EXEC 1 2 a 4 2>&1)
[ "$OUTPUT" = "Error" ] && echo "✅ Passed" || echo "❌ Failed ($OUTPUT)"
echo "----------------------"

# 2. Duplicate numbers
echo "Test: Duplicate numbers"
OUTPUT=$($EXEC 1 2 3 2 2>&1)
[ "$OUTPUT" = "Error" ] && echo "✅ Passed" || echo "❌ Failed ($OUTPUT)"
echo "----------------------"

# 3. INT overflow
echo "Test: INT overflow"
OUTPUT=$($EXEC 1 2 2147483648 2>&1)
[ "$OUTPUT" = "Error" ] && echo "✅ Passed" || echo "❌ Failed ($OUTPUT)"
echo "----------------------"

# 4. No arguments
echo "Test: No arguments"
OUTPUT=$($EXEC 2>&1)
[ -z "$OUTPUT" ] && echo "✅ Passed (No output)" || echo "❌ Failed ($OUTPUT)"
echo "----------------------"

# 5. Checker test
echo "===== CHECKER TEST ====="
ARG="2 1 0"

INSTRUCTIONS=$($EXEC $ARG)
RESULT=$(echo "$INSTRUCTIONS" | $CHECKER $ARG)
COUNT=$(echo "$INSTRUCTIONS" | wc -l | tr -d ' ')

echo "Input: $ARG"
echo "Checker result: $RESULT"
echo "Instruction count: $COUNT"

if [ "$RESULT" = "OK" ]; then
    echo "✅ Checker OK"
else
    echo "❌ Checker failed"
fi

if [ "$COUNT" -le 3 ]; then
    echo "🔥 Excellent (≤3)"
elif [ "$COUNT" -le 5 ]; then
    echo "👍 Acceptable (≤5)"
else
    echo "⚠️ Too many instructions"
fi

# 6. Checker test
echo "===== CHECKER TEST ====="
ARG="1 5 2 4 3"

INSTRUCTIONS=$($EXEC $ARG)
RESULT=$(echo "$INSTRUCTIONS" | $CHECKER $ARG)
COUNT=$(echo "$INSTRUCTIONS" | wc -l | tr -d ' ')

echo "Input: $ARG"
echo "Checker result: $RESULT"
echo "Instruction count: $COUNT"

if [ "$RESULT" = "OK" ]; then
    echo "✅ Checker OK"
else
    echo "❌ Checker failed"
fi

if [ "$COUNT" -le 12 ]; then
    echo "🔥 Excellent (≤12)"
elif [ "$COUNT" -le 15 ]; then
    echo "👍 Acceptable (≤15)"
else
    echo "⚠️ Too many instructions"
fi

echo "===== DONE ====="


# 7 Checker test
for i in 1 2 3
do
    ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')

    INSTRUCTIONS=$($EXEC $ARG)
    RESULT=$(echo "$INSTRUCTIONS" | $CHECKER $ARG)
    COUNT=$(echo "$INSTRUCTIONS" | wc -l | tr -d ' ')

    echo "Run #$i"
    echo "Checker result: $RESULT"
    echo "Instruction count: $COUNT"

    if [ "$RESULT" = "OK" ]; then
        echo "✅ Checker OK"
    else
        echo "❌ Checker failed"
    fi

    if [ "$COUNT" -le 700 ]; then
        echo "🔥 Excellent (<700)"
    elif [ "$COUNT" -le 1500 ]; then
        echo "👍 Good (<1500)"
    elif [ "$COUNT" -le 2000 ]; then
        echo "✅ Acceptable (<2000)"
    else
        echo "⚠️ Too many instructions"
    fi

    echo "----------------------"
done


# 8. Checker 500 test
for i in 1 2 3
do
    ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')

    INSTRUCTIONS=$($EXEC $ARG)
    RESULT=$(echo "$INSTRUCTIONS" | $CHECKER $ARG)
    COUNT=$(echo "$INSTRUCTIONS" | wc -l | tr -d ' ')

    echo "Run #$i"
    echo "Checker result: $RESULT"
    echo "Instruction count: $COUNT"

    if [ "$RESULT" = "OK" ]; then
        echo "✅ Checker OK"
    else
        echo "❌ Checker failed"
    fi

    if [ "$COUNT" -le 5500 ]; then
        echo "🔥 Excellent (<5500)"
    elif [ "$COUNT" -le 8000 ]; then
        echo "👍 Good (<8000)"
    elif [ "$COUNT" -le 12000 ]; then
        echo "✅ Acceptable (<12000)"
    else
        echo "⚠️ Too many instructions"
    fi

    echo "----------------------"
done

# 9. Strategy comparison test (50 random numbers)
echo "===== STRATEGY TEST (50 random numbers) ====="

ARG=$(shuf -i 1-200 -n 50 | tr '\n' ' ')

echo "Input generated"

run_test () {
    FLAG=$1
    LABEL=$2

    if [ -z "$FLAG" ]; then
        INSTRUCTIONS=$($EXEC $ARG)
    else
        INSTRUCTIONS=$($EXEC $FLAG $ARG)
    fi

    RESULT=$(echo "$INSTRUCTIONS" | $CHECKER $ARG)
    COUNT=$(echo "$INSTRUCTIONS" | wc -l | tr -d ' ')

    echo "$LABEL -> Result: $RESULT | Ops: $COUNT" >&2

    if [ "$RESULT" != "OK" ]; then
        echo "❌ $LABEL failed" >&2
    fi

    echo "$COUNT"
}

SIMPLE=$(run_test "--simple" "simple")
MEDIUM=$(run_test "--medium" "medium")
COMPLEX=$(run_test "--complex" "complex")
ADAPTIVE=$(run_test "" "adaptive(default)")

echo "----- Comparison -----"
echo "simple:   $SIMPLE"
echo "medium:   $MEDIUM"
echo "complex:  $COMPLEX"
echo "adaptive: $ADAPTIVE"

# Basic expectation check
if [ "$COMPLEX" -lt "$SIMPLE" ]; then
    echo "✅ complex is more efficient than simple"
else
    echo "⚠️ complex not better than simple (may need tuning)"
fi

#shuf -i 1-500 -n 100
# shuf -i 0-9999 -n 10 > args.txt ; ./push_swap --bench $(cat args.txt)

# Test with 100 random numbers. Use the checker binary provided.
# Generate random numbers using: shuf -i 1-500 -n 100
# Run the test 2-3 times with different random sets.
# Check that the checker displays "OK" for all tests
# The program should use less than 2000 operations to pass this test.
# Less than 1500 is good, less than 700 is excellent performance.
# Note: Some variation between runs is normal. Focus on overall correctness.

# Test different strategy flags with the same input:
# Generate 50 random numbers: shuf -i 1-200 -n 50
# Test the same input with --simple, --medium, --complex flags
# Most should produce valid output that sorts correctly
# Generally, --complex should use fewer instructions than --simple
# The --adaptive flag (or no flag) should work and choose automatically
# Note: It's acceptable if not all strategies are perfectly optimized.
# The important thing is that they work and show some performance differences.

# Test with 500 random numbers. Use the checker binary provided.
# Generate using: shuf -i 1-1000 -n 500
# Run the test 2 times with different random sets
# Check that the checker displays "OK" for both tests
# The program should use less than 12000 operations to pass this test.
# Less than 8000 is good, less than 5500 is excellent performance.
# Note: This is a challenging test. Some variation in performance is expected.
# Focus on correctness first, then performance