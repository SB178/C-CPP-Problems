/*
You are provided with 3 numbers input1, input2 and input3. Each of these are four digit numbers within the range >=1000 and <-9999

1000 < input1 <= 9999 
1000 < input2 <= 9999
1000 < input3 <= 9999

You are expected to find the Key using the below formula

Key=(Thousands digit of input1 x Hundreds digit of input2)-(Largest digit of input3)
For e.g. if input1 = 3521, input2 = 2452 input3 = 1352, then Key = (3x4)-5 = 7

Assuming that the 3 numbers are passed to the given function, Complete the function find and return the Key.
*/


int func(int input1,int input2,int input3)
{
    input1 = input1/1000;                                       //1st part
                                               
    input2/=100;                                                //2nd part
    input2%=10;

    int max_count = INT_MIN;                                    //3rd part
    while(input3)
    {
        int flag = input3%10;
        max_count = std::max(flag,max_count);
        input3/=10;
    }
    int key=(input1*input2)-max_count;                           //calculating input2ey
    return key;

}


