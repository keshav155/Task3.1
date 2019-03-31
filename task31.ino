

int photosensor = A0; //light sensor connected to A0

// Declaring variables
int analogvalue;  
char light[30];


void setup() {

	Serial.begin();


	Particle.variable("analogvalue", analogvalue);

    Particle.variable("Stringlum", light);

    Particle.subscribe("hook-response/light", myHandler, MY_DEVICES);
}
void myHandler(const char *event, const char *data) {

}

void loop() {

    //Reading light value
	analogvalue = analogRead(photosensor);
	//Converting light value into string for particle.publish()
    sprintf(light,"%d", analogvalue);

    //Publishing to thinkspeak
	Particle.publish("light", light, PRIVATE);


	delay(30000);
}

