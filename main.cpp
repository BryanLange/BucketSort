#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void printAry(int*, int, ofstream&);

int main(int argc, char** argv) {
    if(argc == 4) {

        // open input and output files
        ifstream inFile;
        inFile.open(argv[1]);
        ofstream outFile1, outFile2; // outFile2 used for debugging
        outFile1.open(argv[2]);
        outFile2.open(argv[3]);

        // read file to find largest data
        // close and re-open file
        int size = 0, data;
        while(inFile >> data) {
            if(data > size) size = data;
        }
        inFile.close();
        inFile.open(argv[1]);

        // dynamically allocate 1D bucketAry to largest data + 1
        // initialize bucketAry to zero
        int* bucketAry = new int[size+1];
        for(int i=0; i<=size; i++) {
            bucketAry[i] = 0;
        }

        // read file and increment count of each data
        // print bucketAry state after each read
        while(inFile >> data) {
            bucketAry[data]++;
            printAry(bucketAry, size, outFile2);
        }

        // output sorted data
        for(int i=0; i<=size; i++) {
            while(bucketAry[i] > 0) {
                outFile1 << i << " ";
                bucketAry[i]--;
            }
        }

        // close input and output files
        inFile.close();
        outFile1.close();
        outFile2.close();

        // flush memory
        delete[] bucketAry;

    } else {
        cout << "Invalid number of arguments.\n";
    }
} // end main

void printAry(int* ary, int size, ofstream& outFile) {
    outFile << "index:";
    for(int i=0; i<=size; i++) {
        outFile << setw(2) << i << " ";
    }
    outFile << endl << "count:";
    for(int i=0; i<=size; i++) {
        outFile << setw(2) << ary[i] << " ";
    }
    outFile << endl << endl;
} // end printAry()
