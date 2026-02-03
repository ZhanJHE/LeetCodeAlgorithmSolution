class Solution {
public:
    bool isTrionic(vector<int>& nums) {
    	// 0<p<q<n-1
    	int i = 0;
    	
        while(i<nums.size()-1&&nums[i]<nums[i+1]){
        	++i;
		}
		int p = i;// now is i == p
		if(i==0) return false;
		
		while(i<nums.size()-1&&nums[i]>nums[i+1]){
        	++i;
		}
		int q = i;//now is i == q
		if(p==q) return false; 
		
		while(i<nums.size()-1&&nums[i]>nums[i+1]){
        	++i;
		}
		if(q==i) return false;
		if(i==nums.size()-1){
			return true;
		}
		else{
			return false;
		}
    }
};
