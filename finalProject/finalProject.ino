//
//#include <FreqMeasure.h>
//
//void setup() {
//  Serial.begin(57600);
//  FreqMeasure.begin();
//}
//
//double sum=0;
//int count=0;
//
//void loop() {
//  if (FreqMeasure.available()) {
//    // average several reading together
//    sum = sum + FreqMeasure.read();
//    count = count + 1;
//    if (count > 30) {
//      float frequency= FreqMeasure.countToFrequency(sum / count);
//      Serial.println(frequency);
//      sum = 0;
//      count = 0;
//    }
//  }
//}



int pin = 14;

unsigned long duration;



void setup()

{
  Serial.begin(115200);

  pinMode(pin, INPUT);

}



void loop()

{

  duration = pulseIn(pin, HIGH);
  Serial.println(duration);
}

long getFrequency(int pin) {
  #define SAMPLES 4096
  long freq = 0;
  for(unsigned int j=0; j<SAMPLES; j++) 
  freq+= 500000/pulseIn(pin, HIGH, 250000);
  return freq / SAMPLES;
}
/*
#include <FreqPeriod.h>

double lfrq;
long int pp;

void setup() {
  Serial.begin(115200);
  FreqPeriod::begin();
  Serial.println("FreqPeriod Library Test");
}

void loop() {

  pp=FreqPeriod::getPeriod();
  if (pp ){

    Serial.print("period: ");
    Serial.print(pp);
    Serial.print(" 1/16us  /  frequency: ");

    lfrq= 16000400.0 / pp;
    printDouble(lfrq,6);
    Serial.print(" Hz");

    Serial.println("  ");
  }

}

//***************************************************************************
void printDouble( double val, byte precision){
  // prints val with number of decimal places determine by precision
  // precision is a number from 0 to 6 indicating the desired decimial places
  // example: lcdPrintDouble( 3.1415, 2); // prints 3.14 (two decimal places)

  if(val < 0.0){
    Serial.print('-');
    val = -val;
  }

  Serial.print (int(val));  //prints the int part
  if( precision > 0) {
    Serial.print("."); // print the decimal point
    unsigned long frac;
    unsigned long mult = 1;
    byte padding = precision -1;
    while(precision--)
      mult *=10;

    if(val >= 0)
      frac = (val - int(val)) * mult;
    else
      frac = (int(val)- val ) * mult;
    unsigned long frac1 = frac;
    while( frac1 /= 10 )
      padding--;
    while(  padding--)
      Serial.print("0");
    Serial.print(frac,DEC) ;
  }
}


*/



//#include <FreqPeriod.h>







/*
#include <FreqCounter.h>

void setup() {
  Serial.begin(57600);                    // connect to the serial port
  Serial.println("Frequency Counter");
}

long int frq;
void loop() {

 FreqCounter::f_comp= 8;             // Set compensation to 12
 FreqCounter::start(100);            // Start counting with gatetime of 100ms
 while (FreqCounter::f_ready == 0)         // wait until counter ready
 
 frq=FreqCounter::f_freq;            // read result
 Serial.println(frq);                // print result
 delay(20);
}
*/

/*
int analogPin = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //pinMode(analogPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);    // read the input pin
  Serial.println(val);
  delay(250);
}
*/

