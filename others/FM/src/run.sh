exe=fm

for i in {1..5}
do
  echo ""
  echo "Testcase "$i
  time ./$exe ../testcases/p2-$i.nets ../testcases/p2-$i.cells $exe$i.out 
  echo ">>> Verify"
  ../verifier/verifier ../testcases/p2-$i.nets ../testcases/p2-$i.cells $exe$i.out
done
