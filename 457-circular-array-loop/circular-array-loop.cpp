class Solution {
public:
    
    int n; 
    int nextIndex(int i,vector<int>&nums){

        int next=((i+nums[i])%n+n)%n;
        return next;
        
    }
    bool circularArrayLoop(vector<int>& nums) {
        
        n=nums.size(); 
        for(int i=0;i<n;i++){

            int slow=i,fast=i;
            bool forward=nums[i]>0;
            
            while(true){

                //next index
                int s=nextIndex(slow,nums); 
                if((nums[s]>0) !=forward || s==slow) break;

                int f=nextIndex(fast,nums);
                if((nums[f]>0) !=forward || f==fast) break;

                int f2=nextIndex(f,nums);
                if((nums[f2]>0) !=forward || f==f2) break;

                slow=s,fast=f2;
                if(slow==fast) return 1;

            }

        }

        return 0;
    }
};