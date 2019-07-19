#!/bin/bash
cd "$(dirname "$0")"
DBG=""
while getopts ":d" opt; do
  case $opt in
    d)
      echo "-d was selected; compiling in DEBUG mode!" >&2
      DBG=-DDEBUG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

if ! g++ -g -std=c++14 -Wall $DBG CPPFILE; then
    exit
fi
INPUT_NAME=input
OUTPUT_NAME=output
MY_NAME=my_output
rm -R $MY_NAME* &>/dev/null
for test_file in $INPUT_NAME*
do
    i=$((${#INPUT_NAME}))
    test_case=${test_file:$i}
    if !  ./a.out < $INPUT_NAME$test_case > $MY_NAME$test_case; then
        echo [1m[31mSample test \#$test_case: Runtime Error[0m 
        echo ========================================
        echo Sample Input \#$test_case
        cat $INPUT_NAME$test_case
    else
        if diff --brief --strip-trailing-cr $MY_NAME$test_case $OUTPUT_NAME$test_case; then
            echo [1m[32mSample test \#$test_case: Accepted[0m 
        else
            echo [1m[31mSample test \#$test_case: Wrong Answer[0m 
            echo ========================================
            echo Sample Input \#$test_case
            cat $INPUT_NAME$test_case
            echo ========================================
            echo Sample Output \#$test_case
            cat $OUTPUT_NAME$test_case
            echo ========================================
            echo My Output \#$test_case
            cat $MY_NAME$test_case
            echo ========================================
        fi
    fi
done
