TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;
// pins
const int led1 = 2;
const int led2 = 3;
const int ENA = 8;
const int IN1 = 9;
const int IN2=10;
void setup() {
Serial.begin(115200);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
xTaskCreatePinnedToCore(
Task1code, // Task function.
&quot;Task1&quot;, // name of task.
10000, // Stack size of task
NULL, // parameter of the task
1, // priority of the task
&amp;Task1, // Task handle to keep track of created task
0); // pin task to core 0
xTaskCreatePinnedToCore(
Task2code, // Task function.
&quot;Task2&quot;, // name of task.
10000, // Stack size of task
NULL, // parameter of the task
1, // priority of the task
&amp;Task2, // Task handle to keep track of created task
1); // pin task to core 1
xTaskCreatePinnedToCore(
Task3code, // Task function.
&quot;Task3&quot;, // name of task.
10000, // Stack size of task
NULL, // parameter of the task
1, // priority of the task
&amp;Task3, // Task handle to keep track of created task
1); // pin task to core 1
}
//Task1code: blinks an LED every 700 ms
void Task1code( void * pvParameters ){
while(1)
{
digitalWrite(led1, HIGH);
delay(700);
digitalWrite(led1, LOW);
delay(700);
}

}
//Task2code: blinks an LED every 500 ms
void Task2code( void * pvParameters ){
while(1)
{
digitalWrite(led2, HIGH);
delay(500);
digitalWrite(led2, LOW);
delay(500);
}
}
void Task3code( void * pvParameters ){
while(1)
{
digitalWrite(ENA, HIGH);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
delay(2000);
// Stop the motor
digitalWrite(ENA, LOW);
delay(1000);
// Rotate the motor counterclockwise
digitalWrite(ENA, HIGH);
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
delay(2000);
// Stop the motor
digitalWrite(ENA, LOW);
delay(1000);
}
}
void loop()
{
}
