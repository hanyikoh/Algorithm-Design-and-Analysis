#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

static const char pool[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789";
/* A-Z
   a-z
*/
static const char pool2[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
/* A-Z
   a-z
   1-0
*/
int poolSize = sizeof(pool) - 1;
int poolSize2 = sizeof(pool2) - 1;
//randomize the word
char getRandomword()
{
    return pool2[rand() % poolSize2];
}
//randomize the word
char getRandomChar()
{
    return pool[rand() % poolSize];
}
vector<string> emailVect;
//int main(int argc,char *argv[])

void generateEmail()
{

    ofstream myfile;
    myfile.open("email_100.txt");

    string email;
    int numberOfemail;
    int s1 = 5;
    int s2 = 4;
    int s3 = 6;
    srand(time(0)); //random seed

    string word1;
    string word2;
    string word3;
    string word4;
    vector<string> notfVect;

    //cout<<"how many email";
    //cin>>numberOfemail;

//----------------------------------------------------------------------------------------
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < s1; i++)
        {
            word1 += getRandomChar();
        }
        email = word1 + ".";
        //to prevent overlap
        word1 = "";

        for (int i = 0; i < s2; i++)
        {
            word2 += getRandomChar();
        }

        email = email + word2 + "@";

        //to prevent overlap
        word2 = "";

        for (int i = 0; i < s3; i++)
        {
            word3 += getRandomword();
        }
        email = email + word3 + ".";
        //to prevent overlap
        word3 = "";

        string arr[3] = {"net", "org", "my"};
        string word4 = arr[(rand() % 3)];

        email = email + word4;
        emailVect.push_back(email);
        myfile << email << endl;
        //to prevent overlap
        word4 = "";
    };
    myfile.close();
    myfile.open("Email Not Found_100.txt");
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < s1; i++)
        {
            word1 += getRandomChar();
        }
        email = word1 + ".";
        //to prevent overlap
        word1 = "";

        for (int i = 0; i < s2; i++)
        {
            word2 += getRandomChar();
        }

        email = email + word2 + "@";

        //to prevent overlap
        word2 = "";

        for (int i = 0; i < s3; i++)
        {
            word3 += getRandomword();
        }
        email = email + word3 + ".";
        //to prevent overlap
        word3 = "";

        string arr[3] = {"net", "org", "my"};
        string word4 = arr[(rand() % 3)];

        email = email + word4;
        for (int i = 0; i < emailVect.size(); i++)
        {
            if (email == emailVect[i])
                j--;
            continue;
        }
        notfVect.push_back(email);
        myfile << email << endl;
        //to prevent overlap
        word4 = "";
    };

    myfile.close();

    myfile.open("Email Found_100.txt");
    for (int i = 0; i < 10; i++)
    {
        myfile << emailVect[rand() % emailVect.size()] << endl;
    }
    myfile.close();


//----------------------------------------------------------------------------------------

    myfile.open("email_100000.txt");

    for (int j = 0; j < 100000; j++)
    {
        for (int i = 0; i < s1; i++)
        {
            word1 += getRandomChar();
        }
        email = word1 + ".";
        //to prevent overlap
        word1 = "";

        for (int i = 0; i < s2; i++)
        {
            word2 += getRandomChar();
        }

        email = email + word2 + "@";

        //to prevent overlap
        word2 = "";

        for (int i = 0; i < s3; i++)
        {
            word3 += getRandomword();
        }
        email = email + word3 + ".";
        //to prevent overlap
        word3 = "";

        string arr[3] = {"net", "org", "my"};
        string word4 = arr[(rand() % 3)];

        email = email + word4;
        emailVect.push_back(email);
        myfile << email << endl;
        //to prevent overlap
        word4 = "";
    };
    myfile.close();

    myfile.open("Email Not Found_100000.txt");
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < s1; i++)
        {
            word1 += getRandomChar();
        }
        email = word1 + ".";
        //to prevent overlap
        word1 = "";

        for (int i = 0; i < s2; i++)
        {
            word2 += getRandomChar();
        }

        email = email + word2 + "@";

        //to prevent overlap
        word2 = "";

        for (int i = 0; i < s3; i++)
        {
            word3 += getRandomword();
        }
        email = email + word3 + ".";
        //to prevent overlap
        word3 = "";

        string arr[3] = {"net", "org", "my"};
        string word4 = arr[(rand() % 3)];

        email = email + word4;
        for (int i = 0; i < emailVect.size(); i++)
        {
            if (email == emailVect[i])
                j--;
            continue;
        }
        notfVect.push_back(email);
        myfile << email << endl;
        //to prevent overlap
        word4 = "";
    };

    myfile.close();

    myfile.open("Email Found_100000.txt");
    for (int i = 0; i < 10; i++)
    {
        myfile << emailVect[rand() % emailVect.size()] << endl;
    }
    myfile.close();
    
//------------------------------------------------------------------------------------

    myfile.open("email_500000.txt");

    for (int j = 0; j < 500000; j++)
    {
        for (int i = 0; i < s1; i++)
        {
            word1 += getRandomChar();
        }
        email = word1 + ".";
        //to prevent overlap
        word1 = "";

        for (int i = 0; i < s2; i++)
        {
            word2 += getRandomChar();
        }

        email = email + word2 + "@";

        //to prevent overlap
        word2 = "";

        for (int i = 0; i < s3; i++)
        {
            word3 += getRandomword();
        }
        email = email + word3 + ".";
        //to prevent overlap
        word3 = "";

        string arr[3] = {"net", "org", "my"};
        string word4 = arr[(rand() % 3)];

        email = email + word4;
        emailVect.push_back(email);
        myfile << email << endl;
        //to prevent overlap
        word4 = "";
    };
    myfile.close();



    myfile.open("Email Not Found_500000.txt");
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < s1; i++)
        {
            word1 += getRandomChar();
        }
        email = word1 + ".";
        //to prevent overlap
        word1 = "";

        for (int i = 0; i < s2; i++)
        {
            word2 += getRandomChar();
        }

        email = email + word2 + "@";

        //to prevent overlap
        word2 = "";

        for (int i = 0; i < s3; i++)
        {
            word3 += getRandomword();
        }
        email = email + word3 + ".";
        //to prevent overlap
        word3 = "";

        string arr[3] = {"net", "org", "my"};
        string word4 = arr[(rand() % 3)];

        email = email + word4;
        for (int i = 0; i < emailVect.size(); i++)
        {
            if (email == emailVect[i])
                j--;
            continue;
        }
        notfVect.push_back(email);
        myfile << email << endl;
        //to prevent overlap
        word4 = "";
    };

    myfile.close();

    //}
    myfile.open("Email Found_500000.txt");
    for (int i = 0; i < 10; i++)
    {
        myfile << emailVect[rand() % emailVect.size()] << endl;
    }
    myfile.close();
    //return 0;
}
