/**************************************************************************************************/
/*  FILE NAME             :  Model.h                                                              */
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

#ifndef MODEL_H
#define MODEL_H
#include <string>
using namespace std;
class Board{  
    private:
        //row,col,player
        int *boardArr;
        string stringLayout;
    public:
        Board();
        void setBoard(int b[9]);
        int* getBoard();
        string getStringBoard();
};

class Player{
    private:
        int id;
        string marker;
        string name;
    public:
        int getId();
        void setId(int i);
        string getMarker();
        void setMarker(string m);
        string getName();
        void setName(string n);
};
#endif
