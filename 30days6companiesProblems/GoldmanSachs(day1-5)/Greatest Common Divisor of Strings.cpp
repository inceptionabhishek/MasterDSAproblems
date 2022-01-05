class Solution {
public:
    bool check(string small,string big){
        if(small==big){
            return true;
        }
        string temp=small;
        while(temp.size()!=big.size()){
            temp += small;
        }
        return big==temp;
    }
    string gcdOfStrings(string str1, string str2) {
        int size=0;
        int n=str1.size();
        int m=str2.size();
        string ans="";
        vector <pair<int,string>> v;
        for(int i=0;i<min(n,m);i++){
            if(str1[i]!=str2[i]){
                break;
            }else{
                ans += str1[i];
                v.push_back(make_pair(ans.size(),ans));
            }
        }
        sort(v.begin(),v.end());
       // deb(v);
        for(int i=v.size()-1;i>=0;i--){
          if(n%v[i].first ==0  && m%v[i].first==0 && v[i].first<=min(n,m) && check(v[i].second,str1) && check(v[i].second,str2)){
           // deb(mp(n,m));
           // deb(v[i].ff);
           // deb(mp(n%v[i].ff,m%v[i].ff));
            return v[i].second;
          }
        }
        return "";

}
};

// optimized
class Solution {
public:
    string gcdOfStrings(const string& s1, const string& s2)
    {
        return (s1 + s2 == s2 + s1)  
		    ? s1.substr(0, gcd(size(s1), size(s2)))
			: "";
    }
};