/**************************************************************************************************/
/*  FILE NAME             :  Model.cpp                                                            */
/*  PRINCIPAL AUTHOR      :  Fei Pei                                                              */
/*  SUBSYSTEM NAME        :  Model                                                                */
/*  MODULE NAME           :  Model                                                                */
/*  LANGUAGE              :  C++                                                                  */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2016/08/08                                                           */
/*  DESCRIPTION           :  This is a model of MVC                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by PeiFei, 2016/08/08
 *
 */

#include"Model.h"
#include<stdlib.h>
using namespace std;
        Board::Board(){boardArr=new int[9];};
        void Board::setBoard(int  b[9]){
        //    board[i][j]=b[i][j];void Board::setBoard(int  b[3][3]){
        //    boardarr = (int **)malloc(3*3*sizeof(int));
        //    int i,j;
        //    for(i=0;i<3;i++){
        //        for(j=0;j<3;j++){
        //            boardarr[i][j]=b[i][j];
        //        }
            for(int i=0;i<9;i++){
               boardArr[i] = b[i];
            }
        };

        int* Board::getBoard(){
            return boardArr;
        };
        string Board::getStringBoard(){
            return stringLayout;
        };
        int Player::getId(){
            return id;
        };
        void Player::setId(int i){
        
        }; 
        string Player::getMarker(){
            return Player::marker;
        };
        void Player::setMarker(string m){
           Player:: marker=m;
        }; 
        string Player::getName(){
            return Player::name;
        };
        void Player::setName(string n){
           Player:: name=n; 
        }; 

