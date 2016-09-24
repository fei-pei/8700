/**************************************************************************************************/
/*  FILE NAME             :  TTTController.cpp                                                    */
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

#include <string>
#include <iostream>
#include "TTTController.h"
#include "../model/Model.h"

using namespace std;
//private Board board;
//Player player1;
//Player player2;



    TTTController::TTTController(){};
    TTTController::~TTTController(){};
    //set players' propety
    void TTTController::createPlayer(string name, string marker, int playerNum=1){
        if(playerNum==1){
            player1.setId(playerNum);
            player1.setMarker(marker);
            player1.setName(name);
        }
        else{
            player2.setId(playerNum);
            player2.setMarker(marker);
            player2.setName(name);
        }
    };

    string TTTController::getPlayerName(int playerNum){
        if(playerNum==1){
            return player1.getName();
        }
        else{
            return player2.getName();
        }
    }

    //clean the board
    void TTTController::startNewGame(){
        int newBoard[9] = {0};
        board.setBoard(newBoard);

    };
    // row and col: have to be valid, between 0-2
    // currentPlayer: 1=player1; 2=player2
    //return bool: valid and available location
    bool TTTController::setSelection(int row, int col, int currentPlayer){
        int *curboard = board.getBoard();
        if(row>2||row<0||col>2||col<0){
            return false;
        }
        if(curboard[row*3+col]!=0){
            return false;
        }
        else{
            curboard[row*3+col]=currentPlayer;
            board.setBoard(curboard);
            return true;
        }
    };
    //return winner;
    //0= no winner; 1=player1; 2=player2; 3=tie/no more available locations
    int TTTController::determineWinner(){
		int *curboard=board.getBoard();
        int full=0;
        for(int i=0;i<9;i++){
            if(curboard[i]!=0){
                ++full;
            }
        }
        if(full==9){
            return 3;
        }
        if(curboard[0]==curboard[1]&&curboard[1]==curboard[2]&&curboard[0]!=0)
		{
			return curboard[0];
		}
		if(curboard[3]==curboard[4]&&curboard[4]==curboard[5]&&curboard[3]!=0)
		{
			return curboard[3];
		}
		if(curboard[6]==curboard[7]&&curboard[7]==curboard[8]&&curboard[6]!=0)
		{
			return curboard[6];
		}
		if(curboard[0]==curboard[3]&&curboard[3]==curboard[6]&&curboard[0]!=0)
		{
			return curboard[0];
		}
		if(curboard[1]==curboard[4]&&curboard[4]==curboard[7]&&curboard[1]!=0)
		{
			return curboard[1];
		}
		if(curboard[2]==curboard[5]&&curboard[5]==curboard[8]&&curboard[2]!=0)
		{
			return curboard[2];
		}
		if(curboard[0]==curboard[4]&&curboard[4]==curboard[8]&&curboard[0]!=0)
		{
			return curboard[0];
		}
		if(curboard[2]==curboard[4]&&curboard[6]==curboard[8]&&curboard[2]!=0)
		{
			return curboard[2];
		}
			return 0;
    };
    //printable display of current selections;
    //shows each players marker
    string TTTController::getGameDisplay(){
        string out="\n====Board=====\n 0   1   2  \n""------------\n ";
		int *curboard=board.getBoard();
        for(int i=0;i<9;i++){
			if(curboard[i]==0){
 	   			out  += " ";
			}
			else{
				if(curboard[i]==1){
					out +=player1.getMarker();
				}
				else{
					out +=player2.getMarker();
				}
			}
            //not the end of board
			if((i+1)%3!=0){
				out += " | ";
			}
			else{
                //the end of board
				out +=" | ";
                out +=( '0'+((i+1)/3-1));
                out += "\n";
				out +="------------\n ";
			}
		}
   
        
        return out;
    };
