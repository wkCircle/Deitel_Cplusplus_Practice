#include "PythagoreanTriples.hpp"

int PythagoreanTriples(){
	int side1 = 0, side2 = 0, hypotenus = 0, count = 0;

	for (side1 = 1; side1 <= 500; side1++){
		for ( side2 = side1; side2 <= 500; side2++){
			for (hypotenus = side2; hypotenus <= 500; hypotenus++){

				if (side1*side1 + side2*side2 == hypotenus*hypotenus){
					count++;

					string str="";
					switch (count) {
						case 1:
							str = "st";
							break;
						case 2:
							str = "nd";
							break;
						case 3:
							str = "rd";
						default:
							str = "th";
							break;
					}

					cout << "The " << count << str << " right triangle is: " << side1 << ',' << side2 << ',' << hypotenus << endl;
				}



			}
		}

	}


	return 0;
}
