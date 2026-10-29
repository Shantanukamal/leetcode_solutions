class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int prefix=0;
        int ans=0;
        map<int,int>m;
        m[0]=1;
        
        for(int i=0;i<nums.size();i++){

            prefix+=nums[i];
            
            if(m.count((prefix%k+k)%k)){

                ans+=m[(prefix%k+k)%k];
            }

            m[((prefix%k+k)%k)]++ ;

        }

        return ans;

    }
};