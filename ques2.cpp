#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

// Time Complexity for add interval: O(nlogn)

class IntervalMerger {
public:
    vector<pii> intervals;
    void addInterval(int start, int end) {
        vector<pii> newIntervals;
        
        for (auto interval : intervals) {
            int s = interval.first, e = interval.second;
            if (end < s || start > e) {
                newIntervals.push_back({s, e});
            } else {
                start = min(start, s);
                end = max(end, e);
            }
        }
        
        newIntervals.push_back({start, end});
        sort(newIntervals.begin(), newIntervals.end());
        intervals = newIntervals;
    }

    vector<pii> getIntervals() {
        return intervals;
    }
};

int main() {
    IntervalMerger im;
    cout<<"Enter 1 to add interval"<<endl;
    cout<<"Enter 2 to get interval"<<endl;
    cout<<"Enter -1 to terminate"<<endl;
    while(true){
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            int s , e;
            cin>>s>>e;
            im.addInterval(s , e);
            break;
            case 2:
            for (auto interval : im.getIntervals()) {
                cout << "[" << interval.first << ", " << interval.second << "]\n";
            }
            break;
            default:
            return 0;
        }
    }
}