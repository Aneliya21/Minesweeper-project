#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>  
#include <time.h>

/**
*
* Solution to course project # <номер на вариант>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author <Aneliya Kadilarova>
* @idnumber <5MI0600230>
* @compiler <VC>
*
* <Minesweeper - all funcionalities>
*
*/

using namespace std;

//dynamic matrix functions
char** createTable(int sizeOfField) {
    char** matrix;
    matrix = new char* [sizeOfField];
    for (size_t i = 0; i < sizeOfField; i++) {
        matrix[i] = new char[sizeOfField];
    }
    for (size_t i = 0; i < sizeOfField; i++) {
        for (size_t y = 0; y < sizeOfField; y++) {
            matrix[i][y] = NULL;
        }
    }
    return matrix;
}
void generateGameBoard(char** matrix, char value, int sizeOfField) {
    for (int row = 0; row < sizeOfField; row++) {
        for (int col = 0; col < sizeOfField; col++) {
            matrix[row][col] = value;
        }
    }
}
void printMatrix(char** matrix, int sizeOfFIeld) {
    cout << endl;
    for (int row = 0; row < 1; row++) {
        cout << setw(10);
        for (int col = 0; col < sizeOfFIeld; col++) {
            cout << col << "      ";
        }
    }
    cout << endl; 

    cout << setw(7);
    for (int row = 0; row < sizeOfFIeld * 7; row++) {
        cout << "_";
    }
    cout << endl << endl; 

    for (int row = 0; row < sizeOfFIeld; row++) {
        cout << setw(3) << row << " | ";
        for (int col = 0; col < sizeOfFIeld; col++)  {
            cout << "   " << matrix[row][col] << "   ";
        }
        cout << endl << endl;
    }
}
void deleteMatrix(char** matrix, int sizeOfField) {
    for (int i = 0; i < sizeOfField; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//check for mine on coordiantes
bool checkForMine(char** matrix, int sizeOfField, int i, int j) {
    if (matrix[i][j] == '#') {
        return true;
    }
    else if (matrix[i][j] != '#') {
        return false;
    }
}

//generate random mines on hidden board (generate random coordinates to put mine on)
void generateRandomMines(char** matrix, int sizeOfField, int numberOfMines) {
    int xCoordinate, yCoordinate;
    srand(time(0));
    for (int i = 0; i <= numberOfMines - 1; i++) {
        xCoordinate = rand() % sizeOfField;
        yCoordinate = rand() % sizeOfField;
        while (checkForMine(matrix, sizeOfField, xCoordinate, yCoordinate)) {
            xCoordinate = rand() % sizeOfField;
            yCoordinate = rand() % sizeOfField;
        }
        matrix[xCoordinate][yCoordinate] = '#';
    }
}

//validation for coordinates
bool areCoordValid(int x, int y, int sizeOfField) {
    if (x >= 0 && x < sizeOfField && y >= 0 && y < sizeOfField) {
        return true;
    }
    else {
        return false; }
}

//find up Coordinates
int XupCoordinate(int row, int col) {
    int XupIndex = row - 1;
    return XupIndex;
}
int YupCoordinate(int row, int col) {
    int YupIndex = col;
    return YupIndex;
}

//find down Coordinates
int XdownCoordinate(int row, int col) {
    int XdownIndex = row + 1;
    return XdownIndex;
}
int YdownCoordinate (int row, int col){
    int YdownIndex = col;
    return YdownIndex;
}

//find left Coordinates
int XleftCoordinate(int row, int col) {
    int XleftIndex = row;
    return XleftIndex;
}
int YleftCoordinate(int row, int col) {
    int YleftIndex = col - 1;
    return YleftIndex;
}

//find right Coordinates
int XrightCoordinate(int row, int col) {
    int XrightIndex = row;
    return XrightIndex;
}
int YrightCoordinate(int row , int col) {
    int YrightIndex = col + 1;
    return YrightIndex;
}

//find upLeftDiagonal Coordinates
int XupLeftDiagonal(int row, int col) {
    int XcordUpLeftDiagonal = row - 1;
    return XcordUpLeftDiagonal;
}
int YupLeftDiagonal(int row, int col){
    int YcordUpLeftDiagonal = col - 1;
    return YcordUpLeftDiagonal;
}

//find upRightDiagonal Coordinates
int XupRightDiagonal(int row, int col) {
    int XcordUpRightDiagonal = row - 1;
    return XcordUpRightDiagonal;
}
int YupRightDiagonal(int row, int col) {
    int YcordUpRightDiagonal = col + 1;
    return YcordUpRightDiagonal;
}

//find downLeftDiagonal Coordinates
int XdownLeftDiagonal(int row, int col) {
    int XcordDownLeftDiagonal = row + 1;
    return XcordDownLeftDiagonal;
}
int YdownLeftDiagonal(int row, int col) {
    int YcordDownLeftDiagonal = col - 1;
    return YcordDownLeftDiagonal;
}

//find downRightDiagonal Coordinates
int XdownRightDiagonal(int row, int col) {
    int XcordDownRightDiagonal = row + 1;
    return XcordDownRightDiagonal;
}
int YdownRightDiagonal(int row, int col){
    int YcordDownRightDiagonal = col + 1;
    return YcordDownRightDiagonal;
}

//find count of mines arount the square
char findCountOfSurroundingMines(char** matrix, int sizeOfField, int row, int col ) {
    int countOfMines = '0';

    //upCoordinates
    int XupIndex = XupCoordinate(row, col);
    int YupIndex = YupCoordinate(row, col);
    //downCoordinates
    int XdownIndex = XdownCoordinate(row, col);
    int YdownIndex = YdownCoordinate(row, col);
    //leftCoordinates
    int XleftIndex = XleftCoordinate(row, col);
    int YleftIndex = YleftCoordinate(row, col);
    //rightCoordinates
    int XrightIndex = XrightCoordinate(row, col);
    int YrightIndex = YrightCoordinate(row, col);
    //upLeftDiagonal coordinates
    int XcordUpLeftDiagonal = XupLeftDiagonal(row, col);
    int YcordUpLeftDiagonal = YupLeftDiagonal(row, col);
    //upRightDiagonal coordinates
    int XcordUpRightDiagonal = XupRightDiagonal(row, col);
    int YcordUpRightDiagonal = YupRightDiagonal(row, col);
    //downLeftDiagonal coordinates
    int XcordDownLeftDiagonal = XdownLeftDiagonal(row, col);
    int YcordDownLeftDiagonal = YdownLeftDiagonal(row, col);
    //downRightDiagonal coordinates
    int XcordDownRightDiagonal = XdownRightDiagonal(row, col);
    int YcordDownRightDiagonal = YdownRightDiagonal(row, col);

    //checkForMine Up 
    if (areCoordValid(XupIndex, YupIndex, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XupIndex, YupIndex)) {
            countOfMines++;
        }
    }

    //checkForMine Down
    if (areCoordValid(XdownIndex, YdownIndex, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XdownIndex, YdownIndex)) {
            countOfMines++;
        }
    }

    //checkForMine Left
    if (areCoordValid(XleftIndex, YleftIndex, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XleftIndex, YleftIndex)) {
            countOfMines++;
        }
    }

    //checkForMine Right
    if (areCoordValid(XrightIndex, YrightIndex, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XrightIndex, YrightIndex)) {
            countOfMines++;
        }
    }

    //checkForMine UpLeftDiag
    if (areCoordValid(XcordUpLeftDiagonal, YcordUpLeftDiagonal, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XcordUpLeftDiagonal, YcordUpLeftDiagonal)) {
            countOfMines++;
        }
    }

    //checkForMine UpRightDiag
    if (areCoordValid(XcordUpRightDiagonal, YcordUpRightDiagonal, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XcordUpRightDiagonal, YcordUpRightDiagonal)) {
            countOfMines++;
        }
    }

    //checkForMine DownLeftDiag
    if (areCoordValid(XcordDownLeftDiagonal, YcordDownLeftDiagonal, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XcordDownLeftDiagonal, YcordDownLeftDiagonal)) {
            countOfMines++;
        }
    }

    //checkForMIne DownRightDiag
    if (areCoordValid(XcordDownRightDiagonal, YcordDownRightDiagonal, sizeOfField)) {
        if (checkForMine(matrix, sizeOfField, XcordDownRightDiagonal, YcordDownRightDiagonal)) {
            countOfMines++;
        }
    }

    return countOfMines;
}

//put count of mines on each square of the hiddenGameBoard
void putCountOfMines(char** matrix, int sizeOfField) {
    for (int row = 0; row < sizeOfField; row++) {
        for (int col = 0; col < sizeOfField; col++) {
            if (checkForMine(matrix, sizeOfField, row, col) == false) {
                matrix[row][col] = findCountOfSurroundingMines(matrix, sizeOfField, row, col);
            }
        }
    }
}

//check if square is number
bool isItNumber(char** matrix, int sizeOfField, int userInputForX, int userInputForY) {
            if (matrix[userInputForX][userInputForY] > '0' && matrix[userInputForX][userInputForY] <= '8') {
                return true;
            }
            else {
                return false;
            }
}

//check if square is null
bool isItNull(char** matrix, int sizeOfField, int userInputForX, int userInputForY) {
            if (matrix[userInputForX][userInputForY] == '0') {
                return true;
            }
            else {
                return false;
            }
}

//check if square is revelaed
bool isItRevealed(char** playBoard, int x, int y) {
    if (playBoard[x][y] != '_') {
        return true;
    }
    else {
        return false;
    }
}

//open command
void openCommand(char** playBoard, char** hiddenBoard, int sizeOfField, char command, int userInputForX, int userInputForY) {
    if (command == 'o') {
        
        //NOT MINE COORDINATES
        if (!checkForMine(hiddenBoard, sizeOfField, userInputForX, userInputForY)) {
            playBoard[userInputForX][userInputForY] = hiddenBoard[userInputForX][userInputForY];
            //upCords
            int XupCord = XupCoordinate(userInputForX, userInputForY);
            int YupCord = YupCoordinate(userInputForX, userInputForY);
            //downCords
            int XdownCord = XdownCoordinate(userInputForX, userInputForY);
            int YdownCord = YdownCoordinate(userInputForX, userInputForY);
            //leftCords
            int XleftCord = XleftCoordinate(userInputForX, userInputForY);
            int YleftCord = YleftCoordinate(userInputForX, userInputForY);
            //rightCords
            int XrightCord = XrightCoordinate(userInputForX, userInputForY);
            int YrightCord = YrightCoordinate(userInputForX, userInputForY);
            //upLeftDiagCords
            int XupLeftDiagCord = XupLeftDiagonal(userInputForX, userInputForY);
            int YupLeftDiagCord = YupLeftDiagonal(userInputForX, userInputForY);
            //upRightDiagCords
            int XupRightDiagCord = XupRightDiagonal(userInputForX, userInputForY);
            int YupRightDiagCord = YupRightDiagonal(userInputForX, userInputForY);
            //downLeftDiagCords
            int XdownLeftDiagCord = XdownLeftDiagonal(userInputForX, userInputForY);
            int YdownLeftDiagCord = YdownLeftDiagonal(userInputForX, userInputForY);
            //downRightDiagCords
            int XdownRightDiagCord = XdownRightDiagonal(userInputForX, userInputForY);
            int YdownRightDiagCord = YdownRightDiagonal(userInputForX, userInputForY);

            //if value of inputCoordinates is Null
            if (isItNull(hiddenBoard, sizeOfField, userInputForX, userInputForY)) {

                //up
                if (areCoordValid(XupCord, YupCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XupCord, YupCord)) {
                        //check if upCoordinates value is null
                        if (isItNull(hiddenBoard, sizeOfField, XupCord, YupCord)) {
                            //give null value to upCoordinates
                            playBoard[XupCord][YupCord] = hiddenBoard[XupCord][YupCord];
                            //call same command for the new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XupCord, YupCord);
                        }
                        //check if upCoordinates value is number
                        else if (isItNumber(hiddenBoard, sizeOfField, XupCord, YupCord)) {
                            playBoard[XupCord][YupCord] = hiddenBoard[XupCord][YupCord];
                        }
                        //check if upCoordinates value is bomb
                        else if (checkForMine(hiddenBoard, sizeOfField, XupCord, YupCord)) {
                            //keep it hidden
                            break;
                        }

                    }

                }

                //down
                if (areCoordValid(XdownCord, YdownCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XdownCord, YdownCord)) {
                        //check if downCoordinates value is null
                        if (isItNull(hiddenBoard, sizeOfField, XdownCord, YdownCord)) {
                            //give null value to downCoordinates
                            playBoard[XdownCord][YdownCord] = hiddenBoard[XdownCord][YdownCord];
                            //call same command for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XdownCord, YdownCord);
                        }
                        //check if downCoordinates value is number
                        else if (isItNumber(hiddenBoard, sizeOfField, XdownCord, YdownCord)) {
                            playBoard[XdownCord][YdownCord] = hiddenBoard[XdownCord][YdownCord];
                        }
                        //check if downCoordinates value is bomb
                        else if (checkForMine(hiddenBoard, sizeOfField, XdownCord, YdownCord)) {
                            //keep it hidden
                            break;
                        }
                    }
                }

                //left
                if (areCoordValid(XleftCord, YleftCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XleftCord, YleftCord)) {
                        //check if leftCoordinates value is null
                        if (isItNull(hiddenBoard, sizeOfField, XleftCord, YleftCord)) {
                            //give null value to leftCoordinates
                            playBoard[XleftCord][YleftCord] = hiddenBoard[XleftCord][YleftCord];
                            //call same command for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XleftCord, YleftCord);
                        }
                        //check if leftCoordinates value is number
                        else if (isItNumber(hiddenBoard, sizeOfField, XleftCord, YleftCord)) {
                            playBoard[XleftCord][YleftCord] = hiddenBoard[XleftCord][YleftCord];
                        }
                        //check if leftCoordinates value is bomb
                        else if (checkForMine(hiddenBoard, sizeOfField, XleftCord, YleftCord)) {
                            //keep it hidden
                            break;
                        }
                    }
                }

                //right
                if (areCoordValid(XrightCord, YrightCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XrightCord, YrightCord)) {
                        //check if rightCoordines value is null
                        if (isItNull(hiddenBoard, sizeOfField, XrightCord, YrightCord)) {
                            //give null value to rightCoordinates
                            playBoard[XrightCord][YrightCord] = hiddenBoard[XrightCord][YrightCord];
                            //call same command for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XrightCord, YrightCord);
                        }
                        //check if rightCoordinates value is number
                        else if (isItNumber(hiddenBoard, sizeOfField, XrightCord, YrightCord)) {
                            playBoard[XrightCord][YrightCord] = hiddenBoard[XrightCord][YrightCord];
                        }
                        else if (checkForMine(hiddenBoard, sizeOfField, XrightCord, YrightCord)) {
                            //keep if hidden
                            break;
                        }
                    }
                }

                //upLeftDiagCord
                if (areCoordValid(XupLeftDiagCord, YupLeftDiagCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XupLeftDiagCord, YupLeftDiagCord)) {
                        //check if upLeftDiagCoordinates value is null
                        if (isItNull(hiddenBoard, sizeOfField, XupLeftDiagCord, YupLeftDiagCord)) {
                            //give null value to upLeftDiagCoordinates
                            playBoard[XupLeftDiagCord][YupLeftDiagCord] = hiddenBoard[XupLeftDiagCord][YupLeftDiagCord];
                            //call same command for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XupLeftDiagCord, YupLeftDiagCord);
                        }
                        else if (isItNumber(hiddenBoard, sizeOfField, XupLeftDiagCord, YupLeftDiagCord)) {
                            playBoard[XupLeftDiagCord][YupLeftDiagCord] = hiddenBoard[XupLeftDiagCord][YupLeftDiagCord];
                        }
                        else if (checkForMine(hiddenBoard, sizeOfField, XupLeftDiagCord, YupLeftDiagCord)) {
                            //keep it hidden
                            break;
                        }
                    }
                }

                //upRightDiagCord
                if (areCoordValid(XupRightDiagCord, YupRightDiagCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XupRightDiagCord, YupRightDiagCord)) {
                        //check if upRightDiagCoordinates value is null
                        if (isItNull(hiddenBoard, sizeOfField, XupRightDiagCord, YupRightDiagCord)) {
                            //give null value to upRightDiagCoordinates
                            playBoard[XupRightDiagCord][YupRightDiagCord] = hiddenBoard[XupRightDiagCord][YupRightDiagCord];
                            //call same command for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XupRightDiagCord, YupRightDiagCord);
                        }
                        else if (isItNumber(hiddenBoard, sizeOfField, XupRightDiagCord, YupRightDiagCord)) {
                            playBoard[XupRightDiagCord][YupRightDiagCord] = hiddenBoard[XupRightDiagCord][YupRightDiagCord];
                        }
                        else if (checkForMine(hiddenBoard, sizeOfField, XupRightDiagCord, YupRightDiagCord)) {
                            //keep it hidden
                            break;
                        }
                    }
                }

                //downLeftDiagCord
                if (areCoordValid(XdownLeftDiagCord, YdownLeftDiagCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XdownLeftDiagCord, YdownLeftDiagCord)) {
                        //check if downLeftDiagCoordinates value is null
                        if (isItNull(hiddenBoard, sizeOfField, XdownLeftDiagCord, YdownLeftDiagCord)) {
                            //give null value to downLeftDiagCoordinates
                            playBoard[XdownLeftDiagCord][YdownLeftDiagCord] = hiddenBoard[XdownLeftDiagCord][YdownLeftDiagCord];
                            //call same command for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XdownLeftDiagCord, YdownLeftDiagCord);
                        }
                        else if (isItNumber(hiddenBoard, sizeOfField, XdownLeftDiagCord, YdownLeftDiagCord)) {
                            playBoard[XdownLeftDiagCord][YdownLeftDiagCord] = hiddenBoard[XdownLeftDiagCord][YdownLeftDiagCord];
                        }
                        else if (checkForMine(hiddenBoard, sizeOfField, XdownLeftDiagCord, YdownLeftDiagCord)) {
                            //keep it hidden
                            break;
                        }
                    }
                }

                //downRightCord
                if (areCoordValid(XdownRightDiagCord, YdownRightDiagCord, sizeOfField)) {
                    while (!isItRevealed(playBoard, XdownRightDiagCord, YdownRightDiagCord)) {
                        //check if downRightDiagCoordinates value is nul
                        if (isItNull(hiddenBoard, sizeOfField, XdownRightDiagCord, YdownRightDiagCord)) {
                            //give null value to downRightDiagCooridnates
                            playBoard[XdownRightDiagCord][YdownRightDiagCord] = hiddenBoard[XdownRightDiagCord][YdownRightDiagCord];
                            //call same comand for new Null
                            openCommand(playBoard, hiddenBoard, sizeOfField, command, XdownRightDiagCord, YdownRightDiagCord);
                        }
                        else if (isItNumber(hiddenBoard, sizeOfField, XdownRightDiagCord, YdownRightDiagCord)) {
                            playBoard[XdownRightDiagCord][YdownRightDiagCord] = hiddenBoard[XdownRightDiagCord][YdownRightDiagCord];
                        }
                        else if (checkForMine(hiddenBoard, sizeOfField, XdownRightDiagCord, YdownRightDiagCord)) {
                            //keep it hidden
                            break;
                        }
                    }
                }
            }
            //if user input is Number
            else if (isItNumber(hiddenBoard, sizeOfField, userInputForX, userInputForY)) {
                playBoard[userInputForX][userInputForY] = hiddenBoard[userInputForX][userInputForY];
            }
        }
    }
}

//check if square is marked
bool isItMarked(char** playBoard, int sizeOfField, int userInputForX, int userInputForY) { 
            if (playBoard[userInputForX][userInputForY] == '+') {
                return true;
            }
            else {
                return false;
            }      
}

//mark command
void markCommand(char** playBoard, int sizeOfField, char userInput, int userInputForX, int userInputForY) {
    if (isItMarked(playBoard, sizeOfField, userInputForX, userInputForY) == false) {
        if (userInput == 'm' || userInput == 'M') {
            playBoard[userInputForX][userInputForY] = '+';
        }
    }
    else {
        cout << endl << endl;
        cout << " >> This square is alread marked! Try to mark another one! ";
        cout << endl << endl;
    }
}

//find count of marked squares to WIN
int countOfMarked(char** playBoard, int sizeOfField, int x, int y) {
    if (isItMarked(playBoard, sizeOfField, x, y) == true) {
        int count = 0;
        for (int row = 0; row < sizeOfField; row++) {
            for (int col = 0; col < sizeOfField; col++) {
                if (playBoard[row][col] == '+') {
                    count++;
                }
                else {
                    continue;
                }
            }
        }
        return count;
    }
}

//unmark command
void unmarkCommand(char** playBoard, int sizeOfField, char userInput, int userInputForX, int userInputForY) {
    if (userInput == 'u' || userInput == 'U') {
        if (isItMarked(playBoard, sizeOfField, userInputForX, userInputForY)  == true) {
            playBoard[userInputForX][userInputForY] = '_';
        }
        else {
            cout << endl << endl;
            cout << "You can unmark only marked squares! Try again with another comand or coordinates! ";
            cout << endl<<endl;
        }
    }
}

//find count of needed open squares to WIN
int countOfNeededOpenSquares(char** playBoard, int sizeOfField, int numberOfMines) {
    int numberOfAllSquares = sizeOfField * sizeOfField;
    int res = numberOfAllSquares - numberOfMines;
    return res;
}

//find count of opened squares
int countOfOpenedSquaresByTheUser(char** playBoard, int sizeOfField) {
    int count = 0;
    for (int row = 0; row < sizeOfField; row++) {
        for (int col = 0; col < sizeOfField; col++) {
            if (isItRevealed(playBoard, row, col)) {
                count++;
            }
            else {
                continue;
            }
        }
    }
    return count;
}

//check if user has opened all squares (which are not mine)
bool isCountOfOpenedSquaresReached(char** playBoard, int sizeOfField, int numberOfMines) {
    if (countOfOpenedSquaresByTheUser(playBoard, sizeOfField) == countOfNeededOpenSquares(playBoard, sizeOfField, numberOfMines)) {
        return true;
    }
    else {
        return false;
    }
}

//check if user has marked all bombs
bool isCountOfMarkedReached(char** playBoard, int sizeOfField, int numberOfMines, int x, int y) {
    if (countOfMarked(playBoard, sizeOfField, x, y) == numberOfMines) {
        return true;
    }
    else {
        return false;
    }
}

//continue playing
bool doYouWantToPlayMore(char userAnswer) {
    if (userAnswer == 'y') {
        return true;
    }
    else if (userAnswer == 'n') {
        return false;
    }
}

int main() {

    while (true) {
        //choose difficulty level
        cout << "----<<< MINESWEEPER GAME >>>----" << endl << endl;
        cout << ">> Choose difficulty level from 3 to 10." << endl << endl;
        int sizeOfField;
        cout << "Difficulty level: ";
        cin >> sizeOfField;

        //invalid input case
        while (sizeOfField < 3 || sizeOfField > 10) {
            cout << endl;
            cout << "----You entered wrong input!----" << endl;
            cout << "Try again. >>" << endl << endl;
            cout << ">> Choose difficulty level from 3 to 10." << endl << endl;
            cout << "Difficulty level: ";
            cin >> sizeOfField;
        }

        //choose number of mines
        cout << endl;
        cout << ">> Now, choose number of hidden mines!" << endl << endl;
        int maxNumberOfMines = 3 * sizeOfField;
        int minesInput;
        cout << "Enter number of hidden mines: ";
        cin >> minesInput;
        cout << endl;

        //invalid number of mines case
        while (minesInput < 1 || minesInput > maxNumberOfMines) {
            cout << endl;
            cout << "----You entered unexisting number of mines!----" << endl;
            cout << "Try again. >>" << endl << endl;
            cout << ">> Now, choose angain number of hidden mines!" << endl << endl;
            cout << "Enter number of hidden mines: ";
            cin >> minesInput;
            cout << endl;
        }

        //create hiddenGameBoard and gameBoard
        char** hiddenGameBoard = createTable(sizeOfField);
        char** gameBoard = createTable(sizeOfField);
        generateGameBoard(hiddenGameBoard, '_', sizeOfField);
        generateGameBoard(gameBoard, '_', sizeOfField);

        //print gameBoard
        printMatrix(gameBoard, sizeOfField);

        //generate random mines on hidden board
        generateRandomMines(hiddenGameBoard, sizeOfField, minesInput);

        //put count of surrounding mines on hidden board
        putCountOfMines(hiddenGameBoard, sizeOfField);

        bool openedSquares = false;
        bool markedSquares = false;
        bool doYouWantToPlayAgain = false;

        //comands input:
        while (true) {
            int xCoordinate = 0;
            int yCoordinate = 0;
            char command;

            cout << endl << endl;
            cout << ">> PRESS: " << endl;
            cout << "(o) to OPEN a square, " << endl << "(m) to MARK as suspected mine, "
                << endl << "(u) to UNMARK suspected mine. " << endl;
            cout << endl << "HINT: Command should be olny ONE letter!" << endl << "Enter command: >>" << endl;
            cin >> command;
            //command validation
            while (command != 'o' && command != 'm' && command != 'u') {
                cout << "----You entered wrong command!----" << endl;
                cout << "Try again with another command >> " << endl;
                cin >> command;
            }

            cout << endl << endl << "Enter coordinates to open square: " << endl << endl;
            cout << "row: ";
            cin >> xCoordinate;

            cout << endl;

            cout << "col: ";
            cin >> yCoordinate;

            //'x' and 'y' validation
            if (!areCoordValid(xCoordinate, yCoordinate, sizeOfField)) {
                cout << endl << "----Invalid coordinates!----" << endl << endl;
                cout << "Try to enter command and coordinates again >> " << endl << endl;
                continue;
            }
            else if (isItRevealed(gameBoard, xCoordinate, yCoordinate)) {
                cout << endl << ">>It has already been revealed!" << endl << endl;
                cout << "Try to enter command and coordinates again >> " << endl << endl;
                continue;
            }

            //open square command
            if (command == 'o') {
                if (checkForMine(hiddenGameBoard, sizeOfField, xCoordinate, yCoordinate)) {
                    for (int row = 0; row < sizeOfField; row++) {
                        for (int col = 0; col < sizeOfField; col++) {
                            //game over case
                            if (checkForMine(hiddenGameBoard, sizeOfField, row, col)) {
                                gameBoard[row][col] = hiddenGameBoard[row][col];
                            }
                        }
                    }
                    printMatrix(gameBoard, sizeOfField);
                    cout << endl << "---- GAME OVER! ): ----" << endl;

                    char userAnswer;
                    cout << endl << "Do you want to play again? " << endl;
                    cout << ">>PRESS " << endl << "(y) for 'yes' " << endl << "(n) for 'no' " << endl;
                    cout << ">> ";
                    cin >> userAnswer;
                    cout << endl;
                    if (doYouWantToPlayMore(userAnswer)) {
                        doYouWantToPlayAgain = true;
                        break;
                    }
                    else if (!doYouWantToPlayMore(userAnswer)) {
                        doYouWantToPlayAgain = false;
                        break;
                    }                   

                    break;
                }
                openCommand(gameBoard, hiddenGameBoard, sizeOfField, command, xCoordinate, yCoordinate);
                printMatrix(gameBoard, sizeOfField);

                cout << endl << "-> Number of revealed squares >> " << countOfOpenedSquaresByTheUser(gameBoard, sizeOfField) << endl;
                int leftToOpen = ((sizeOfField * sizeOfField) - (countOfOpenedSquaresByTheUser(gameBoard, sizeOfField)) - minesInput);
                cout << endl << leftToOpen << " more left to reveal. " << endl;

                //check if all squares are opened
                if (isCountOfOpenedSquaresReached(gameBoard, sizeOfField, minesInput)) {
                    openedSquares = true;
                }
            }

            //mark square command
            else if (command == 'm') {
                markCommand(gameBoard, sizeOfField, command, xCoordinate, yCoordinate);
                printMatrix(gameBoard, sizeOfField);

                cout << endl << "-> Count of marked squares >> " << countOfMarked(gameBoard, sizeOfField, xCoordinate, yCoordinate) << endl;;
                int leftToMark = minesInput - countOfMarked(gameBoard, sizeOfField, xCoordinate, yCoordinate);
                cout << endl << leftToMark << " more left to mark. " << endl;

                //check if all mines are marked
                if (isCountOfMarkedReached(gameBoard, sizeOfField, minesInput, xCoordinate, yCoordinate)) {
                    markedSquares = true;
                }
            }

            //unmark square command
            else if (command == 'u') {
                unmarkCommand(gameBoard, sizeOfField, command, xCoordinate, yCoordinate);
                printMatrix(gameBoard, sizeOfField);
            }

            //win case
            if (openedSquares == true && markedSquares == true) {
                if (markedSquares == true && openedSquares == true) {
                    cout << endl << " ----<< YOU WIN!!! >>---- " << endl << endl;

                    char userAnswer;
                    cout << endl << "Do you want to play again? " << endl;
                    cout << ">>PRESS " << endl << "(y) for 'yes' " << endl << "(n) for 'no' " << endl;
                    cout << ">> ";
                    cin >> userAnswer;
                    cout << endl;
                    if (doYouWantToPlayMore(userAnswer)) {
                        doYouWantToPlayAgain = true;
                        break;
                    }
                    else if (!doYouWantToPlayMore(userAnswer)) {
                        doYouWantToPlayAgain = false;
                        break;
                    }
                }
            }
        }
        //delete both boards
        deleteMatrix(gameBoard, sizeOfField);
        deleteMatrix(hiddenGameBoard, sizeOfField);
        if (!doYouWantToPlayAgain) {
            break;
        }
        else {
            continue;
        }
    }
}

