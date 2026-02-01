class Solution {
public:
    string intToRoman(int num) {
        string result;
        int thousands,hundreds,tens,units
        //extract digits
        units = num%10;
        tens = (num/10)%10;
        hundreds = (nums/100)%10;
        thousands = (nums/100);
        
        //千位
		if(thousands!=0){
			for(int i = 1;i<=thousands;++i){
				result = result + "M";
			}
		}
		//百位
		if(hundreds!=0){
			//4
			if(hundreds == 4){
				result = result + "CD"
			}
			//9
			else if(hundreds == 9){
				result = result + "CM"
			}
			//else
			else{
				if(hundreds>=5){
					result += "D";
					hundreds -= 5;
				}
				for(int i = 1;i<=hundreds;++i){
					result += "C";
				}
			}
			
		}
		//十位
		if(tens!=0){
			//4
			if(tens == 4){
				result = result + "XL";
			}
			//9
			else if(tens == 9){
				result = result + "XC"
			}
			//else
			else{
				if(tens >= 5){
					tens -= 5;
					result += "L";
				}
				for(int i = 1;i<=tens;++i){
					result += "X";
				}
			}
			
		}
		//个位
		if(units!=0){
			if(units == 4){
				result += "IV";
			}
			//9
			else if(units == 9){
				result += "IX";
			}
			//else
			else{
				if(units >= 5){
					units -=5;
					result += "V";
					
				}
				for(int i = 1;i<=units;++i){
					result += "I";
				}
			}
			
		}
		return result; 
    }
};
