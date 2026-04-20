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