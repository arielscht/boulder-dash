#ifndef __SCORE__
#define __SCORE__

#include <stdlib.h>
#include "../../utils/utils/utils.h"
#include "../../utils/constants.h"

void save_score(int score);
void read_score(int savedScores[MAX_SCORE_STORED], int *scoreQtd);

#endif