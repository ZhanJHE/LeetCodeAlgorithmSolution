class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string res;
    	bool flag;
        for(int i = 0;i<strs[0].size();++i){//第 i 个 字符 
        	flag = true;
        	for(int j = 1 ; j<strs.size();++j){//迭代每个字符串 
        		if(strs[0][i]!=strs[j][i]){
        			flag = false;
        			break;
				}
			}
			if(flag){
				res += strs[0][i];
			}
			else{
				break;
			}
		}
    }
};
