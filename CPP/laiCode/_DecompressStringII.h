#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <bitset>
#include <sstream>
#include <climits>
#include <cmath>
#include <map>
#include <utility>
#include <stdint.h>
#include <algorithm>
#include <stack>
#include <set>
#include <string.h>

using namespace std;

class Solution {
private:
	int stringToInt(int charsToInt[], string input) {
		int ans = 0;
		reverse(input.begin(), input.end());
		for (int i = 0; i <input.length(); ++i) {
			ans += charsToInt[input[i] - '0'] * pow(10,i);
		}

		return ans;
	}
	string stringMultiple(string base, int num) {
		string ans = "";
		
		while (num > 0) {
			ans += base;
			num--;
		}
		return ans;
	}
	bool isInteger(char c) {
		int i = c - '0';
		return 9 >= i && i >= 0;
	}
	string getNums(string::iterator &begin, string::iterator stop) {
		string::iterator end = begin;
		while (end != stop&&isInteger(*end)) {
			end++;
		}
		string s = string(begin, end);
		begin = end;
		return s;
	}
public:
	string decompress(string input) {
		// write your solution here
		if (input.length() <= 1) {
			return input;
		}
		int charsToInt[] = {0,1,2,3,4,5,6,7,8,9};
		string::iterator num = input.begin();
		string::iterator let = input.begin();
		string ans = "";
		do {
			if (isInteger(*num)) {
				string tmp = string(let, num);
				ans += stringMultiple(tmp, stringToInt(charsToInt, getNums(num, input.end())));
				let = num;
			}
			else {
				num++;
			}
		} while (num < input.end());

		return ans;
	}
};

