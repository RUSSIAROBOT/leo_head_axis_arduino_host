# leo_head_axis_arduino_host #
### Arduino совместимый контроллер Teensy 3.2 в качестве хост контроллера управления поворотом осями головы робота в ROS ###

###### !!! ПРИМЕНЕНИЕ ХОСТ КОНТРОЛЛЕРА ИМЕЕТ ЭКСПЕРИМЕНТАЛЬНЫЙ ХАРАКТЕР И НЕ ОБЯЗАТЕЛЕН, Т.К. SmartStepper МОЖЕТ РАБОТАТЬ ПО USB(UART) И УПРАВЛЯТЬСЯ НЕПОСРЕДСТВЕННО С КОМПЬЮТЕРА!!! ######
 
 Поворот осуществляется с помощью "умных шаговых двигателей" SmartStepper(Nano Zero Stepper), т.е. Каждый шаговый двигатель имеет свой Arduino совместимый контроллер (Arduino Zero M0), драйвер двигателя и магнитный энкодер, для обратной связи.
 > Nano Zero Stepper имеет несколько интерфейсов:
 >> USB (программный последовательный порт)
 >>
 >> UART (аппаратный последовательный порт)
 >>> для включения внешнего управления по UART нужно расскоментировать строчку в прошивке (board.h) иначе аппаратный последовательный порт является журналом отладки.
 >>>
 >>> <#define CMD_SERIAL_PORT>
 
 Подробная информация о SmartStepper находится тут: https://github.com/Misfittech/nano_stepper
 
 ### Принцип работы хост контроллера ###
Хост контроллер выступает в качестве подписчика в ROS и пересылает значения Float32MultiArray на последовательный порт 2 и 3 в том виде виде, который понятен Nano Zero Stepper. 
> Например:
>> Для поворота головы робота вправо Nano Zero Stepper должен получить команду MOVE 300 30
>>
>> Для поворота головы робота влево Nano Zero Stepper должен получить команду MOVE -300 30
>>
>> где "300 -300"-это угол поворота, а "30" - скорость

Serial2 - осьX (по умолчанию значения от -300 до 300 и 30 скорость)

Serial3 - осьY (по умолчанию значения от 0 до -100 и 10 скорость)

## В дальнейших планах добавить функции: ##

+ автокалибровки осей по датчикам холла

+ сброс контроллеров шаговых двигателей по требованию

+ побликация положения энкодеров в топики

+ программное вкл./выкл. двигателей 

+ ускорение, топрожение двигателей при перемещении

 
 
 
 
 
 
 

 

