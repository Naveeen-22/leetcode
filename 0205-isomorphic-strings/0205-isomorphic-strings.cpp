class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map(128, -1);
        vector<bool> status(128, false);
        for(int i=0 ; i<s.length(); i++){
            if(map[s[i]]==-1 && status[t[i]]==false){
                map[s[i]] = t[i];
                status[t[i]] =true;
            }
        }
        for(int i=0; i<s.length() ; i++){
            if(map[s[i]]!= t[i])
            return false;
        }
        return true;

        
    }
};