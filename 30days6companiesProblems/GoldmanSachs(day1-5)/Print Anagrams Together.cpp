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

// Optimized Solution
vector <vector <string>> ans{
    map<map<char, int>, vector<string>> my_map;
     
    for(string str : my_list)
    {
        map<char, int> temp_map;
        vector<string> temp_my_list;
        for(int i = 0; i < str.length(); ++i)
        {
            ++temp_map[str[i]];
        }
        auto it = my_map.find(temp_map);
        if (it != my_map.end())
        {
            it->second.push_back(str);
        }
        else
        {
            temp_my_list.push_back(str);
            my_map.insert({ temp_map, temp_my_list });
        }
    }
    vector<vector<string>> result;
    for(auto it = my_map.begin();
             it != my_map.end(); ++it)
    {
        result.push_back(it->second);
    }
    return result;
}