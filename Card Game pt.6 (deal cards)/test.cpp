// include files
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "classes.h"

using namespace std;

int main()
{

	player plyr;
	card* crd = new card [5];
	card* crdhome = crd;
	
	for (int ndx = 0; ndx < 5; ndx++)
		{
			(*crd).setSuit("BOB");
			(*crd).setRank(13);
			(*crd).setLocation("MYHOUSE");
			crd++;
		}
		
	crd = crdhome;
		
	plyr.setHand(crd);
	
	plyr.printPlayer();

}
