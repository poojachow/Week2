//
//  Anagrams.cpp
//  Week2Assignment
//
//  Created by Pooja Chowdhary on 7/21/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() <= 0) {
        return {};
    }
    
    vector<vector <int>> answer;
    map<string, int> arr;
    map<string, int>::const_iterator finder;
    
    string temp = "";
    
    for (int i = 0; i < A.size(); i++) {
        
        temp = A[i];
        sort(temp.begin(), temp.end());
        finder = arr.find(temp);
        if(finder == arr.end()) {
            arr[temp] = i;
            answer.push_back({(i+1)});
        }
        else {
            for (int j = 0; j < answer.size(); j++) {
                if ((answer[j][0] == (finder->second) + 1)) {
                    answer[j].push_back(i+1);
                    break;
                }
            }
            //  answer.push_back({((finder->second)+1),(i+1)});
        }
    }
    
    return answer;
    
}
