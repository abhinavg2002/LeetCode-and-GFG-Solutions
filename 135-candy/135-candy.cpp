class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> v(n,1);
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]){
                v[i]=max(v[i], v[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1]){
                v[i]=max(v[i],v[i+1]+1);
            }
        }
        return accumulate(v.begin(), v.end(), 0ll);
    }
};