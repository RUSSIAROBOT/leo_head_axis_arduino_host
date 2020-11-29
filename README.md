# leo_head_axis_arduino_host
### Teensy 3.2 в качестве хост контроллера управления поворотом осями головы робота по UART ###
 
 Поворот осуществляется с помощью "умных шаговых двигателей" SmartStepper(Nano Zero Stepper), т.е. Каждый шаговый двигатель имеет свой Arduino совместимый контроллер (Arduino Zero M0), драйвер двигателя и магнитным энкодером, для обратной связи.
 > SmartStepper имеет несколько интерфейсов:
 >> USB
 
 >> UART
 >>> для включения внешнего управления по UART нужно расскоментировать строчку в прошивке
 
 
 
 
 
 Controlling Two NanoStepper (Axis XY) controllers with Arduino
 
Контроллер с магнитным энкодером производства http://misfittech.net/
