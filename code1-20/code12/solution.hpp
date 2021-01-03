#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string out="";
        for(int i=0;i<num/1000;i++)
            out.insert(out.end(),'M');
        num = num - num/1000*1000;
        switch(num/100){
            case 0:break;
            case 1:out+="C";break;
            case 2:out+="CC";break;
            case 3:out+="CCC";break;
            case 4:out+="CD";break;
            case 5:out+="D";break;
            case 6:out+="DC";break;
            case 7:out+="DCC";break;
            case 8:out+="DCCC";break;
            case 9:out+="CM";break;
        }
        num = num - num/100*100;
        switch(num/10){
            case 0:break;
            case 1:out+="X";break;
            case 2:out+="XX";break;
            case 3:out+="XXX";break;
            case 4:out+="XL";break;
            case 5:out+="L";break;
            case 6:out+="LX";break;
            case 7:out+="LXX";break;
            case 8:out+="LXXX";break;
            case 9:out+="XC";break;
        }
        num = num - num/10*10;
        switch(num){
            case 0:break;
            case 1:out+="I";break;
            case 2:out+="II";break;
            case 3:out+="III";break;
            case 4:out+="IV";break;
            case 5:out+="V";break;
            case 6:out+="VI";break;
            case 7:out+="VII";break;
            case 8:out+="VIII";break;
            case 9:out+="IX";break;
        }
        return out;
    }
};