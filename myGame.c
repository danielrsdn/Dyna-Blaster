# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <time.h>
# include <stdbool.h>

// Name: Daniel Rashidian

// C program of Bomberman game 


/* checkIfValidString checks if valid string
* 	argument: userInput
*	return: int
*/
int checkIfValidString(char* userInput) {
	
	int i = 0;
	int answer = 1;
	
	while (*(userInput + i) != '\0') {
		
		if (isdigit(*(userInput + i)) != 0) {
			answer = 0;
		}
		
		i++;
	}
	
	return answer;
}




/* checkIfValidInteger checks if valid integer
* 	argument: userInput
*	return: int
*/
int checkIfValidInteger(char* userInput) {
	int i = 0;
	int answer = 1;
	
	while (*(userInput + i) != '\0') {
		
		if (isdigit(*(userInput + i)) == 0) {
			answer = 0;
		}
		
		i++;
	}
	
	return answer;
}


/* placeNegatives sets negative tiles
* 	argument: boardGame, n, m
*/
void placeNegatives(float* boardGame, int n, int m) {
		
	int tiles = n * m;
	int i = 1;
	
	while (i < tiles) {
		i = i * 2;
	}
	
	unsigned int numberOfNegatives = 0;
	
	while ((((float) numberOfNegatives/tiles) > 0.40) ||  (((float) numberOfNegatives/tiles) < 0.35)) {
		unsigned int bitxn = i;
		unsigned int a = rand();
		unsigned int b = a/tiles;
		unsigned int c = a + (b * (bitxn - tiles));
		bitxn = bitxn - 1;
		numberOfNegatives = c & bitxn;
	}
	
	
	while (numberOfNegatives >  0) {
		unsigned bitxn = i;
		unsigned int a = rand();
		unsigned int b = a/tiles;
		unsigned int c = a + (b * (bitxn - tiles));
		bitxn = bitxn - 1;
		unsigned int d = c & bitxn;
		
		if ((*(boardGame + d) != 1.00) && (*(boardGame + d) != 19.00)) {
			*(boardGame + d) = 1.00;
			numberOfNegatives--;
		
		}
	
	}
	
}


/* placeSpecials sets special tiles
* 	argument: boardGame, n, m
*/
void placeSpecials(float* boardGame, int n, int m) {

			
	int tiles = n * m;
	int i = 1;
	
	while (i < tiles) {
		i = i * 2;
	}
	
	unsigned int numberOfSpecials = 0;
	
	while ((((float) numberOfSpecials/tiles) > 0.20) ||  (((float) numberOfSpecials/tiles) < 0.15)) {
		unsigned int bitxn = i;
		unsigned int a = rand();
		unsigned int b = a/tiles;
		unsigned int c = a + (b * (bitxn - tiles));
		bitxn = bitxn - 1;
		numberOfSpecials = c & bitxn;
		numberOfSpecials--;
	}
	
	
	while (numberOfSpecials >  0) {
		unsigned bitxn = i;
		unsigned int a = rand();
		unsigned int b = a/tiles;
		unsigned int c = a + (b * (bitxn - tiles));
		bitxn = bitxn - 1;
		unsigned int d = c & bitxn;
		
		if (((*(boardGame + d) != 1.00) && (*(boardGame + d) != 2.00)) && (*(boardGame + d) != 19.00))  {
			*(boardGame + d) = 2.00;
			numberOfSpecials--;
		
		}
	
	}
	
}


/* randomNumber gets random number
* 	argument: n, m, neg
*	returns float
*/
float randomNumber(int n, int m, int neg) {
	
	unsigned int a = rand();

	unsigned int b = a/1501;
	
	unsigned int c = a + (b * (2048-1501));
	
	unsigned int d = c & 2047;
	
	float randomFloat = (float) d;
	
	randomFloat = randomFloat/100.0;
	
	
	if (neg == 0) {
		return randomFloat;
	}
	
	else {
		return (randomFloat * -1);
	}
	
}


/* display shows board 
*/
void display(float* boardGame, int* gameTiles, float score, float totalScore, int lives, int star, int boost, int bad, int bombs, int n, int m, int mode) {
	if (mode == 0) {
	
		int negativeCounter = 0;
		int characterCounter = 0;
	
		int tiles = m * n;
		int j = 0;
	
		for (int i = 0; i < tiles; i++) {
			if (j == m) {
				printf("\n");
				j = 0;
			}
		
			if  (*(boardGame + i) == 19.00) {
				printf("   *      ");
				j++;
				characterCounter++;
			}
			
			else if  (*(boardGame + i) == 16.00) {
				printf("   $      ");
				j++;
				characterCounter++;
			}
			
			else if  (*(boardGame + i) == 17.00) {
				printf("   !      ");
				j++;
				characterCounter++;
				
			}
			
			
			else {
				if (*(boardGame + i) <= -10.00) {
					printf("%.2f    ", *(boardGame + i));
					j++;
				}
			
				else if (*(boardGame + i) < 0.00) {
					printf(" %.2f    ", *(boardGame + i));
					j++;
				}
			
				else if (*(boardGame + i) < 10.00) {
					printf("  %.2f    ", *(boardGame + i));
					j++;
				}
			
				else {
					printf(" %.2f    ", *(boardGame + i));
					j++;
				}
			
			}
			
			if  (*(boardGame + i) < 0) {
				negativeCounter++;
		}
			
	}
		
		printf("\nPercentage of negative tiles: %.2f\n", (((float) negativeCounter/tiles))*100);	
		printf("Percentage of special tiles: %.2f\n\n\n", (((float) characterCounter/tiles))*100);	
	}
		
	else if (mode == 1) {
				
		int tiles = n * m;
		int j = 0;
		
		printf("\n\n");	
		
		for (int i = 0; i < tiles; i++) {
			if (j == m) {
				printf("\n");
				j = 0;
			}
				
			if (*(gameTiles + i) == 1.00) {
				
		
				if  (*(boardGame + i) == 19.00) {
					printf("   *      ");
					j++;
						
				}
			
				else if  (*(boardGame + i) == 16.00) {
					printf("   $      ");
					j++;
						
				}
			
				else if  (*(boardGame + i) == 17.00) {
					printf("   !      ");
					j++;
						
				}
				
				else {
					
					if (*(boardGame + i) < 0.00) {
						printf("   -      ");
						j++;
					}
						
					else {
						
						printf("   +      ");
						j++;
						
					}
				}
				
			}
				
				
			else {
				
				printf("   X      ");
				j++;
					
			}
			
		}
		
		
		printf("\nLives: %d\n", lives);
		printf("Total Score: %.2f\n", totalScore);
		printf("Bombs: %d\n", bombs);
		
		
	}
		
}


/* initializeCharacter gets random character
*	returns float
*/
float initializeCharacter() {
	
	int randInt = rand() & 1;
	float num = 16.0 + randInt;
	return num;

}


/* setStarLocation sets stars in board game
*/
void setStarLocation(float* boardGame, int n, int m) {

	int tiles = n * m;
	int i = 1;
	
	while (i < tiles) {
		i = i * 2;
	}
	
	unsigned bitxn = i;
	unsigned int a = rand();
	unsigned int b = a/tiles;
	unsigned int c = a + (b * (bitxn - tiles));
	bitxn = bitxn - 1;
	unsigned int starLocationIndex = c & bitxn;
	
	*(boardGame + starLocationIndex) = 19.00;
}


/* initializeGame sets up board game at the beginning of the game
*/
void initializeGame(float* boardGame, int* gameTiles, int n, int m)
{

	int starCounter = 0;
	int tiles = n * m;
	
	
	setStarLocation(boardGame, n, m);
		

	
	placeNegatives(boardGame, n, m);
	
	
	
	placeSpecials(boardGame, n, m);
	

		
	for (int i = 0; i < tiles; i++) {
						
		if (*(boardGame + i) == 1.00) {
			*(boardGame + i) = randomNumber(n, m, 1);
		} 
		
		else if (*(boardGame + i) == 19.00) {
			//star character
			starCounter++;
		}
		
		else if (*(boardGame + i) == 2.00) {
			*(boardGame + i) = initializeCharacter();
			starCounter++;
		} 
		
		else {
		
			*(boardGame + i) = randomNumber(n, m, 0);
		}
		
	}
	
	
	
	for (int i = 0; i < tiles; i++) {
		*(gameTiles + i) = 0;
	}
	
	
}


/* getInput gets the user's input during the game. User must select x and y coordinate of selected tile
*/
void getInput(int* input, int* gameTiles, int n, int m) {
	
	printf("\nEnter x coordinate of the tile you wish to bomb. Enter 'exit' to quit game.\n");
	
	
	char* userInput = (char*) calloc(20, sizeof(char));
	char* exitOption = "exit";
	scanf("%s", userInput);
	
	int coordinatesCaptured = 0;
	int coordinateLimit = n;
	char message[] = "x";
	
	while (coordinatesCaptured != 2) {
		// printf("Enter %s coordinate of the tile you wish to bomb. Enter 'exit' to quit game.\n", message);
		
		if (checkIfValidInteger(userInput) == 0) {
			if (strcmp(userInput, exitOption) == 0) {
				*input = -1;
				*(input + 1) = -1;
				coordinatesCaptured = 2;
				
			}
			
			else {
				printf("Invalid input.\n");
				printf("Enter %s coordinate of the tile you wish to bomb. Enter 'exit' to quit game.\n", message);
				free(userInput);
				userInput = (char*) calloc(20, sizeof(char));
				scanf("%s", userInput);	
			}
		}
		
		else if ((atoi(userInput) >= coordinateLimit) || (atoi(userInput) < 0)) {
			printf("Invalid input. %s coordinate out of range.\n", message);
			printf("Enter %s coordinate of the tile you wish to bomb. Enter 'exit' to quit game.\n", message);
			free(userInput);
			userInput = (char*) calloc(20, sizeof(char));
			scanf("%s", userInput);	
		}
		
		else if (coordinatesCaptured == 0) {
			*input = atoi(userInput);
			coordinatesCaptured = 1;
			coordinateLimit = m;
			*message = 'y';
			printf("Enter %s coordinate of the tile you wish to bomb. Enter 'exit' to quit game.\n", message);
			free(userInput);
			userInput = (char*) calloc(20, sizeof(char));
			scanf("%s", userInput);	
			
		}
		
		else if (coordinatesCaptured == 1) {
			*(input + 1) = atoi(userInput);
			int tileIndex = ((*(input + 1)) * m) + *input;
			
			if (*(gameTiles + tileIndex) == 1) {
				printf("Error. this tile is already exploded. Please select another tile.\n");
				coordinatesCaptured = 0;
				coordinateLimit = n;
				*message = 'x';
				printf("Enter %s coordinate of the tile you wish to bomb. Enter 'exit' to quit game.\n", message);
				free(userInput);
				userInput = (char*) calloc(20, sizeof(char));
				scanf("%s", userInput);	
			}
			
			else {
				coordinatesCaptured = 2;
				
			}
		}
	}
	
}


void check(int line) {
	printf("No Issues after line %d\n", line);
}


/* processInput assures that only non-exploded tiles explode in the next user's turn
*/
void processInput(int* adjacentTiles, int* processedInput, int* gameTiles, int* numAdjacentTiles, int n, int m) {
	int i = 0;
	int j = 0;
	int tiles = n*m;
	int currentNumTiles = *numAdjacentTiles;
	
	for (i = 0; i < currentNumTiles; i++) {
		int comparisonIndex = *(adjacentTiles + i);
		int reject = 0;

		if (*(gameTiles + comparisonIndex) == 1) {
				reject = 1;
		}
				
		if (reject == 0) {
			*(processedInput + j) = comparisonIndex;
			*(gameTiles + comparisonIndex) = 1;
			j++;
		}
	}
	
	*numAdjacentTiles = j;
	
	
	for (int a = *numAdjacentTiles; a < tiles; a++) {
		*(processedInput + a) = -1;
	}	
	
}

/* getAdjacentTiles gets all of the tiles adjacent to a selected tile
*/
void getAdjacentTiles(int* input, int* adTiles, int* finalTiles, int* gameTiles, int* numTiles, int boost, int bad, int n, int m) {
	int xCoor = *input;
	int yCoor = *(input + 1);
	
	int minX;
	int minY;
	int maxX;
	int maxY;
	
	
	int range = (boost - bad) + 1;
	
	if (range < 0) {
		range = 0;
	}
	
	minX = xCoor - range;
	minY = yCoor - range;
	maxX = xCoor + range;
	maxY = yCoor + range;
	
	while (minX < 0) {
		minX++;
	}
	
	while (minY < 0) {
		minY++;
	}
	
	while (maxX >= m) {
		maxX--;
	
	}
	
	while (maxY >= n) {
		maxY--;
	
	}
	
	int i = 0;
	int a = minX;
	int b = minY;
	
	*numTiles = 0;
	
	while (b <= maxY) {
		while (a <= maxX) {
			int tile = (b*m) + a;
			*(adTiles + i) = tile;
			(*numTiles)++;
			i++;
			a++;
		}
		
		a = minX;
		b++;
	}
	

	processInput(adTiles, finalTiles, gameTiles, numTiles, n, m);

}


/* calculateScore calculates the score after each turn
*/
void calculateScore(int* input, int* inputSize, float* score, float* totScore, int* star, int* boost, int* bad, float* boardGame, int n, int m) {
	
	for (int i = 0; i < *inputSize; i++) {
		int checkIndex = *(input + i);
		
		if (*(boardGame + checkIndex) == 19.00) {
			
			(*star)++;
			
		}
		
		
		else if (*(boardGame + checkIndex) == 16.00) {
			
			(*boost)++;
			
		}
		
		
		else if (*(boardGame + checkIndex) == 17.00) {
			
			(*bad)++;
			
		}
		
		else {
		
			*score = *score + *(boardGame + checkIndex);
			
		}
		
	}
	
	
	*totScore = (*totScore) + (*score);
}


/* getNumberOfBombs calculates number of bombs at beginning of game
*	arguments: n, m
*	returns int
*/
int getNumberOfBombs(int n, int m) {
	int bombs = (n + m)/4;
	return bombs;
}

/* play commences the game, allowing user to quit at any point (and data will not be saved for this game)
*	Game ends if star is found, if out of lives and a negative score reached or out of bombs
*/
void play(float* boardGame, int* gameTiles, int n, int m, float* totalScore, int* quit) {
	float moveScore = 0;
	int playerLives = 3;
	int playerStar = 0;
	int playerBoost = 0;
	int playerBad = 0;
	int playerBombs = getNumberOfBombs(n, m);
	
	display(boardGame, gameTiles, moveScore, *totalScore, playerLives, playerStar, playerBoost, playerBad, playerBombs, n, m, 1);
	
	while ((playerLives >= 0 && playerStar == 0) && (playerBombs > 0)) {
			
		int userInput[2];
		getInput(userInput, gameTiles, n, m);
	
		if (*userInput == -1) {
			*quit = 1;
			printf("\nYou quit the game.\n");
			break;
		}	
		
		playerBombs--;
		
		int numAffectedFiles;
		int adjacentTiles[n*m];
		int finalTiles[n*m];
		
		getAdjacentTiles(userInput, adjacentTiles, finalTiles, gameTiles, &numAffectedFiles, playerBoost, playerBad, n, m);
		
		playerBoost = 0;
		playerBad = 0;
		
		calculateScore(finalTiles, &numAffectedFiles, &moveScore, totalScore, &playerStar, &playerBoost, &playerBad, boardGame, n, m);
		
		printf("\nTotal uncovered score of %.2f points.\n", moveScore);
		
	
		display(boardGame, gameTiles, moveScore, *totalScore, playerLives, playerStar, playerBoost, playerBad, playerBombs, n, m, 1);
		
		if ((playerBoost != 0) || (playerBad != 0)) {
		
			printf("You gained %d boosts.\n", playerBoost);
			printf("You gained %d blows.\n", playerBad);
		
			if ((playerBoost - playerBad) < 0) {
				printf("Next bomb range is 1 tile only.\n");
			}
		
			else {
				printf("Next bomb range is x %d\n", ((playerBoost - playerBad) + 1));
			}
		}
		
		moveScore = 0;
		
		if (playerStar == 1) {
			printf("\nYou found the exit tile! Congratulations, you won!\n");
			break;
		}
		
		else if (*totalScore < 0) {
			printf("\nYou lost a life.\n");
			printf("Resetting total score...\n");
			if (playerLives > 0) {
				playerLives--;
				*totalScore = 0;
				display(boardGame, gameTiles, moveScore, *totalScore, playerLives, playerStar, playerBoost, playerBad, playerBombs, n, m, 1);
				
			}
			
			else {
				printf("\nOut of lives. You've lost. Game over. \n");
				break;
			}
		}
		
		else if (playerBombs == 0) {
			printf("\nYou've lost. Out of bombs.\n");
			break;
		}
		
	}
	
}


/* initializeScoreSheet sets up log sheet if one does not yet exist
*/
void initializeScoreSheet(FILE* fileToWrite) {
	fprintf(fileToWrite, "Top scores for Bomberman game:\n\n\n");
	fprintf(fileToWrite, "Name                Score          Duration\n");
}


/* logScore logs player stats into log file at end of game
*/
void logScore(FILE* fileToWrite, char* name, float score, int duration) {
	int i = 0;
	while (*(name + i) != '\0') {
		i++;
	}
	
	int space = 20 - i;
	
	fprintf(fileToWrite, "%s", name);
	
	for (int j = 0; j < space; j++) {
		fprintf(fileToWrite, " ");
	}
	
	fprintf(fileToWrite, "%.2f         ", score);
	fprintf(fileToWrite, "%d\n", duration);

}


/* exitgame ends the game
*/
void exitGame(int quit, char* name, float totalScore, int duration) {
	if (quit == 0) {
		FILE* output = fopen("mygame.log", "a");
		logScore(output, name, totalScore, duration);
		fclose(output);
	}
	
	printf("Game over.\n");
}


/* console sets up the game to be played, such as setting up the boardGame, tiles, etc.
*/
void console(char* name, int n, int m) {	
	float boardGame[n][m];
	int gameTiles[n][m];
	
	initializeGame(*boardGame, *gameTiles, n, m);
	display(*boardGame, *gameTiles, 0, 0, 0, 0, 0, 0, 0, n, m, 0);
	
	float totalScore = 0.0;
	int quit = 0;
	
	int duration = 0.0;
	
	clock_t begin = clock();
	play(*boardGame, *gameTiles, n, m, &totalScore, &quit);
	clock_t end = clock();
	
	duration = (int) (((double) begin + ((double) (end-begin))/CLOCKS_PER_SEC)/100);
	
	exitGame(quit, name, totalScore, duration);
	
}


int getNumberRecords() {
	FILE* fileToCheck;
	fileToCheck = fopen("mygame.log", "r");
	
	if (fileToCheck == NULL) {
		return 0;
	}
	
	else {
		
		char string[20];
		char start[] = "Duration";
		
		while (fscanf(fileToCheck, "%s", string) != EOF) {
			if (strcmp(string, start) == 0) {
				break;
			}
		}
		
		int numStrings = 0;
		
		while (fscanf(fileToCheck, "%s", string) != EOF) {
			numStrings++;
		}
		
	
		rewind(fileToCheck);
		fclose(fileToCheck);
		return numStrings;
	
	}

}



void sort(int* topIndices, float* scores, int arrayLength, int n) {
	
	int sortedArray[arrayLength];
	
	for (int i = 0; i < arrayLength; i++) {
		*(sortedArray + i) = -1;
	}
	
	for (int i = 0; i < arrayLength; i++) {
		int compareIndex = i;
		float compareScore = *(scores + i);
		int numTimesBigger = 0;
		
		for (int j = 0; j < arrayLength; j++) {
			if (compareScore < *(scores + j)) {
				numTimesBigger++;
			}
		}
		
		int relativeLocation = numTimesBigger;
		
		int a = relativeLocation;
		
		while (a < arrayLength) {
			if (*(sortedArray + a) != -1) {
				a++;
			}
			
			else {
				break;
			}
		}
		
		*(sortedArray + a) = compareIndex;
	
	}
	
	
	for (int i = 0; i < n; i++) {
		*(topIndices + i) = *(sortedArray + i);
	}
}



void readLogData(char** names, float* scores, int* dur, int numString) {
	
	char* allStrings[numString];
	
	FILE* fileToCheck = fopen("mygame.log", "r");
    
    char newString[20];
    char reStar[] = "Duration";

	while (fscanf(fileToCheck, "%s", newString) != EOF) {
        if (strcmp(newString, reStar) == 0) {
        	break;
        }
    }
    
    int i = 0;

    while (fscanf(fileToCheck, "%s", newString) != EOF) {
        char* linkCopy = malloc(strlen(newString) + 1);
        strcpy(linkCopy, newString);
        *(allStrings + i) = malloc(strlen(linkCopy) + 1);
        strcpy(*(allStrings + i), linkCopy);
        free(linkCopy);
        i++;
    }
    
    
    i = 0;
	int j = 0;
	
	while (j < numString) {		
		*(names + i) = *(allStrings + j);
		*(scores + i) = atof(*(allStrings + j + 1));
		*(dur + i) = atoi(*(allStrings + j + 1 + 1));
		j = j + 3;
		i++;
	}
	

	fclose(fileToCheck);
	
}



void printScores(char** names, float* scores, int* dur, int* topIndices, int n) {
	printf("Name                Score       Duration\n");
	
	for (int i = 0; i < n; i++) {
		
		int rank = *(topIndices + i);
		
		int stringSpace = 21;
		int stringLength = strlen(*(names + rank));
		stringSpace = stringSpace - stringLength;
		char stringArray[stringSpace];
		
		for (int j = 0; j < stringSpace - 1; j++) {
			*(stringArray + j) = ' ';
		}
		
		*(stringArray + stringSpace - 1) = '\0';

	
		int floatSpace = 12;
		int floatLength = 0;
		
		if (*(scores + rank) >= 0) {
			floatLength = 3;
			int a = (int) *(scores + rank);
			
			a = a/10;
			
			while (a != 0) {
				a = a/10;
				floatLength++;
			}
		}
		
		else {
			floatLength = 4;
			
			int a = (int) *(scores + rank);
			a = a * -1;
			
			a = a/10;
			
			while (a != 0) {
				a = a/10;
				floatLength++;
			}
		
		}
		
		floatSpace = floatSpace - floatLength;
		char floatArray[floatSpace];
		
		for (int j = 0; j < floatSpace - 1; j++) {
			*(floatArray + j) = ' ';
		}
		
		*(floatArray + floatSpace - 1) = '\0';
		
		
		int intSpace = 8;
		int intLength = 1;
		
		int a = *(dur + rank);
		a = a/10;
		
		while (a != 0) {
			intLength++;
			a = a/10;
		}
		
		
		intSpace = intSpace - intLength;
		char intArray[intSpace];
		
		for (int j = 0; j < intSpace - 1; j++) {
			*(intArray + j) = ' ';
		}
		
		*(intArray + intSpace - 1) = '\0';
		
		
		printf("%s", *(names + rank));
		printf("%s", stringArray);
		printf("%.2f", *(scores + rank));
		printf("%s", floatArray);
		printf("%d", *(dur + rank));
		printf("%s\n", intArray);

	}

}



void displayTopScores(int n) {	
	int numString = getNumberRecords();
	
	if (numString == 0) {
		printf("No data yet. Play a game first.\n");
	}
	
	else if (n > (numString/3)) {
		printf("Not enough data to display that many matches. Play more games.\n");
	}

	else {

		char* names[numString/3];
		float scores[numString/3];
		int dur[numString/3];
		
		readLogData(names, scores, dur, numString);

		
		int arrayLength = numString/3;
		int topIndices[n];
		sort(topIndices, scores, arrayLength, n);

		
		printScores(names, scores, dur, topIndices, n);

	
	}
}


void scoreMenu() {
	printf("Enter top number of records. Enter 'back' to return to main menu.\n");
	char* num = (char*) calloc(20, sizeof(char));
	char goBack[10] = "back";
	scanf("%s", num);
				
	while (strcmp(num, goBack) != 0) {
		
		if (checkIfValidInteger(num) == 0) {
			printf("\nError. Invalid input. Please try again.\n");
			printf("Enter top number of records. Enter 'back' to return to main menu.\n");	
			free(num);
			num = (char*) calloc(20, sizeof(char));
			scanf("%s", num);
		}
				
		else if (atoi(num) <= 0) {
			printf("\nError. Please enter a number larger than 0.\n");
			printf("Enter top number of records. Enter 'back' to return to main menu.\n");	
			free(num);
			num = (char*) calloc(20, sizeof(char));
			scanf("%s", num);
		}
					
		else if (atoi(num) > getNumberRecords()){
			printf("\nNot enough games played to display that number of records.\n");
			printf("Enter top number of records. Enter 'back' to return to main menu.\n");		
			free(num);
			num = (char*) calloc(20, sizeof(char));
			scanf("%s", num);
		}
		
		else {
			printf("\n");
			displayTopScores(atoi(num));
			printf("\nEnter top number of records. Enter 'back' to return to main menu.\n");		
			free(num);
			num = (char*) calloc(20, sizeof(char));
			scanf("%s", num);
			
		}		
	}
}


/* Main method checks if arguments passed by user in command line are valid, 
*	and gives user the option to run game as many times
*	Arguments: int argc, char *argv[]
*	Method returns void
*/
int main(int argc, char* argv[]) {

	if (argc != 4) {
		printf("\nError. Invalid number of command line arguments.\n");
		exit(0);
	}
	
	else if (checkIfValidString(argv[1]) == 0) {
		printf("\nError. You must enter a valid name.\n");
		exit(0);
	}
	
	else if (checkIfValidInteger(argv[2]) == 0) {
		printf("\nError. Must enter integer for number of rows.\n");
		exit(0);
	}
	
	else if (checkIfValidInteger(argv[2]) == 0) {
		printf("\nError. Must enter integer for number of columns.\n");
		exit(0);
	}
	
	else if (atoi(argv[2]) < 10) {
		printf("\nError. Minimum of 10 rows required.\n");
		exit(0);
	}
	
	else if (atoi(argv[3]) < 10) {
		printf("\nError. Minimum of 10 columns required.\n");
		exit(0);
	}
	
	else if (atoi(argv[3]) > 100) {
		printf("\nError. Maximum of 100 columns to fit screen.\n");
		exit(0);
	}
	
	char* name = argv[1];
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);	
	time_t t;
	srand((unsigned) time(&t));	
	
	int start = 1;
	
	FILE* output;
	FILE *fileToRead = fopen("mygame.log", "r");			
	
	if (fileToRead != NULL) {
		fclose(fileToRead);
	}
	
	else {
		output = fopen("mygame.log", "w");
		initializeScoreSheet(output);
		fclose(output);
	}
	
	int programTerminate = 0;
	
	while (programTerminate != 1) {
		printf("\nWelcome to Bomberman, %s! What would you like to do?\n", argv[1]);
		printf("To see top scores, enter 'see'.\n");
		printf("To play, enter 'play'.\n");
		printf("To exit, enter 'exit'.\n\n");
	
		char* userOption = (char*) calloc(20, sizeof(char));
		char seeOption[] = "see";
		char playOption[] = "play";
		char exitOption[] = "exit";
	
		scanf("%s", userOption);
	
		while (((strcmp(userOption, seeOption) != 0) && (strcmp(userOption, playOption) != 0)) 
			&& (strcmp(userOption, exitOption) != 0)) {
			printf("\nInvalid option.\n");
			printf("To see top scores, enter 'see'.\n");
			printf("To play, enter 'play'.\n");
			printf("To exit, enter 'exit'.\n");
		
			free(userOption);
			userOption = (char*) calloc(20, sizeof(char));
			scanf("%s", userOption);
		}
	

		if (strcmp(userOption, exitOption) == 0) {
			programTerminate = 1;
			exit(0);
		}
	
		else if (strcmp(userOption, playOption) == 0) {
			console(name, n, m);
		}
	
		else {
			scoreMenu();
		}
	}
	
	
	return 1;

}
