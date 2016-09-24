/**************************************************************************************************/
/*  FILE NAME             :  main.cpp                                                             */
/*  PRINCIPAL AUTHOR      :  Fei Pei                                                              */
/*  SUBSYSTEM NAME        :  main                                                                 */
/*  MODULE NAME           :  View                                                                 */
/*  LANGUAGE              :  C++                                                                  */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2016/08/08                                                           */
/*  DESCRIPTION           :  This is a view and main of MVC                                       */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by PeiFei, 2016/08/08
 *
 */

#include<string>
#include<iostream>
#include"./model/Model.h"
#include"./controller/TTTController.h"
using namespace std;

int main(){
    string name1,name2,marker1,marker2;
    TTTController controller;
    
    cout << "Please input play1's name:" <<endl;
    cin >> name1;
    cout << "Please input play1's marker:" <<endl;
    cin >> marker1;
    cout << "Please input play2's name:" <<endl;
    cin >> name2;
    cout<<"Please input play2's marker:" <<endl;
    cin>> marker2;
    controller.createPlayer(name1, marker1, 1);
    controller.createPlayer(name2, marker2, 2);
    controller.startNewGame();
    int flag=1; // who's turn
    char location[3];
    while(controller.determineWinner()==0){
    cout <<  controller.getGameDisplay();
        if(flag==1){
            cout << "Please input player:"<< controller.getPlayerName(1)<<"'s selection of row and col,seperate by\",\" : like 1,1" <<endl;
            cin >> location;
            if(controller.setSelection(location[0]-'0',location[2]-'0',flag)){
                flag=2;
            }
            else{
                cout << "Wrong location, please input again!" <<endl;
            }
            
        }
        else{
            cout << "Please input player:"<< controller.getPlayerName(2)<<"'s selection of row and col,seperate by\",\" : like 1,1" <<endl;
            cin >> location;
            if(controller.setSelection(location[0]-'0',location[2]-'0',flag)){
                flag=1;
            }
            else{
                cout << "Wrong location, please input again!" <<endl;
            }
        }
    }
    cout <<  controller.getGameDisplay();
    if(controller.determineWinner()==1)cout << "winner is "<<controller.getPlayerName(1)<<"!"<<endl;
    if(controller.determineWinner()==2)cout << "winner is "<<controller.getPlayerName(2)<<"!"<<endl;
    if(controller.determineWinner()==3)cout << "Tie"<<"!"<<endl;
    return 0;    
}
