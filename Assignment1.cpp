#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
//use to ensure you get a random number.
#include <time.h>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
  string fileName;
  string dnaSequence;
  string nucleotide;
  string bigram;
  int numA = 0; int numT = 0; int numG = 0; int numC = 0;

  int nucleoSum = 0;
  double probA = 0; double probT = 0; double probG = 0; double probC = 0;

  int numAA = 0; int numAT = 0; int numAG = 0; int numAC = 0;
  int numTA = 0; int numTT = 0; int numTG = 0; int numTC = 0;
  int numGA = 0; int numGT = 0; int numGG = 0; int numGC = 0;
  int numCA = 0; int numCT = 0; int numCG = 0; int numCC = 0;

  int bigramSum = 0;
  double probAA = 0; double probAT = 0; double probAG = 0; double probAC = 0;
  double probTA = 0; double probTT = 0; double probTG = 0; double probTC = 0;
  double probGA = 0; double probGT = 0; double probGG = 0; double probGC = 0;
  double probCA = 0; double probCT = 0; double probCG = 0; double probCC = 0;

  double biProbSum = 0;
  double nuProbSum = 0;
  int sequenceSum = 0;
  int seqLength = 0;
  double meanDistance = 0;
  double meanDistSquared = 0;
  double sumMDS = 0;
  double mean = 0;
  double stDev = 0;
  double var = 0;
  double a = 0;
  double b = 0;
  double randNum = 0;
  string newSequence = "";

  //use to ensure you have a really random number
  //help from Joely
  //srand(time(NULL));

  cout << "input a file to analyze" << endl;
  cin >> fileName;

  //reference for file I/O ifstream: http://www.cplusplus.com/doc/tutorial/files/
  ifstream file(fileName);
  if (file.is_open()) {
    //reference for how to iterate over a line in a file: https://www.geeksforgeeks.org/cpp-program-read-file-word-word/
    while (file >> dnaSequence) {
      cout << dnaSequence << "\n";
      seqLength = dnaSequence.length();
      for (int i = 0; i < dnaSequence.length(); ++i){
        nucleotide = dnaSequence.substr(i,1);
        nucleoSum += 1;
        if ((nucleotide == "A" )|| (nucleotide == "a")) {
          numA += 1;
        } else if (nucleotide == "T" || nucleotide == "t") {
          numT += 1;
        } else if (nucleotide == "G" || nucleotide == "g") {
          numG += 1;
        } else if (nucleotide == "C" || nucleotide == "c") {
          numC += 1;
        }

        //help with bigram: SI Matthew Raymond
        bigram = dnaSequence.substr(i, 2);
        bigramSum +=1;
        if (bigram == "AA" || bigram == "aa" || bigram == "aA" || bigram == "Aa") {
          numAA += 1;
          bigramSum +=1;
        } else if (bigram == "AT" || bigram == "at" || bigram == "aT" || bigram == "At") {
          numAT += 1;
          bigramSum +=1;
        } else if (bigram == "AG" || bigram == "ag" || bigram == "aG" || bigram == "Ag") {
          numAG += 1;
          bigramSum +=1;
        } else if (bigram == "AC" || bigram == "ac" ||bigram == "aC" || bigram ==  "Ac") {
          numAC += 1;
          bigramSum +=1;
        } else if (bigram == "TA" || bigram ==  "ta" || bigram == "tA" || bigram == "Ta") {
          numTA += 1;
          bigramSum +=1;
        } else if (bigram == "TT" || bigram == "tt" || bigram == "tT" || bigram == "Tt") {
          numTT += 1;
          bigramSum +=1;
        } else if (bigram == "TG" || bigram == "tg" || bigram == "tG" || bigram ==  "Tg") {
          numTG += 1;
          bigramSum +=1;
        } else if (bigram == "TC" || bigram == "tc" || bigram == "tC" || bigram == "Tc") {
          numTC += 1;
          bigramSum +=1;
        } else if (bigram == "GA" || bigram == "ga" || bigram == "gA" || bigram == "Ga") {
          numGA += 1;
          bigramSum +=1;
        } else if (bigram == "GT" || bigram == "gt" || bigram == "gT" || bigram == "Gt") {
          numGT += 1;
          bigramSum +=1;
        } else if (bigram == "GG" || bigram == "gg" || bigram == "gG" || bigram ==  "Gg") {
          numGG += 1;
          bigramSum +=1;
        } else if (bigram == "GC" || bigram == "gc" || bigram == "gC" || bigram == "Gc") {
          numGC += 1;
          bigramSum +=1;
        } else if (bigram == "CA" || bigram == "ca" || bigram == "cA" | bigram ==  "Ca") {
          numCA += 1;
          bigramSum +=1;
        } else if (bigram == "CT" || bigram == "ct" || bigram == "cT" || bigram == "Ct") {
          numCT += 1;
          bigramSum +=1;
        } else if (bigram == "CG" || bigram == "cg" || bigram == "cG" || bigram == "Cg") {
          numCG += 1;
          bigramSum +=1;
        } else if (bigram == "CC" || "cc" || "cC" || "Cc") {
          numCC += 1;
          bigramSum +=1;
        }
      }//end for loop
      sequenceSum += 1;
      mean = (double)nucleoSum/(double)sequenceSum;

      probA = (double)numA/(double)nucleoSum;
      probT = (double)numT/(double)nucleoSum;
      probG = (double)numG/(double)nucleoSum;
      probC = (double)numC/(double)nucleoSum;
      probAA = (double)numAA/(double)bigramSum;
      probAT = (double)numAT/(double)bigramSum;
      probAG = (double)numAG/(double)bigramSum;
      probAC = (double)numAC/(double)bigramSum;
      probTA = (double)numTA/(double)bigramSum;
      probTT = (double)numTT/(double)bigramSum;
      probTG = (double)numTG/(double)bigramSum;
      probTC = (double)numTC/(double)bigramSum;
      probGA = (double)numGA/(double)bigramSum;
      probGT = (double)numGT/(double)bigramSum;
      probGG = (double)numGG/(double)bigramSum;
      probGC = (double)numGC/(double)bigramSum;
      probCA = (double)numCA/(double)bigramSum;
      probCT = (double)numCT/(double)bigramSum;
      probCG = (double)numCG/(double)bigramSum;
      probCC = (double)numCC/(double)bigramSum;

      //reference for pow function: https://www.programiz.com/cpp-programming/library-function/cmath/pow
      var += (double)pow((seqLength - mean), 2)/(double)sequenceSum;
      cout << "the variance is " << var << endl;
      //biProbSum = probAA + probAT + probAG + probAC + probTA + probTT + probTG + probTC + probGA + probGT + probGG + probGC + probCA + probCT + probCG + probCC;
    }// end while loop
    //seqLength = dnaSequence.length();
    file.close();

    stDev = (double)sqrt(var);

    //reference for output file ofstream: https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
    ofstream output;
    output.open("meghanashastri.out");
    output << "Name: Meghana Shastri" << endl;
    output << "Student ID: 2317343" << endl;
    output << "Class: CPSC 350" << endl;
    output << "Section: section 2" << endl;
    output << " " << endl;
    output << "the nucleotide sum is " << nucleoSum << endl;
    output << "the bigram sum is " << bigramSum << endl;
    output << "the mean is " << mean << endl;
    output << "the variance is " << var << endl;
    output << "the standard deviation is " << stDev << endl;
    output << " " << endl;
    output << "the probability of A is " << probA << endl;
    output << "the probability of T is " << probT << endl;
    output << "the probability of G is " << probG << endl;
    output << "the probability of C is " << probC << endl;
    output << " " << endl;
    output << "the probability of AA is " << probAA << endl;
    output << "the probability of AT is " << probAT << endl;
    output << "the probability of AG is " << probAG << endl;
    output << "the probability of AC is " << probAC << endl;
    output << "the probability of TA is " << probTA << endl;
    output << "the probability of TT is " << probTT << endl;
    output << "the probability of TG is " << probTG << endl;
    output << "the probability of TC is " << probTC << endl;
    output << "the probability of GA is " << probGA << endl;
    output << "the probability of GT is " << probGT << endl;
    output << "the probability of GG is " << probGG << endl;
    output << "the probability of GC is " << probGC << endl;
    output << "the probability of CA is " << probCA << endl;
    output << "the probability of CT is " << probCT << endl;
    output << "the probability of CG is " << probCG << endl;
    output << "the probability of CC is " << probCC << endl;
    output.close();

    output.open("meghanashastri.out", ios::app);

    for (int i = 0; i < 1000; ++i) {
      //a = (double) rand() / RAND_MAX;
      a = (float)rand()/RAND_MAX;
      cout << "a = " << a << endl;
      //b = (double) rand() /RAND_MAX;
      b = (double)rand()/RAND_MAX;
      cout << "b = " << b << endl;
      //help with calculating c: Michelle Yoon
      double c = sqrt(-2 *log(a))*(cos(2*M_PI*b));
      int d = 0;
      //https://www.programiz.com/cpp-programming/library-function/cmath/trunc
      d = ((stDev*c) + mean);
      //output << " d = " << d << endl;
      //output << d << endl;
      //for (int i = 0; i < d; ++i) {
          int aD = d * probA;
          //output << aD << endl;
          for (int i = 0; i < aD; i++) {
            newSequence += "A";
          }
          int tD = d * probT;
          for (int i = 0; i < tD; i++) {
            newSequence += "T";
          }
          int gD = d * probG;
          for (int i = 0; i < gD; i++) {
            newSequence += "G";
          }
          int numcD = d * probC;
          for (int i = 0; i < numcD; i++) {
            newSequence += "C";
          }
      //}
      //
      random_shuffle(newSequence.begin(), newSequence.end());
      output << newSequence << endl;
      newSequence = "";
    }


      }
  return 0;
}
