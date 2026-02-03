class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int d = 0;
        if(n%2==1){
        	res[0] = 0;
        	n -= 1;
        	++d;
		}
        for(int i = 1;i<=n/2;++i){
        	res[d] = i;
        	++d;
        	res[d] = (-1)*i;
        	++d;
		}
		return res;
    }
};
