#include "score.h"

//insert a new value into an array position
void insert(int array[MAX_SCORE_STORED], int scoreQtd, int value, int index)
{
    int i = scoreQtd - 1;
    for (; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = value;
}

//find the position to insert a new score
void findIndexToInsert(int array[MAX_SCORE_STORED], int *scoreQtd, int score)
{
    if (*scoreQtd == 0)
    {
        *scoreQtd += 1;
        insert(array, *scoreQtd, score, 0);
    }
    else
    {
        for (int i = 0; i < *scoreQtd; i++)
        {
            if (score > array[i])
            {
                if (*scoreQtd < MAX_SCORE_STORED)
                    *scoreQtd += 1;
                insert(array, *scoreQtd, score, i);
                break;
            }
            else if (i == *scoreQtd - 1 && *scoreQtd < MAX_SCORE_STORED)
            {
                *scoreQtd += 1;
                insert(array, *scoreQtd, score, i + 1);
                break;
            }
        }
    }
}

//read the score file
void read_score(int savedScores[MAX_SCORE_STORED], int *scoreQtd)
{
    FILE *scoreFile = fopen("./resources/data/score.txt", "r");

    //reads the file if exist
    if (scoreFile)
    {
        for (int i = 0; i < MAX_SCORE_STORED; i++)
        {
            if (fscanf(scoreFile, "%d ", &savedScores[i]) == 1)
                *scoreQtd += 1;
        }
        fclose(scoreFile);
    }
}

//save the new score in the scores file
void save_score(int score)
{
    int savedScores[MAX_SCORE_STORED] = {0, 0, 0, 0, 0};
    int scoreQtd = 0;

    read_score(savedScores, &scoreQtd);

    //rewrites the file
    FILE *scoreFile = fopen("./resources/data/score.txt", "w");
    must_init(scoreFile, "output file to write");

    findIndexToInsert(savedScores, &scoreQtd, score);

    for (int i = 0; i < scoreQtd; i++)
        fprintf(scoreFile, "%d ", savedScores[i]);

    fclose(scoreFile);
}