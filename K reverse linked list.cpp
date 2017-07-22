//
//  K reverse linked list.cpp
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

ListNode* reverseList(ListNode* A, int B) {
    
    //read k nodes/till null, push in vector
    //go back to 1st node in the set of k
    //replace val with reverse val, clear vector
    ListNode *current = A;
    vector<int> reverse;
    int start = 0, end = 0, temp = 0;
    
    while(current!=nullptr) {
        reverse.push_back(current->val);
        current = current->next;
    }
    current = A;
    
    while(current!=nullptr) {
        end = (start+B-1) > reverse.size() ? reverse.size()-1 : (start+B-1);
        temp = end;
        while(start <= temp) {
            current->val = reverse[temp];
            current = current->next;
            temp--;
        }
        start = end+1;
    }
    
    return A;
    
}
