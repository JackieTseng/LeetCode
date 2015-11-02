/*********************************************************************************
 * Leetcode : Bulls and Cows -- https://leetcode.com/problems/bulls-and-cows/ 
 * Coded in Nov 2nd, 2015
 *
 * [Problem]
 * You are playing the following Bulls and Cows game with your friend: You write a
 * 4-digit secret number and ask your friend to guess it. Each time your friend
 * guesses a number, you give a hint. The hint tells your friend how many digits
 * are in the correct positions (called "bulls") and how many digits are in the
 * wrong positions (called "cows"). Your friend will use those hints to find out
 * the secret number.
 * 
 * For example:
 * 
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * Write a function to return a hint according to the secret number and friend's
 * guess, use A to indicate the bulls and B to indicate the cows. In the above
 * example, your function should return "1A3B".
 * 
 * Please note that both secret number and friend's guess may contain duplicate
 * digits, for example:
 * 
 * Secret number:  "1123"
 * Friend's guess: "0111"
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow,
 * and your function should return "1A1B".
 * You may assume that the secret number and your friend's guess only contain digits, 
 * and their lengths are always equal. 
 *********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution One
string getHint(string secret, string guess) {
	int l = secret.length();
	int A = 0, B = 0;
	int x[10] = {0};
	for (int i = 0; i < l; i++) {
		if (secret[i] == guess[i]) {
			A++;
		} else {
			x[secret[i] - '0']++;
		}
	}
	for (int i = 0; i < l; i++) {
		if (secret[i] != guess[i] && x[guess[i] - '0']) {
			B++;
			x[guess[i] - '0']--;
		}
	}
	return to_string(A) + "A" + to_string(B) + "B";
}

// Solution Two
string getHint(string secret, string guess) {
	int l = secret.length();
	int A = 0, B = 0;
	int x[10] = {0};
	for (int i = 0; i < l; i++) {
		if (secret[i] == guess[i]) {
			A++;
		} else {
			if (x[secret[i] - '0']++ < 0) {
				B++;
			}
			if (x[guess[i] - '0']-- > 0) {
				B++;
			}
		}
	}
	return to_string(A) + "A" + to_string(B) + "B";
}

// Solution Three
string getHint(string secret, string guess) {
	int l = secret.length();
	int A = 0, B = 0;
	int x[10] = {0};
	for (int i = 0; i < l; i++) {
		A += secret[i] == guess[i];
		B += (x[secret[i] - '0']++ < 0) + (x[guess[i] - '0']-- > 0);
	}
	return to_string(A) + "A" + to_string(B - A) + "B";
}

int main(int argc, const char *argv[]) {
	cout << getHint("1122", "2211") << endl;
	return 0;
}
