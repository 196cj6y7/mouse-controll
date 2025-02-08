#include <Mouse.h>

void setup(){
	Serial.begin(9600);
	Mouse.begin();
}

void loop(){
	if (Serial.available()>0){
		// read command
		String command = Serial.readStringUntil('\n');
		
		// remove blank and line break symbol
		command.trim();
		
		if (command == "MOVE"){
			
			// mouse displacement
			int move_dist = 100;
			Serial.println("mouse move");
			
			// right side
			Mouse.move(move_dist,0,0);
			delay(500); // delay(millisecond)
			
			
			//left side
			Mouse.move(-move_dist, 0,0);
			delay(500);
			
			
			/* 回到原位，目前未知這段程式的功能
			Mouse.move(move_dist,0,0);
			delay(500);
			Mouse.move(-move_dist, 0,0);
			delay(500);
			*/
			Serial.println("complete");
		}
	}
}

			
