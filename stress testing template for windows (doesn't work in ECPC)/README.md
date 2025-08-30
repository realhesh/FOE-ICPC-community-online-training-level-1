WARNING 1: this stress testing template works for windows and will not work for the computers in the ECPC since they run on linux
WARNING 2: resort to stress testing as a last resort, you should try working towards improving your debugging skills first

instructions : 

1.put the brute,main,stress files in the same folder

2.put the code for which you don't know the failing test case in main.cpp 

3.put the code for which you always know outputs the correct output 

4.tweak the generate() function in stress.cpp, make a random variable using rnd(left limit,right limit), make sure the values for the variable are between the allowed range in the problem

5.make sure that the values are small enough so you could trace them easily.

6.if your code is wrong, the stress tester code will output the case that makes your code fail, and will tell you the correct output from the brute code and wrong output from your code

7.if the stress tester runs for way too long, try changing the variables allowed sizes


