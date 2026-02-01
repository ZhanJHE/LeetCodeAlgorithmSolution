#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
		string s = "MMIII";
        int result;
        int i = 0;
        //thousands digit
        while(s[i]=='M'){
        	result += 1000;
        	++i;
		}
		//hundreds
		if(i<s.size()-1&&s[i]=='C'&&s[i+1]=='M'){// 900 CM
			result += 900;
			i += 2;
		}
		else if(i<s.size()-1&&s[i]=='C'&&s[i+1]=='D'){//400 CD
			result += 400;
			i += 2;
		}
		else{
			if(i<s.size()&&s[i]=='D'){// above 500
				result += 500;
				++i;
			} 
			while(i<s.size()&&s[i]=='C'){
				result += 100;
				++i;
			}	
		}
		//tens
		if(i<s.size()-1&&s[i]=='X'&&s[i+1]=='C'){// 90 XC
			result += 90;
			i +=2;
		}
		else if(i<s.size()-1&&s[i]=='X'&&s[i+1]=='L'){// 40 XL
			result += 40;
			i+=2;
		}
		else{
			if(i<s.size()&&s[i]=='L'){//above 50
				result += 50;
				++i;
			}
			while(i<s.size()&&s[i]=='X'){
				result += 10;
				++i;
			}	
		}
		//units
		if(i<s.size()-1&&s[i]=='I'&&s[i+1]=='X'){// 9 IX
			result += 9;
			i +=2;
		}
		else if(i<s.size()-1&&s[i]=='I'&&s[i+1]=='V'){// 4 IV
			result += 4;
			i+=2;
		}
		else{
			if(i<s.size()&&s[i]=='V'){//above 5
				result += 5;
				++i;
			}
			while(i<s.size()&&s[i]=='I'){
				result += 1;
				++i;
			}	
		}
		return result;
}
