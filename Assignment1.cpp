#include <iostream>
using namespace std;
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <string.h>

int main()
{
  //Declaring variables
  ifstream inFile;
  string line;
  string fileName;

  float cntA, cntT, cntC, cntG;
  cntA = cntT = cntC = cntG = 0;
  float cntAA, cntTT, cntCC, cntGG, cntAT, cntAC, cntAG, cntTA, cntTC, cntTG, cntCA, cntCT, cntCG, cntGA, cntGT, cntGC;
  cntAA = cntTT = cntCC = cntGG = cntAT = cntAC = cntAG = cntTA = cntTC = cntTG = cntCA = cntCT = cntCG = cntGA = cntGT = cntGC = 0;

  float probA, probT, probC, probG, probAA, probTT, probCC, probGG, probAT, probAC, probAG, probTA, probTC, probTG, probCA, probCT, probCG, probGA, probGT, probGC;
  probA = probT = probC = probG = probAA = probTT = probCC = probGG = probAT = probAC = probAG = probTA = probTC= probTG = probCA = probCT = probCG = probGA = probGT = probGC = 0;

  float nbrLines = 0;
  float sumLengths = 0;

  float mean = 0;

  float sqDiffSum = 0;
  float variance = 0;
  float stdDev = 0;

  int lineLength;

  //Defining a & b
  float a = 0;
  float b = 0;

  cout << "What is the name of the file you would like to analyze?";
  //Read file name from command line
  cin >> fileName;

  //Read from file
  inFile.open(fileName + ".txt");

  //Error mssg if not found
  if (!inFile) {
    cout << "Unable to open file";
    exit(1);
  } else{

    //Iterate through each line
    while (getline (inFile,line))
     {
      //Add every length
      sumLengths += line.length()-1;

      for (int i = 0; i < line.length(); i++)
      {
          //Make every char uppercase
          line[i] = toupper(line[i]);
          //Count each type
          if (line[i] == 'A') cntA += 1;
          if (line[i] == 'T') cntT += 1;
          if (line[i] == 'C') cntC += 1;
          if (line[i] == 'G') cntG += 1;

          if (line[i] == 'A' && line[i+1] == 'A') cntAA += 1;
          if (line[i] == 'T' && line[i+1] == 'T') cntTT += 1;
          if (line[i] == 'C' && line[i+1] == 'C') cntCC += 1;
          if (line[i] == 'G' && line[i+1] == 'G') cntGG += 1;
          if (line[i] == 'A' && line[i+1] == 'T') cntAT += 1;
          if (line[i] == 'A' && line[i+1] == 'G') cntAG += 1;
          if (line[i] == 'A' && line[i+1] == 'C') cntAC += 1;
          if (line[i] == 'T' && line[i+1] == 'A') cntTA += 1;
          if (line[i] == 'T' && line[i+1] == 'C') cntTC += 1;
          if (line[i] == 'T' && line[i+1] == 'G') cntTG += 1;
          if (line[i] == 'C' && line[i+1] == 'A') cntCA += 1;
          if (line[i] == 'C' && line[i+1] == 'T') cntCT += 1;
          if (line[i] == 'C' && line[i+1] == 'G') cntCG += 1;
          if (line[i] == 'G' && line[i+1] == 'A') cntGA += 1;
          if (line[i] == 'G' && line[i+1] == 'T') cntGT += 1;
          if (line[i] == 'G' && line[i+1] == 'C') cntGC += 1;
          }
      //Count number of lines
      nbrLines += 1;
      }
      //Close file
      inFile.close();
   }
   //Calculate the mean of the number of lines
   mean = sumLengths/nbrLines;

   //Open file again
   inFile.open(fileName + ".txt");

   //Read through file again
   while (getline (inFile,line))
    {
      //Find the sum of every square ";
      lineLength = line.length() - 1;
      sqDiffSum = (lineLength-mean) * (lineLength-mean);
    }
  //Close file
  inFile.close();

  //Calculate variance
  variance = sqDiffSum/nbrLines;
  //Calculate standard deviation
  stdDev = sqrt(variance);

  //Calculate single probability
  probA = cntA/sumLengths;
  probT = cntT/sumLengths;
  probC = cntC/sumLengths;
  probG = cntG/sumLengths;

  //Calculate bigram probability
  probAA = cntAA/sumLengths;
  probTT = cntTT/sumLengths;
  probCC = cntCC/sumLengths;
  probGG = cntGG/sumLengths;
  probAT = cntAT/sumLengths;
  probAC = cntAC/sumLengths;
  probAG = cntAG/sumLengths;
  probTA = cntTA/sumLengths;
  probTC = cntTC/sumLengths;
  probTG = cntTG/sumLengths;
  probCA = cntCA/sumLengths;
  probCT = cntCT/sumLengths;
  probCG = cntCG/sumLengths;
  probGA = cntGA/sumLengths;
  probGT = cntGT/sumLengths;
  probGC = cntGC/sumLengths;

  //Output
  ofstream outFile;
  //Open file
  outFile.open("luisabaldino.out");
  //Output basic info
  outFile.precision(2);
  outFile.setf(ios::fixed);
  outFile.setf(ios::showpoint);
  outFile << "Name: Luisa Baldino\nStudent ID: 2328991\nDate: 02/25/20\n";
  //Output stats
  outFile << "\nNumber of lines: " << nbrLines << "\n";
  outFile << "Sum of lengths: " << sumLengths << "\n";
  outFile << "Mean of lengths: " << mean << "\n";
  outFile << "Variance of lengths: " << variance << "\n";
  outFile << "Standard deviation of lengths: " << stdDev << "\n";
  outFile << "Probability of nuclotide A: " << probA << "\n";
  outFile << "Probability of nuclotide T: " << probT << "\n";
  outFile << "Probability of nuclotide C: " << probC << "\n";
  outFile << "Probability of nuclotide G: " << probG << "\n";
  outFile << "Probability of bigram AA: " << probAA << "\n";
  outFile << "Probability of bigram TT: " << probTT << "\n";
  outFile << "Probability of bigram CC: " << probCC << "\n";
  outFile << "Probability of bigram GG: " << probGG << "\n";
  outFile << "Probability of bigram AT: " << probAT << "\n";
  outFile << "Probability of bigram AC: " << probAC << "\n";
  outFile << "Probability of bigram AG: " << probAG << "\n";
  outFile << "Probability of bigram TA: " << probTA << "\n";
  outFile << "Probability of bigram TC: " << probTC << "\n";
  outFile << "Probability of bigram TG: " << probTG << "\n";
  outFile << "Probability of bigram CA: " << probCA << "\n";
  outFile << "Probability of bigram CT: " << probCT << "\n";
  outFile << "Probability of bigram CG: " << probCG << "\n";
  outFile << "Probability of bigram GA: " << probGA << "\n";
  outFile << "Probability of bigram GT: " << probGT << "\n";
  outFile << "Probability of bigram GC: " << probGC << "\n";

  outFile << "------------------------------------------\n";

  //OUTPUTTING NEW LINES

  for (int i = 0; i < 1000; ++i){

    //Gaussian distribution c
    a = ((float) rand() / (RAND_MAX));
    b = ((float) rand() / (RAND_MAX));
    float c = sqrt(-2*log10(a)) * cos(2*M_PI*b);
    //Calculate length d of new line
    float d = stdDev*c + mean;

    //Nucleotides
    int nbrA = round(probA * d);
    int nbrT = round(probT * d);
    int nbrG = round(probG * d);
    int nbrC = round(probC * d);

    // Build string
    string newLine = "";
    for (int i = 0; i < nbrA; ++i){
      newLine += "A";
    }
    for (int i = 0; i < nbrT; ++i){
      newLine += "T";
    }
    for (int i = 0; i < nbrC; ++i){
      newLine += "C";
    }
    for (int i = 0; i < nbrG; ++i){
      newLine += "G";
    }

    // Output line
    outFile << newLine << "\n";
  }


return 0;
}
