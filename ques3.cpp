// Assuming expiry to be the number of calls made to add and get functions
#include<bits/stdc++.h>
#define pii pair<int , int>
using namespace std;

class Cache{
public:
    unordered_map<int , pii> mp; // key + (value & exprity time) 
    unordered_map<int , int> expiry; // expiry time frequencies
    int cnt = 0;


    void removeKey(){
        if(expiry.find(cnt) != expiry.end()){
            vector<int> eraseKeys;
            for(auto p : mp){
                int key = p.first;
                int expiryTime = p.second.second;
                if(expiryTime == cnt)
                eraseKeys.push_back(key);

            }


            for(int i = 0 ; i<eraseKeys.size() ; i++){
                mp.erase(eraseKeys[i]);
            }
        }
    }
    void set(int key , int value , int expiryTime){
        if(mp.find(key) != mp.end()){
            int prevExpiry = mp[key].second;
            expiry[prevExpiry]--;
            if(expiry[prevExpiry] == 0)
            expiry.erase(prevExpiry);
            mp[key] = {value , expiryTime};
            expiry[expiryTime]++;
        }
        else{
            mp[key] = {value , expiryTime};
            expiry[expiryTime]++;
        }

        cnt++;
        removeKey();
    }

    int get(int key) {
        cnt++;
        removeKey();
        if(mp.find(key) != mp.end()){
            return mp[key].first;
        }
        else
        return -1;

    }

};

int main(){
    Cache cache;
    while (true) {
        int ch;
        cout<<"Enter 1 to set, 2 to get, -1 to exit: ";
        cin>>ch;
        switch (ch) {
            case 1: {
                int key, value, expiryTime;
                cout << "Enter key, value, and expiry time: ";
                cin >> key >> value >> expiryTime;
                cache.set(key, value, expiryTime);
                break;
            }
            case 2: {
                int key;
                cout << "Enter key: ";
                cin >> key;
                int result = cache.get(key);
                if (result != -1) {
                    cout << "Value: " << result << endl;
                } else {
                    cout << "Key not found" << endl;
                }
                break;
            }
            case -1:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}