//
//  Sort List.cpp
//  Week2Assignment
//
//  Created by Pooja Chowdhary on 7/22/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* sortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> constSpace;
    ListNode *current = A;
    while (current != nullptr) {
        constSpace.push_back(current->val);
        current = current->next;
    }
    
    if(constSpace.size() <= 1) {
        return A;
    }
    
    sort(constSpace.begin(), constSpace.end());
    current = A;
    
    for(int i = 0; i < constSpace.size(); i++) {
        if(current == nullptr) {
            break;
        }
        current->val = constSpace[i];
        current = current->next;
    }
    return A;
}
