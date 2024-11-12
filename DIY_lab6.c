#include <stdio.h>
#include <string.h>

int romanToInt(char R[]);
void intToRoman(int num, char result[]);

int main(){
    char R1[10], R2[10], result[10]; // for the given inputs
    int num1,num2,sum; // for calculating the sum and then putting into intToRoman

    printf("Enter the first Roman numeral: ");
    scanf("%s", R1);

    printf("Enter the second Roman numeral: ");
    scanf("%s", R2);

    num1 = romanToInt(R1);
    num2 = romanToInt(R2);

    sum = num1 + num2;

    intToRoman(sum, result);

    printf("Result = %s\n", result);
}

int romanToInt(char R[]){
    int result = 0;

    for(int i =0; R[i] != '\0';i++){ // as long as the string is not empty
        if(R[i] == 'I'){ // IV is 4 and IX is 9 so you gotta check those cases
            if(R[i+1] == 'V' || R[i+1] == 'X'){
                result -=1; //subtract because, a smaller number precedes a larger number
            }else{
                result +=1; // else its like I, II, or III and stuff
            }
        }else if(R[i] == 'V'){ // V is 5 
            result += 5;
        }else if(R[i] == 'X'){ // X is 10
            result += 10;
        }
    }
    return result;
}
void intToRoman(int num, char result[]){
    //str copy puts a value in the value given after the comma into the destination which is before the comma
    strcpy(result, "");

    while(num >= 10){
        //strcat merges the destination with the given, in this example X will merge with result
        strcat(result, "X");
        num -= 10;
    }
    // go by order of highest number to lowest when appenging the new roman numerals
    if(num == 9){
        strcat(result, "IX");
        num -= 9;
    }
    else if(num >= 5){
        strcat(result, "V");
        num -= 5;
    }
    else if(num == 4){
        strcat(result, "IV");
        num -=  4;
    }
    //this is a while loop because if it is a one at the end it will keep decreasing untill num is 0
    while( num >= 1){
        strcat(result, "I");
        num -= 1;
    }
    //basically just appended different characters depending on which value they need to replace
}