class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
  vector <vector <string>> ans;
  vector <pair<pair<string,string>,int>> v;
  for(int i=0;i<string_list.size();i++){
    string given=string_list[i];
    sort(given.begin(),given.end());
    v.push_back(make_pair(make_pair(given,string_list[i]),i));
  }
  sort(v.begin(),v.end());
  //deb(v);
  for(int i=0;i<v.size();){
    int j=i;
    string curr=v[i].first.first;
    vector <pair<int,string>> temp;
    while(curr==v[j].first.first && j<v.size()){
      temp.push_back(make_pair(v[j].second,v[j].first.second));
      j++;
    }
    i=j;
    sort(temp.begin(),temp.end());
    vector <string> final;
    for(auto j:temp){
      final.push_back(j.second);
    }
    ans.push_back(final);
  }

  return ans;
}
};