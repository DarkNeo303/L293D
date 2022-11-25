//Библиотеки
#include <L293D.h>

//Объекты
UDCMotor M1(1);

void setup() {
  
}

void loop() {
  //Плавное повышение скорости вращения
  for(int i = 0; i < 255; i++) {
    //Крутим мотор вперёд
    M1.start(i, true);
  }
}
