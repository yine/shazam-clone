#include <iostream>
#include <stdlib.h>
#include <sndfile.h>

#include "../common/gpu_helpers.cu"
#include "../common/cpu_helpers.cpp"
#include "../common/audiodatabase.cpp"

using namespace std;

int main(int argc, char *argv[])
{   
    /* STEP 0: Decide whether to run in CUDA mode or not */
    int CUDA_MODE = 0;
    if(argc==2 && (strcmp(argv[1], "-cuda") == 0)) {
        CUDA_MODE = 1;
    }

    /* STEP 1: Request the folder containing .wav files */
    char inputDirPath[100];
    cout << "Enter the name of folder containing WAVs to footprint: ";
    cin.getline(inputDirPath, sizeof inputDirPath);
    cout << endl;

    /* STEP 2: Build the database */
    DB* database = new DB();
    database->initFromScratch(inputDirPath);

    /* STEP 3: Serialize the database into text files */
    database->serializeToFiles((char *) "HASHES.txt", (char *) "FILENAMES.txt");

    return 0;
}