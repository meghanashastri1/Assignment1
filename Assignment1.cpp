#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
  //declare all variables before program starts
  string fileName;
  string dnaSequence;
  string nucleotide;
  string bigram;

  //variables that count number of A, T, G, and C's in a dna sequence in the user Input file
  int numA = 0; int numT = 0; int numG = 0; int numC = 0;

  //nucleosum is the sum of all nucleotides (A, T, G, or C) in the input file
  int nucleoSum = 0;

  //probability of each nucleotide being printed in file
  double probA = 0; double probT = 0; double probG = 0; double probC = 0;

  //variables that count the sum of all possible bigrams
  int numAA = 0; int numAT = 0; int numAG = 0; int numAC = 0;
  int numTA = 0; int numTT = 0; int numTG = 0; int numTC = 0;
  int numGA = 0; int numGT = 0; int numGG = 0; int numGC = 0;
  int numCA = 0; int numCT = 0; int numCG = 0; int numCC = 0;

  //sum of all bigrams, used to calculate bigram probabilities
  int bigramSum = 0;
  //variables that calculate the possiblity of every possible bigram in file
  double probAA = 0; double probAT = 0; double probAG = 0; double probAC = 0;
  double probTA = 0; double probTT = 0; double probTG = 0; double probTC = 0;
  double probGA = 0; double probGT = 0; double probGG = 0; double probGC = 0;
  double probCA = 0; double probCT = 0; double probCG = 0; double probCC = 0;

  int sequenceSum = 0; //sum of the number of sequences in file
  int seqLength = 0;  //length of each sequence in file
  double mean = 0;    // mean number of nucleotides in the file
  double stDev = 0;   // standard deviation
  double var = 0;     //variance
  double a = 0;       //random number a used in gaussian distribution for calculating c
  double b = 0;       //random number b used in gaussian distribution for calculating c
  string newSequence = ""; //new sequence of length d that gets printed 1000 times


  //bool answer = true ; //boolean to test if user wants to analyze a file
  string userInput;    //user's choice when asked if they want to analyze a file


  while (true) {
    cout << "Do you want to enter a file to analyze? Enter 'yes' or 'no' " << endl;
    cin >> userInput;
    if (userInput == "no") {
      break;  //break out of while loop if user doesn't want to analyze a file
    }
    cout << "input a file to analyze" << endl;
    cin >> fileName;

    // user input is a file name, open the file using ifstream class
    ifstream file(fileName);  //reference for file I/O ifstream: http://www.cplusplus.com/doc/tutorial/files/

    //make sure that file opens
    if (file.is_open()) {

      //while loop iterates over each line (dna sequence) in the input file
      while (file >> dnaSequence) { //reference for how to iterate over a line in a file: https://www.geeksforgeeks.org/cpp-program-read-file-word-word/
        
        //set the length of each sequence to the length of the line
        seqLength = dnaSequence.length();

        //for each nucleotide in each sequence
        for (int i = 0; i < dnaSequence.length(); ++i){
          //nucleotide is a substring of 1 in each sequence
          //help with nucleotide: SI Matthew Raymond
          nucleotide = dnaSequence.substr(i,1);
          //add each nucleotide to the total sum, sum will be used to calculate probability
          nucleoSum += 1;

          //test which nucleotide is read and add that to the total number of the specific nucleotide
          if ((nucleotide == "A" )|| (nucleotide == "a")) {
            numA += 1;
          } else if (nucleotide == "T" || nucleotide == "t") {
            numT += 1;
          } else if (nucleotide == "G" || nucleotide == "g") {
            numG += 1;
          } else if (nucleotide == "C" || nucleotide == "c") {
            numC += 1;
          }


          //bigram is a substring of 2 in each sequence
          //help with bigram: SI Matthew Raymond
          bigram = dnaSequence.substr(i, 2);

          //add each bigram to the total number of bigrams for the file
          bigramSum +=1;

          //test which bigram is read and add that to the total number of the specific bigram
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
        //increase number of lines (sequences) by 1
        sequenceSum += 1;

        //calculate mean using sum of nucleotides divides by total number of sequences
        mean = (double)nucleoSum/(double)sequenceSum;

        //calculate probabilites of all nucleotides using total of each nucleotide divided by all nucleotides
        probA = (double)numA/(double)nucleoSum;
        probT = (double)numT/(double)nucleoSum;
        probG = (double)numG/(double)nucleoSum;
        probC = (double)numC/(double)nucleoSum;

        //calculate probabilites of all bigrams using total of each bigram divided by all bigrams
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

        //calculate variance by adding each
        //reference for pow function: https://www.programiz.com/cpp-programming/library-function/cmath/pow
        var += (double)pow((seqLength - mean), 2)/(double)sequenceSum;
        //cout << "the variance is " << var << endl;

      }// end while loop
      //seqLength = dnaSequence.length();
      //close file after it's finished being read
      file.close();

      //calculate standard deviation by square rooting the variance
      stDev = (double)sqrt(var);

      //print results to an output file using ofstream class
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
      //close the file so that anything appended afterwards doesn't overwrite the header and results
      output.close();

      //open the output file for appending
      //reference for appending files: https://www.tutorialride.com/cpp-file-management/append-to-a-file-c-program.htm
      output.open("meghanashastri.out", ios::app);

      //print 1000 DNA sequences
      for (int i = 0; i < 1000; ++i) {
        //formula for random number a between 0 and 1
        //reference: Rene German
        a = (double)rand()/RAND_MAX;
        //cout << "a = " << a << endl;

        //formula for random number b between 0 and 1
        //reference: Rene German
        b = (double)rand()/RAND_MAX;
        //cout << "b = " << b << endl;

        //calculate random variable c for gaussian distribution
        double c = sqrt(-2 *log(a))*(cos(2*M_PI*b));

        //find gaussian distribution d using c, standard deviation, and mean
        //this is the length of each new string that is printed 1000 times
        int d = 0;
        d = ((stDev*c) + mean);
        //output << " d = " << d << endl;
        //output << d << endl;
        //aD is the number of "A" nucleotides needed in each new string with length d
        //calculate aD by muliplying length of each new sequence by the probability of A from the input file
        int aD = d * probA;
        //output << aD << endl;
        //append newSequence with nucleotide A
        for (int i = 0; i < aD; i++) {
          newSequence += "A";
        }

        //tD is the number of "T" nucleotides needed in each new string with length d
        //calculate tD by muliplying length of each new sequence by the probability of T from the input file
        int tD = d * probT;
        for (int i = 0; i < tD; i++) {
          newSequence += "T";
        }

        //gD is the number of "G" nucleotides needed in each new string with length d
        //calculate gD by muliplying length of each new sequence by the probability of G from the input file
        int gD = d * probG;
        for (int i = 0; i < gD; i++) {
          newSequence += "G";
        }

        //cD is the number of "C" nucleotides needed in each new string with length d
        //calculate cD by muliplying length of each new sequence by the probability of C from the input file
        int numcD = d * probC;
        for (int i = 0; i < numcD; i++) {
          newSequence += "C";
        }

        //shuffle each newSequence since the newSequence is not random after the nucleotides are appended
        //reference on how to shuffle a string: http://www.cplusplus.com/reference/algorithm/random_shuffle/
        random_shuffle(newSequence.begin(), newSequence.end());

        //output new sequence to output file
        output << newSequence << endl;

        //once new Sequence is in the output file, reset newSequence to have no characters
        newSequence = "";
      }
        }
  }//end while loop that asks if you want to analyze a file or not

  return 0;
}//end main
