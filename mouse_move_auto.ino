#include<Mouse.h>

unsigned long lastMoveTime = 0;
const unsigned long idleThreshold = 180000;  // 閒置時間 (3 分鐘 = 180000 毫秒)
const unsigned long checkInterval = 10000;   // 每 10 秒檢查一次




void setup() {
  // put your setup code here, to run once:

  // start mouse simulate
  Mouse.begin();

  // wait system stable
  delay(2000);

  

  // record initial time
  lastMoveTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:

  static bool movedRecently = false;

    // 每 10 秒讓滑鼠微移動 1 像素，測試是否有人手動移動滑鼠
  if (millis() - lastMoveTime >= checkInterval) {
    Mouse.move(1, 0, 0);  // 向右移動 1 像素
    delay(50);
    Mouse.move(-1,0,0);
    delay(50);

    //如果滑鼠被手動移動，系統會忽略這個微小移動
    movedRecently = false;
    lastMoveTime = millis();
  }

  // if the mouse hasn't been moved for more than a specific time,
  // move the mouse.
  if(millis() - lastMoveTime >= idleThreshold){
    moveMouse();

    // timer reset
    lastMoveTime = millis();
  }

  // check mouse every second
  delay(1000);
}

void moveMouse(){
  int move_range = 100;

  // right 
  Mouse.move(move_range,0,0);
  delay(500);

  //left
  Mouse.move(move_range,0,0);
  delay(500);

}
