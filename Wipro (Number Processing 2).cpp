/*
Find Password (unstable 10)+stable:

Detective Buckshee Junior has been approached by the shantiniketan kids society for help in finding the password to the games complex. 
After hearing the scenario, detective Buckshee Junior realises that he will need a programmer's support. He contacts you and requests 
your help Please help the detective by writing a function to generate the password

The scenano is as below -

Five numbers are available with the kids. These numbers are either stable or unstable. A number is stable if each of its digit occur 
the same number of times, Le the frequency of each digit in the number is the same For eg 2277, 4004, 11, 23, 583835, 1010 are examples
of stabile numbers Similarly, A number is unstable if the frequency of each digit in the number is NOT the same For e g. 221, 4314, 101,
233, 58135, 101 are examples of unstable numbers.

The password can be found as below Le password = (Number of Unstable numbers 10) + Number of stable numbers

Assuming that the five numbers are passed to a function as inputt, input2, inputa inputs and inputs, complete the function to find and 
return the password.

For Example
It input1= 12, input2= 1313, mput3-122, inpot4-678, and input5858, we see that there are THREE stable numbers te 12, 1313 and 678 and
TWO unstable numbers are 122 and 698.
So, the password should be (Number of Unstable numbers 10)+ Number of stable numbers = (2 * 10) +3=23
*/


int func(int input1,int input2,int input3,int input4,int input5)
{
        vector<int>vec(5,0);
        vec[0]=input1;
        vec[1]=input2;
        vec[2]=input3;
        vec[3]=input4;
        vec[4]=input5;
        map<int,int>m;
        int unstable=0,stable=0;
        for(auto e:vec)                                      //looping over vector
        {
                int trigger=0,count=INT_MIN;
                while(e)                                     //counting the occurence of the digits
                {
                        int flag = e%10;
                        m[flag]++;
                        e=e/10;
                }
                for(auto f:m)                                //finding the common occurence
                {
                   if(count==INT_MIN)
                        {
                                count=f.second;
                                continue;
                        }
                   if(count!=INT_MIN && count!=f.second)
                   {
                           unstable++;                          //unstable++
                           trigger++;
                           break;

                   }
                }
                m.clear();
                if(trigger==0)
                   {
                           stable++;                            //stable++
                           continue;
                   }     
        }
        int key=(unstable*10)+stable;                           //calculating key
        return key;

}

