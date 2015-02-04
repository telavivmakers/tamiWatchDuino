/*
 * Cycle a monitored computer when it is off. We have a welcome computer (EPIA)
 * whose BIOS is set to start on power on but doesn't always, but it does
 * always when we cycle the power via removing the plug and reinserting it.
 *
 * So this arduino will do that automatically.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int leds[2] = {13, 5};

void writeOutputs(int val)
{
  int i;
  for (i = 0 ; i < sizeof(leds) / sizeof(leds[0]); ++i) {
    digitalWrite(leds[i], val);
  }
}

void setupOutputLeds(void)
{
  int i;
  for (i = 0 ; i < sizeof(leds) / sizeof(leds[0]); ++i) {
    pinMode(leds[i], OUTPUT);     
  }
}

// the setup routine runs once when you press reset:
void setup() {
  setupOutputLeds();
}

// the loop routine runs over and over again forever:
void loop() {
  writeOutputs(HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  writeOutputs(LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
