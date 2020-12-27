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


vector <string> generateEmail();
void priorityQueue(vector<string>);

int main()
{
    //vectEmail.push_back("abc");
    //vectEmail.push_back("cds");
    //vectEmail.push_back("bvf");
    //vectEmail.push_back("red");

   vector<string> vectEmail = generateEmail();
   priorityQueue(vectEmail);
    return 0;
}
