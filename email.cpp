#include <iostream>
#include<list>
#include<fstream>
#include<cstdlib>
#include<vector>
#include <time.h>
#include <ctime>
#include<cctype>
#include<cstring>
#include<cstdio>
#include <fstream>
using namespace std;


/* A-Z
   a-z
   1-0
*/
static const char pool[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789";
/* A-Z
   a-z
*/
static const char pool2[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
;

int poolSize = sizeof(pool)-1;
int poolSize2 = sizeof(pool2)-1;

//randomize the word
char getRandomword()
{
 return pool2[rand() %poolSize2];
}
//randomize the word
char getRandomChar()
{
 return pool[rand() %poolSize];
}

int main(int argc,char *argv[])
{
    while(true)
    {
        string email;
        int numberOfemail;
        int s1=5;
        int s2=4;
        int s3=6;
        srand(time(0)); //random seed
        string word1;
        string word2;
        string word3;
        string word4;
        cout<<"how many email";
        cin>>numberOfemail;

        for(int j=0; j<numberOfemail;j++)
        {
            for (int i =0;i < s1;i++)
                {
                word1 += getRandomChar();
                }
            email=word1+".";
            //to prevent overlap
            word1="";

             for (int i =0;i < s2;i++)
                {
                word2 += getRandomChar();
                }


            email=email+word2+"@";

            //to prevent overlap
            word2="";

            for (int i =0;i < s3;i++)
                {
                word3 += getRandomword();
                }
            email=email+word3+".";
            //to prevent overlap
            word3="";

            string arr[3] = {"net", "org", "my"};
            string word4 = arr[(rand() % 3)];


            email=email+word4;

            cout<<email<<endl;
            //to prevent overlap
            word4="";
        }
    }

}
