#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

using namespace std;
const int Section=4 ,validLenInput=8;
const char OneDig='1', FourDig='4';
enum parts
{
    HAT, NOSE, LEFT_EYE, RIGHT_EYE, LEFT_ARM, RIGHT_ARM, TORSO, BASE 
};

const array<std::string,Section> hats={"_===_"," ___\n .....","  _\n  /_\\"," ___\n (_*_)"};
const array<std::string,Section> noses={",", ".", "_"," "};
const array<std::string,Section> eyes={".", "o", "O","-"};
const array<std::string,Section> torsos={" : ", "] [", "> <","   "};
const array<std::string,Section> bases={" : ", "\" \"", "___","   "};
const array<std::string,Section> leftArmTop={" ","\\"," "," "};
const array<std::string,Section> leftArm={"<"," ","/"," "};
const array<std::string,Section> rightArmTop={" ","/"," "," "};
const array<std::string,Section> rightArm={">"," ","\\"," "};



//   need to check input:
//   A-8 number
//   B-each number is 1-4
//   C-no negtiv number

 void isValid(int input){
     std::string inputStr=std::to_string(input);
     //check A
     int inputLen=inputStr.length();
     if(inputLen!=validLenInput){
        throw invalid_argument("Invalid input . The length must be 8");}
     //check B & C
     for(int i=0; i<inputLen;i++){
         if(inputStr[i]<OneDig ||inputStr[i]>FourDig){
             throw invalid_argument("Invalid input. The characters must be between 1 and 4.");
         }
     }
 }
 
string buildSnowMan(array<int,validLenInput> arr){
  
    string hat=" "+hats.at(arr[HAT]);
    string face=leftArmTop.at(arr[LEFT_ARM])+"("+eyes.at(arr[LEFT_EYE]) + noses.at(arr[NOSE])+eyes.at(arr[RIGHT_EYE])+")" + rightArmTop.at(arr[RIGHT_ARM]);
    string torso=leftArm.at(arr[LEFT_ARM])+"("+torsos.at(arr[TORSO])+")"+ rightArm.at(arr[RIGHT_ARM]);
    string base=" ("+bases.at(arr[BASE])+")";
    return ""+hat+"\n"+face+"\n"+torso+"\n"+base+"\n";


}

namespace ariel {

 string snowman(int input){     
      isValid(input);
      array<int , validLenInput> arr={};
      const int baseTen=10;

      for(int i=validLenInput-1; i>=0; i--){
          arr.at(i)=(input%baseTen) -1;
          input/=baseTen;
      }
      
      return buildSnowMan(arr);
 }
 }
 

  