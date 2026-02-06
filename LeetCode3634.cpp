//排序+双指针 
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxKeep = 1; // 至少保留一个
        int right = 0;

        for (int left = 0; left < n; ++left) {
            // 扩展 right 到最远：nums[right] <= nums[left] * k
            while (right < n && (long long)nums[right] <= (long long)nums[left] * k) {
                ++right;
            }
            // [left, right - 1] 是合法区间
            maxKeep = max(maxKeep, right - left);
        }

        return n - maxKeep;
    }
};




/*暴力O(n^2)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i,j;
        
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-1;++i){
        	for(j=0;j<=i;++j){
                int min = nums[j];
                int max = nums[nums.size()-1-(i-j)];
                //min*k>=max
        		if(min>max/k||(min==max/k&&max%k==0)){
        			return i;
				}
			}
		}
        return nums.size()-1;
    }
};
*/
