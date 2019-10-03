// File: auxiliary.h
// Helper Functions

#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline vector<string> Tokenize(const string& str, const string& delimiters = " \t") {
	vector<string> tokens;
	// Skip beginning delimiter
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first non-delimiter
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos) {
		// Found a token, add to vector
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
	
	return tokens;
}

inline void trim(string& str) {
	string::size_type beginPos = str.find_first_not_of(" \t");
	if (beginPos == string::npos) {
		str = string("");
	} else {
		string::size_type endPos = str.find_last_not_of(" \t");
		string::size_type length = endPos - beginPos + 1;
		str = str.substr(beginPos, length);
	}
}

inline string merge(const vector<string>& str) {
	// string must not be empty
	// returns merged vector of string
	string merged;
	vector<string>::iterator it = (const_cast<vector<string>&>(str)).begin();
	if (it < str.end()) {
	merged = *it; it++; // pointed, then move forward
		while (it < str.end()) {
			merged += (string(" ") + *it);
			it++;
		}
	}
	return merged;
}

#endif

