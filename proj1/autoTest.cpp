/**************************************************************************************************/
/*  FILE NAME             :  test.cpp                                                             */
/*  PRINCIPAL AUTHOR      :  Fei Pei                                                              */
/*  SUBSYSTEM NAME        :  test                                                                 */
/*  MODULE NAME           :  test                                                                 */
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
    int testNum=0;
    int passNum=0;
    TTTController controller;
    string name1 = "testname1";
    string marker1="x";
    string name2 = "testname2";
    string marker2="o";
    
	cout << "No."<<testNum++<<": test createPlayer and getPlayers' name" <<endl;
    controller.createPlayer(name1, marker1, 1);
    controller.createPlayer(name2, marker2, 2);
    if(controller.getPlayerName(1)==name1){
        passNum++;
        cout<<"test passed!"<<endl;
    }
	else{
		cout<<"test failed!"<<endl;
	}
    controller.startNewGame();
   	string testDisp;
	testDisp= 
	"\n====Board=====\n 0   1   2  \n------------\n   |   |   | 0\n------------\n   |   |   | 1\n------------\n   |   |   | 2\n------------\n ";
	cout << "No."<<testNum++<<": test initial getGameDisplay" <<endl;
    if(controller.getGameDisplay()==testDisp){
		passNum++;
		cout<<"test passed!"<<endl;
	}
	else{
		cout<<"test failed!"<<endl;
	}
	cout <<"test input board:"<< testDisp;
    cout <<"test output board:"<<controller.getGameDisplay();
			int i=2,j=4;
			cout << "No."<<testNum++<<": test right setSelection" <<endl;
            if(controller.setSelection(i,i,1)){
				passNum++;
				cout<<"test passed!"<<endl;
			}
			else{
				cout<<"test failed!"<<endl;
			}
			
			cout << "No."<<testNum++<<": test duplicated setSelection" <<endl;
            if(!controller.setSelection(i,i,1)){
				passNum++;
				cout<<"test passed!"<<endl;
			}
			else{
				cout<<"test failed!"<<endl;
			}
			
			cout << "No."<<testNum++<<": test invalid setSelection" <<endl;
            if(!controller.setSelection(i,j,1)){
				passNum++;
				cout<<"test passed!"<<endl;
			}
			else{
				cout<<"test failed!"<<endl;
			}
            	
			cout << "No."<<testNum++<<": test invalid setSelection" <<endl;
            if(!controller.setSelection(j,j,1)){
				passNum++;
				cout<<"test passed!"<<endl;
			}
			else{
				cout<<"test failed!"<<endl;
			}
	
	testDisp= 
	"\n====Board=====\n 0   1   2  \n------------\n   |   |   | 0\n------------\n   |   |   | 1\n------------\n   |   | x | 2\n------------\n ";
	cout << "No."<<testNum++<<": test  getGameDisplay:" <<endl;
    if(controller.getGameDisplay()==testDisp){
		passNum++;
		cout<<"test passed!"<<endl;
	}
	else{
		cout<<"test failed!"<<endl;
	}
	cout <<"test input board:"<< testDisp;
    cout <<"test output board:"<<controller.getGameDisplay();

	cout << "No."<<testNum++<<": test  winner:" <<endl;
	controller.setSelection(0,0,2);
	controller.setSelection(0,2,1);
	controller.setSelection(1,0,2);
	controller.setSelection(1,2,1);
	cout<< "Winner is "<<controller.determineWinner()<<endl;
    if(controller.determineWinner()==1){
		passNum++;
		cout<<"test passed!"<<endl;
	}
	else{
		cout<<"test failed!"<<endl;
	}

	testDisp= 
	"\n====Board=====\n 0   1   2  \n------------\n o | x | o | 0\n------------\n x | o | x | 1\n------------\n x | o | x | 2\n------------\n ";
	cout <<"test input board:"<< testDisp;
    cout <<"test output board:"<<controller.getGameDisplay();

	cout << "No."<<testNum++<<": test startNewGame &  tie:" <<endl;
	controller.startNewGame();
	controller.setSelection(2,2,1);
	controller.setSelection(0,0,2);
	controller.setSelection(0,1,1);
	controller.setSelection(0,2,2);
	controller.setSelection(1,0,1);
	controller.setSelection(1,1,2);
	controller.setSelection(1,2,1);
	controller.setSelection(2,1,2);
	controller.setSelection(2,0,1);
	
	cout<< "Winner is "<<controller.determineWinner()<<endl;
    if(controller.determineWinner()==3){
		passNum++;
		cout<<"test passed!"<<endl;
	}
	else{
		cout<<"test failed!"<<endl;
	}

	testDisp= 
	"\n====Board=====\n 0   1   2  \n------------\n o |   | x | 0\n------------\n o |   | x | 1\n------------\n   |   | x | 2\n------------\n ";
	cout <<"test input board:"<< testDisp;
    cout <<"test output board:"<<controller.getGameDisplay();
	
	cout <<"Total test number is: "<<testNum<<endl;
	cout <<"Passed test number is: "<<passNum<<endl;
	float p=0.0000;
	p=passNum/testNum * 100;
	cout << "Pass/fail percentage is: "<<p<<endl;
    return 0;    
}
