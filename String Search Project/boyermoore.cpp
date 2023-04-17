#include "boyermoore.h"
boyermoore::boyermoore() {
	
}






 
// bad character heuristic  
void boyermoore::badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1  
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence  
    // of a character  
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}





/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void boyermoore::search(vector<string> myVector, string pat)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        string txt = myVector[i];
        int m = pat.size();
        int n = txt.size();

        int badchar[NO_OF_CHARS];

        /* Fill the bad character array by calling
        the preprocessing function badCharHeuristic()
        for given pattern */
        badCharHeuristic(pat, m, badchar);

        int s = 0; //s is shift of the pattern with respect to text
                    
        while (s <= (n - m))
        {
            int j = m - 1;
            // reduce index j of the pattern if while the pattern and text are matching
            while (j >= 0 && pat[j] == txt[s + j])
                j--;
            // if the pattern is present then index will become -1
            if (j < 0)
            {
                cout << "pattern occurs at shift = " << s << endl;

                cout << txt << endl;
                //move the pattern so the next character aligns with its last occurence
                s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

            }

            else
                //Move the pattern so that the bad char aligns wiht its last occurence in the pattern.
                //  ensure we only have positive values
                s += max(1, j - badchar[txt[s + j]]);
        }
    }
}