//
//  main.cpp
//  20170607 Chapter 8 Exercises
//
//  Created by ntueconRA on 2017/6/7.
//  Copyright © 2017年 Kai. All rights reserved.
//

#include "Chpater8_Exercises.hpp"


int main(int argc, const char * argv[]) {
	ExerCh8 HOTsommer;
	HOTsommer.TortoiseAndHare8_12();
	HOTsommer.Quicksort8_15();
	HOTsommer.MazeTraversal8_16();
	HOTsommer.GeneratingMazesRandomly8_17();
	
	SML GannBade;
	GannBade.MachineLanguageProgramming();
	
	
///////////////////////////////////////////////////////////////////////////
	othersPeople nice;
	while(1)    //in order for oher time to get instruction
	{
		nice.enterInstruction();    //
  
		while(1)
		{
			nice.loadRegister();    //
			nice.translateInstruction();    //
			nice.carryInstruction();
			
			if(nice.operationCode == HALT)    //
			{
				nice.computerDump();    //
				break;
			}
		}
  
		int i;
  
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("* * * enter 1 to again. * * *\n");
		printf("* * * enter 0 to exit. * * *\n");
		scanf("%d",&i);
		if(i==0)
			break;
	}
	//TODO

}
