#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


#include <ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>




int valY, valX;
int resetPinY = 11;
int resetPinX = 12;


ros::NodeHandle  nh;


//////публикатор в топик
////?????????????????????????????str_msg или парсить
std_msgs::String str_msg;
ros::Publisher headpos("headpos", &str_msg);








////////////функция выполнения движения//////////////////////

void headmove_Cb(const std_msgs::Float32MultiArray& move_msg) {
  Serial2.print("move ");
  Serial2.print(move_msg.data[0]);
  Serial2.println(" 30");

  Serial3.print("move ");
  Serial3.print(move_msg.data[1]);
  Serial3.println(" 10");
}

//////////////////////////////////////////////////////////////

////////////////////////получающий сообщение из topic pub
ros::Subscriber<std_msgs::Float32MultiArray> sub("headmove", headmove_Cb);


void setup() {

  Serial.begin(57600);
  while (!Serial) {
    Serial2.begin(115200);
    Serial3.begin(115200);

    digitalWrite(resetPinX, HIGH);
    pinMode(resetPinX, OUTPUT);
    digitalWrite(resetPinY, HIGH);
    pinMode(resetPinY, OUTPUT);

    nh.initNode();
    nh.subscribe(sub);

    nh.advertise(headpos);
  }
}





void loop() {

  reset_axis();

  nh.spinOnce();

  delay(2);
}

void pos_x() {

}

void pos_y() {

}

/////////////функция_сброса_контроллеров_шд//////////////////////
/////////////////////////////////////////////////////////////////

void reset_axis() {
  if (Serial2.available() < 0) {
    digitalWrite(resetPinX, LOW);
    delay(50);
    digitalWrite(resetPinX, HIGH);
  }
  if (Serial3.available() < 0) {
    digitalWrite(resetPinY, LOW);
    delay(50);
    digitalWrite(resetPinY, HIGH);
  }

}


/////////////функция_остановки_контроллеров_шд//////////////////////
/////////////////////////////////////////////////////////////////

void stop_axis() {
  Serial2.print("stop");
  Serial3.print("stop");

}


/////////////функция_установки_нуля_контроллеров_шд//////////////
/////////////////////////////////////////////////////////////////

void setzero_controllers_motors() {
  Serial2.print("setzero");
  Serial3.print("setzero");

}
