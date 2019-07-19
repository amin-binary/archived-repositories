#ifdef no_compile_tc
// FoxAndFencingEasy.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,from,to) for(int i = (from),end##i = (to); i < end##i; ++i)

class FoxAndFencingEasy {
public:
	string WhoCanWin(int mov1, int mov2, int d)  {
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 1; string Arg3 = "Ciel"; verify_case(0, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100000000; string Arg3 = "Draw"; verify_case(1, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 150; int Arg2 = 100000000; string Arg3 = "Draw"; verify_case(2, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 250; int Arg2 = 100000000; string Arg3 = "Liss"; verify_case(3, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }

	// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	FoxAndFencingEasy ___test;
	___test.run_test(-1);
}

/* PROBLEM STATEMENT
Fox Ciel is playing a board game with her friend Squirrel Liss.
The game is played on an infinite strip of paper.
The strip of paper is divided into consecutive cells.
Each cell has an integer coordinate.
Formally, for each integer i, the left neighbor of cell i is cell (i-1) and the right neighbor of cell i is cell (i+1).



Each of the players has a single token called the fencer.
At the beginning of the game, Ciel's fencer is in cell 0 and Liss's fencer is in cell d.
Each of the fencers has a limit: its maximum move length.
For Ciel's fencer the maximum move length is mov1 and for Liss's fencer it is mov2.



The players take alternating turns.
Ciel goes first.
In each turn the current player moves her fencer.
The distance between the original cell and the destination cell must be at most equal to the fencer's maximum move length.
(It is also allowed to leave the fencer in the same cell.)
If the current player moves her fencer into the cell with the other fencer, the current player's fencer scores a hit and wins the game.



You are given the ints mov1, mov2, and d.
Return "Ciel" (quotes for clarity) if Fox Ciel has a winning strategy, "Liss" if Squirrel Liss has a winning strategy, and "Draw" otherwise.

DEFINITION
Class:FoxAndFencingEasy
Method:WhoCanWin
Parameters:int, int, int
Returns:string
Method signature:string WhoCanWin(int mov1, int mov2, int d)


CONSTRAINTS
-mov1 will be between 1 and 100,000,000, inclusive.
-mov2 will be between 1 and 100,000,000, inclusive.
-d will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
1
58
1

Returns: "Ciel"

Ciel can win in her first turn by moving her fencer one cell to the right.


1)
100
100
100000000

Returns: "Draw"

Liss can avoid getting hit forever by repeating Ciel's moves. For example, whenever Ciel moves her fencer 47 cells to the right, Liss also moves her fencer 47 cells to the right. Ciel has a similar strategy: in her first turn she can move her fencer arbitrarily and in each of the following turns she will repeat Liss's previous move. Therefore the game ends in a draw.

2)
100
150
100000000

Returns: "Draw"



3)
100
250
100000000

Returns: "Liss"


*/
// END CUT HERE
#endif