#include "bits/stdc++.h"
using namespace std;
#define int long long

random_device rd;
mt19937_64 mt(rd());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(mt); }

void generate() {
    ofstream cout("test.txt");
    /*
     generate inputs here.
    generate a variable x by typing  x = rnd(left limit, right limit), take care to not make a variable
    equal to a value it isn't allowed to be, and don't make it very large so you can trace easily
     */

}
int32_t main() {
    system("g++ -O2 -o main.exe main.cpp");
    system("g++ -O2 -o brute.exe brute.cpp");

    for (int tc = 1; tc <= 1e6; ++tc) { //this generates 1e6 test cases
        cerr << "Case " << tc << '\n';
        generate();

        system("main.exe <test.txt >wa.txt");
        if (system("brute.exe <test.txt >ac.txt")) break;

        ifstream ac("ac.txt"), wa("wa.txt");
        string a, w;
        getline(ac, a, (char)EOF);
        getline(wa, w, (char)EOF);

        if (a != w) {
            cerr << "\n=== DIFFERENCE FOUND ===\n"; //if a difference is found, output the test case
            ifstream test("test.txt");
            for (string line; getline(test, line);) cerr << line << '\n';
            cerr << "Expected (from brute): " << a << "\nGot(from main): " << w << endl;
            //the output from brute is the correct one , and the one from main is the wrong one
            break;
        }
    }
    return 0;
}
