class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> sec_hash;
        map<int,int> guess_hash;
        int x = 0, y = 0;
        for(int i=0;i<secret.length();i++) {
            if(secret[i]==guess[i]) {
                x++;
            } else {
                sec_hash[secret[i]-'0']++;
                guess_hash[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            y += min(sec_hash[i], guess_hash[i]);
        }
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};