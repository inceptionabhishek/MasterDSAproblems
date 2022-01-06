// Brute Force ;-

class Solution{   
public:
    bool check(string s,string pat){
        for(int i=0;i<pat.size();i++){
            if(pat[i]=='I'){
                if(s[i]>s[i+1]){
                    return false;
                }
            }else{
                if(s[i]<s[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
    string printMinNumberForPattern(string S){
        string s="123456789";
        do{
            if(check(s,S)){
                return s.substr(0,S.length()+1);
            }
        }while(next_permutation(s.begin(),s.end()));
        
    }
};

// Optimized Approach


