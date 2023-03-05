#!/bin/bash

exe=hw2

for i in {1..3}
do
  echo ""
  echo "Testcase n"$i"00"
  time ./build/$exe ./testcases/n"$i"00.hardblocks ./testcases/n"$i"00.nets ./testcases/n"$i"00.pl ./output/0.1/n"$i"00.floorplan 0.1
  echo ">>> Verify"
  ./verifier/verifier ./testcases/n"$i"00.hardblocks ./testcases/n"$i"00.nets ./testcases/n"$i"00.pl ./output/0.1/n"$i"00.floorplan 0.1

  time ./build/$exe ./testcases/n"$i"00.hardblocks ./testcases/n"$i"00.nets ./testcases/n"$i"00.pl ./output/0.15/n"$i"00.floorplan 0.15
  echo ">>> Verify"
  ./verifier/verifier ./testcases/n"$i"00.hardblocks ./testcases/n"$i"00.nets ./testcases/n"$i"00.pl ./output/0.15/n"$i"00.floorplan 0.15
done