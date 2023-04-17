#include "RabinKarp.h"
# define NO_OF_CHARS 256 


  
void RabinKarp::search(string pat, vector<string> myVector, int q)
{
    for (int v = 0; v < myVector.size(); v++)
    {

        
        int M = pat.size();
        int N = myVector[v].size();
        int i, j;
        int p = 0; // hash for pattern  
        int t = 0; // hash for txt  
        int h = 1;

        // value of h is pow(d, M-1)%q
        for (i = 0; i < M - 1; i++)
            h = (h * NO_OF_CHARS) % q;

        // Calculate the hash value of pattern and first value in vector
          
        for (i = 0; i < M; i++)
        {
            p = (NO_OF_CHARS * p + pat[i]) % q;
            t = (NO_OF_CHARS * t + myVector[v][i]) % q;
        }

        // compare the pattern over text one by one  
        for (i = 0; i <= N - M; i++)
        {


            //Check the hash of current items and patterns, if the hash only match them then check characters one by one  
            if (p == t)
            {
                // Checks for indivdual characters 
                for (j = 0; j < M; j++)
                {
                    if (myVector[v][i + j] != pat[j])
                        break;
                }

                //if a pattern is found cout that item of the vector
                if (j == M)
                    cout << "Pattern found at index " << i << endl;
                cout << myVector[v] << endl;
            }

            // Calculate hash value for next item in vector Remove leading digit, add trailing digit  
            if (i < N - M)
            {
                t = (NO_OF_CHARS * (t - myVector[v][i] * h) + myVector[v][i + M]) % q;

              //  ensure we only have positive values
                if (t < 0)
                    t = (t + q);
            }
        }
    }
}

