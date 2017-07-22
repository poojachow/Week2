//
//  Substring Concatenation.cpp
//  Week2Assignment
//
//  Created by Pooja Chowdhary on 7/21/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string A, const vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if ((A.length() == 0) || (B.size() == 0)) {
        return {};
    }
    unordered_multimap<string, int> C;
    unordered_multimap<string, int>::const_iterator it;
    
    vector<int> answer = {};
    string word;
    int originalSize = 0;
    int len = 0, start = -1, recheck = -1;
    len = B[0].length();
    
    for (int i = 0; i<B.size(); i++) {
        C.insert(pair<string, int>(B[i], i));
    }
    originalSize = C.size();
    for (int i = 0; i < A.length(); i++) {
        if(i+len-1 >= A.length()) {
            break;
        }
        word = A.substr(i, len);
        it = C.find(word);
        if(it == C.end()) {
            
            if(C.size() != originalSize) {
                C.clear();
                start = -1;
                for (int i = 0; i<B.size(); i++) {
                    C.insert(pair<string, int>(B[i], i));
                }
            }
            if (recheck > -1) {
                i = recheck;
                recheck = -1;
            }
        }
        else {
            if(start == -1) {
                start = i;
            }
            C.erase(it);
            if(C.size() == 0) {
                answer.push_back(start);
                if(recheck > -1) {
                    i = recheck;
                    continue;
                }
            }
            if(recheck == -1) {
                recheck = i;
            }
            
            
            i=i+len-1;
        }
    }
    return answer;
}

