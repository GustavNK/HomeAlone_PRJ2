//Final tester
#include "..\HomeAlone\PC_Control.h";



int main() {

	PC_Control p1(false);

	Lamp l1('A', 1);
	p1.addModule(&l1);

	while (true) {
		p1.updateGui();
	}


}