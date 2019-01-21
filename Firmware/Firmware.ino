
// Include Libraries
    #include "Arduino.h"
    #include "NewPing.h"

//Sensor 4
    NewPing hcsr04_4(HCSR04_4_PIN_TRIG,HCSR04_4_PIN_ECHO);
    #define HCSR04_4_PIN_TRIG	9
    #define HCSR04_4_PIN_ECHO	8
//Sensor 3
    NewPing hcsr04_3(HCSR04_3_PIN_TRIG,HCSR04_3_PIN_ECHO);
    #define HCSR04_3_PIN_TRIG	7
    #define HCSR04_3_PIN_ECHO	6
//Sensor 2
    NewPing hcsr04_2(HCSR04_2_PIN_TRIG,HCSR04_2_PIN_ECHO);
    #define HCSR04_2_PIN_TRIG	5 
    #define HCSR04_2_PIN_ECHO	4
//Sensor 1 (Testing is done with this sensor)
    NewPing hcsr04_1(HCSR04_1_PIN_TRIG,HCSR04_1_PIN_ECHO);
    #define HCSR04_1_PIN_TRIG	3
    #define HCSR04_1_PIN_ECHO	2

//variables
    const int timeout = 10000;      //define timeout of 10 sec
    char menuOption = 0;
    long time0;
    float distance, duration;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    menuOption = menu();
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // Ultrasonic Sensor - HC-SR04 - Test Code
    // Read distance measurment from UltraSonic sensor           
    int hcsr04Dist = hcsr04.ping_cm();
    delay(10);
    Serial.print(F("Distance: ")); Serial.print(hcsr04Dist); Serial.println(F("[cm]"));

    }
    
    
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Ultrasonic Sensor - HC-SR04"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {
            if(c == '1') 
    			Serial.println(F("Now Testing Ultrasonic Sensor - HC-SR04"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

