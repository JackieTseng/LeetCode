/*********************************************************************************
 * Leetcode : Isomorphic Strings -- https://leetcode.com/problems/isomorphic-strings/
 * Coded in Aug 27th, 2015
 *
 * [Problem]
 *  Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 *********************************************************************************/
#include <iostream>
#include <string>
#include <map>
using namespace std;

// Solution One
bool isIsomorphic(string s, string t) {
    int slen = s.length(), tlen = t.length();
    if (slen != tlen) {
        return false;
    }
    map<char, int> smap, tmap;
    string sstr, tstr;
    for (int i = 0, counter = 0; i < slen; i++) {
        if (smap.find(s[i]) == smap.end()) {
            sstr += (counter + '0');
            smap[s[i]] = counter++;
        } else {
            sstr += (smap[s[i]] + '0');
        }
    } 
    for (int i = 0, counter = 0; i < tlen; i++) {
        if (tmap.find(t[i]) == tmap.end()) {
            tstr += (counter + '0');
            tmap[t[i]] = counter++;
        } else {
            tstr += (tmap[t[i]] + '0');
        }
    }
    cout << sstr << endl << tstr << endl;
    return (sstr == tstr);
}

// Solution Two
bool isIsomorphic(string s, string t) {
    char smap[256] = {0}, tmap[256] = {0};
    int i = 0 , length = s.length();
    while (i < length) {
        if (smap[s[i]] == 0 && tmap[t[i]] == 0) {
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        } else {
            if (smap[s[i]] != t[i] || tmap[t[i]] != s[i]) {
                return false;
            }
        }
        ++i;
    }
    return true;
}

// Solution Three
bool isIsomorphic(string s, string t) {
    int smap[256] = {0}, tmap[256] = {0}, len = s.length();
    for (int i = 0; i < len; ++i) {
        if (smap[s[i]] != tmap[t[i]]) {
            return false;
        }
        smap[s[i]] = tmap[t[i]] = i + 1;
    }
    return true;
}

int main(int argc, const char *argv[]) {
    string s, t;
    while (cin >> s >> t) {
        cout << (isIsomorphic(s, t)? "Ture" : "False") << endl;
    } 
    return 0;
}
