class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long ans=0;
        int temp=1;
        int tot=N;
        while(temp<=N){
                ans += 1LL*temp*temp;
                temp ++;
        }
        return ans;
    }
}