//Заголовок библиотеки
#pragma once

//Библиотеки
#include <Arduino.h>
#include <Servo.h>

//Порты для управления сдвиговым регистром
#define EN 7
#define CLK 4
#define DAT 8
#define LATCH 12

//Порты для управления сервоприводами
#define A1 9
#define B1 10

//Порты для управления моторами
#define EN1 11
#define EN2 3
#define EN3 5
#define EN4 6

//Объекты
Servo servo;

//Класс для работы с моторами
class UDCMotor {
  //Публичные методы
  public:
    //Объект мотора
    UDCMotor(int PIN) {
      //Если порт в доступном диапозоне
      if(PIN > 0 and PIN <= 4) {
        //Присваеваем глобальную переменную локальной
        _M = PIN;
        //Инициализация
        pinMode(EN1, OUTPUT);
        pinMode(EN2, OUTPUT);
        pinMode(EN3, OUTPUT);
        pinMode(EN4, OUTPUT);
	pinMode(EN, OUTPUT);
        pinMode(CLK, OUTPUT);
        pinMode(DAT, OUTPUT);
        pinMode(LATCH, OUTPUT);
      }
    }
    //Для работы с мотором
    void start(int S, bool F) {
      //Выбор порта для работы
      switch(_M) {
	case 1:
          //Включаем порт M1
          digitalWrite(EN4, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 2);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 3);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
        case 2:
          //Включаем порт M2
          digitalWrite(EN3, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 1);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 4);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
        case 3:
          //Включаем порт M3
          digitalWrite(EN1, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 0);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 6);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
        case 4:
          //Включаем порт M4
          digitalWrite(EN2, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 5);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
          //Устанавливаем 1 на выходах
          bitSet(dat, 7);
          //Открываем порты для записи
          digitalWrite(LATCH, LOW);
          //Записываем информациб побитово
          shiftOut(DAT, CLK, LSBFIRST, dat);
          //Закрываем порты для записи
          digitalWrite(LATCH, HIGH);
      }
    }
  private:
    //Локальные переменные
    int _M;
    byte dat;
};

//Класс для работы с шаговыми двигателями
class UStepper {
  //Публичные методы
  public:
    //Объект сервопривода
    UStepper(int PIN) {
      //Если задан необходимый пин
      if(PIN == 1) {
        //Присваеваем порт
        _S = A1;
	//Инициализация
	pinMode(A1, OUTPUT);
        //Привязываем сервопривод к объекту
        servo.attach(_S);
      } 
      else if(PIN == 2) {
        //Присваеваем порт
        _S = B1;
	//Инициализация
	pinMode(B1, OUTPUT);
        //Привязываем сервопривод к объекту
        servo.attach(_S);
      }
    }
    //Для работы с сервоприводами
    void angle(int ang) {
      //Запоминаем угол
      _A = ang;
      //Поворачиваем севро
      servo.write(ang);
    }
    //Получение текущего положения
    int getAngle() {
      return _A;
    }
  //Приватные методы
  private:
    int _S;
    int _A;
};
