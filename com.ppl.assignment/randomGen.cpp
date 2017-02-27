#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

int main()
{
    char names[500][100];
    ifstream infile("names.txt");
    string line;
    int i = 0;
    while (std::getline(infile, line))
    {
        istringstream iss(line);
        int a, b;
        if (!(iss >> names[i])) { break; } // error
        i++;
    }
    srand(time(NULL));
    infile.close();
    ofstream myfile;
    myfile.open ("boys.txt");
    myfile << 300 << endl;
    {int a = rand()%6 + 1;
    int b = rand()%20000 + 5000;
    int in = rand()%6 + 1;
    int m = rand()%5 + 1;
    int t = rand()%3;
    int ind = -1;
    myfile << names[0] << " " << a << " " << b << " " << in << " " << m << " " << t << " " << ind << endl;}
    for(int i = 1; i < 300; i++){

    int a = rand()%10 + 1;
    int b = rand()%30000 + 5000;
    int in = rand()%10 + 1;
    int m = rand()%5 + 1;
    int t = rand()%3;
    int ind = -1;
    myfile << names[i] << " " << a << " " << b << " " << in << " " << m << " " << t << " " << ind << endl;
    }
    myfile.close();

    ofstream myfile2;
    myfile2.open ("girls.txt");
    myfile2 << 50 << endl;
    for(int i = 0; i < 50; i++){

    int a = rand()%10 + 1;
    int mb = rand()%10000 + 5000;
    int in = rand()%10 + 1;
    int p = rand()%3;
    int t = rand()%3;
    int ind = -1;
    myfile2 << names[i+300] << " " << a << " " << mb << " " << in << " " << p << " " << t << " " << ind << endl;
    }
    myfile2.close();

    ofstream myfile3;
    myfile3.open ("list.txt");
    int p = 100;
    int t,v,a,b;
    for(int i = 0; i < 50; i++)
    {
        if(i == 0)
            t = 3;
        else
            t = rand()%3 + 1;
        p = p + rand()%500;
        v = rand()%1000 + 100;

        if( t == 1){
            a = 0;
            b = 0;
        }
        else{
            a = rand()%50 + 10;
            b = rand()%50 + 10;
        }
        myfile3 << t << " " << p << " " << v << " " << a << " " << b << endl;
    }
    myfile3.close();

    ofstream myfile4;
    myfile4.open ("k.txt");
    myfile4 << rand()%10 + 10 << endl;
    myfile4.close();

    return 0;
}
