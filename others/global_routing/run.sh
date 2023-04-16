#!/bin/bash

exe=route

for i in {1..4}
do
  echo ""
  echo "Testcase ibm0"$i
  time ./bin/$exe ./testcase/ibm0"$i".modified.txt ./output/ibm0"$i".modified.out
  echo ">>> Verify"
  ./verifier/verify ./testcase/ibm0"$i".modified.txt ./output/ibm0"$i".modified.out
done