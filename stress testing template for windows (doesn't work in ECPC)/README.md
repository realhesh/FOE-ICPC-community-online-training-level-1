WARNING : this stress testing template works for windows and will not work for the computers in the ECPC since they run on linux
instructions : 
put the brute,main,stress files in the same folder
put the code for which you don't know the failing test case in main.cpp 
put the code for which you always know outputs the correct output 
tweak the generate() function in stress.cpp, make a random variable using rnd(left limit,right limit), make sure the values for the variable are between the allowed range in the problem
make sure that the values are small enough so you could trace them easily.
if your code is wrong, the stress tester code will output the case that makes your code fail, and will tell you the correct output from the brute code and wrong output from your code
if the stress tester runs for way too long, try changing the variables allowed sizes
