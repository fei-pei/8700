/**************************************************************************************************/
/*  FILE NAME             :  TTTController.h                                                      */
/*  PRINCIPAL AUTHOR      :  Fei Pei                                                              */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  Controller                                                           */
/*  LANGUAGE              :  C++                                                                  */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2016/08/08                                                           */
/*  DESCRIPTION           :  This is a controller of MVC                                          */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by PeiFei, 2016/08/08
 *
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "../model/Model.h"


using namespace std;

class TTTController{
    private:
        Board board;
        Player player1;
        Player player2;
    public:
        TTTController();
        ~TTTController();
        void createPlayer(string name, string marker, int playerNum);
        string getPlayerName(int playerNum);
        void startNewGame();
        bool setSelection(int row, int col, int currentPlayer);
        // row and col: have to be valid, between 0-2
        // currentPlayer: 1=player1; 2=player2
        //return bool: valid and available location
        int determineWinner();
        //return winner;
        //0= no winner; 1=player1; 2=player2; 3=tie/no more available locations
        string getGameDisplay();
        //printable display of current selections;
        //shows each players marker
};
#endif
