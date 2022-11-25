//Библиотеки
#include <L293D.h>

//Объекты
UStepper S1(1);

void setup() {
  //Инициализация
  Serial.begin(9600);
}

void loop() {
  //Поворачиваем сервопривод на 90 градусов
  S1.angle(90);
  //Получаем угол поворота
  Serial.println(S1.getAngle());
}
