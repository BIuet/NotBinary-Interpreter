#include <iostream>
#include <fstream>
#include "utils.h"
#include "interpret.h"
using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
      cout << "Usage: ./main file.txt";
   }
   else
   {
      string data = "";
      string filename = argv[1];
      ifstream inFile(filename);
      string data1;
      while (getline (inFile, data1))
      {
         data += data1;
      }
      inFile.close();
      // prepares code
      data1 = data;
      string cleanData = clean(data);
      data = removeHeader(cleanData);
      if (data == "N")
      {
         cout << "Error:  Cannot parse the code:" << endl << cleanData.length() % 3 << endl;
         return 0;
      }
      vector<string> tokens = tokenize(data); 
      if (!checkBrackets(tokens)) 
      {
         cout << "Error: Too many opens or closes." << endl;
      }
      interpret(tokens);
   }
   return 0;
}
