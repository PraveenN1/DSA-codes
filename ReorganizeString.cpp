#include<bits/stdc++.h>
using namespace std;


string reorganizeString(string s) {
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for (auto entry : charCount) {
        maxHeap.push({entry.second, entry.first});
    }

    string result = "";
    while (!maxHeap.empty()) {
        auto curr = maxHeap.top();
        maxHeap.pop();

        if (result.empty() || curr.second != result.back()) {
            result += curr.second;
            if (curr.first > 1) {
                maxHeap.push({curr.first - 1, curr.second});
            }
        } else {
            if (maxHeap.empty()) {
                return "";
            }
            auto next = maxHeap.top();
            maxHeap.pop();
            result += next.second;
            if (next.first > 1) {
                maxHeap.push({next.first - 1, next.second});
            }
            maxHeap.push(curr);
        }
    }

    return result;
}
int main( ){
    string s;
    cin>>s;
    cout<<reorganizeString(s);
    return 0;
}