class Solution {
public:
    int dp[505][505][2];
    int fun(int i, int j, vector<int>&a, vector<int>&b, int ct){
        int n=a.size(), m=b.size();
        if(i==a.size() or j==b.size()){
            if(ct==0)return INT_MIN;
            return 0;
        }
        if(dp[i][j][ct]!=-1)return dp[i][j][ct];
        int ans=INT_MIN;
        ans=max({ans,fun(i+1, j, a, b, ct),fun(i, j+1, a, b, ct)});
        ans=max(ans,fun(i+1, j+1, a, b, 1)+a[i]*b[j]);
        return dp[i][j][ct]=ans;
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        memset(dp, -1, sizeof(dp));
        return fun(0,0,a,b,0);
    }
};