#!/bin/bash

echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  report.c tests @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

echo
echo "[[[[ test case 0: compiling report.c ]]]]"
echo "********************************************************************************"
echo "gcc -o report report.c"
gcc -o report report.c
echo "********************************************************************************"
echo
echo "[[[[ test case 1: EXPECTED TO FAIL - missing parameter ]]]]"
echo "********************************************************************************"
echo "./report data.csv"
./report data.csv
echo "********************************************************************************"
echo
echo "[[[[ test case 2: EXPECTED TO FAIL - missing file ]]]]"
echo "********************************************************************************"
echo "./report nosuchdata.csv "Jane Doe" rpt.txt"
./report nosuchdata.csv "Jane Doe" rpt.txt
echo "********************************************************************************"
echo
echo "[[[[ test case 3: EXPECTED TO FAIL - missing user in data file ]]]]"
echo "********************************************************************************"
echo "./report data.csv "Jane Doe" rpt.txt"
./report data.csv "Jane Doe" rpt.txt
echo "********************************************************************************"
echo
echo "[[[[ test case 4: - create output file ]]]]"
echo "********************************************************************************"
echo "./report data.csv "Markus Bender" rpt.txt"
./report data.csv "Markus Bender" rpt.txt
echo "********************************************************************************"
echo
echo "[[[[ test case 5: - No collaborators found ]]]]"
echo "********************************************************************************"
echo "./report data.csv "Markus Bender" rpt.txt"
./report data.csv "Markus Bender" rpt.txt
echo "********************************************************************************"
echo
echo "[[[[ test case 6: - Collaborators found ]]]]"
echo "********************************************************************************"
echo "./report data.csv "Adaline Murphy" rpt.txt"
./report data.csv "Adaline Murphy" rpt.txt
cat rpt.txt
echo "********************************************************************************"
echo




