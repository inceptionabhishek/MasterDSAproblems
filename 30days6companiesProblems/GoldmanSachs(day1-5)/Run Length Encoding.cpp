


/*You are required to complete this function */

string encode(string src)
{     
  vector <pair<char,int>> v;
  for(int i=0;i<src.length();){
      int j=i;
      char curr=src[i];
      while(curr==src[j] && j<src.length()){
          j++;
      }
      v.push_back(make_pair(curr,j-i));
      i=j;
      
     
  }
  string ans ="";
      for(auto j:v){
          ans += j.first;
          ans += (j.second+'0');
      }
      return ans;
}     
 
