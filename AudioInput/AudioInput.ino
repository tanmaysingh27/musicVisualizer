int micInput = A1;

int baseline = 337;

int amplitude;
const int max_amplitude = 165;
// const int delta_ampliude = max_amplitude/


void setup(){
  Serial.begin(9600);
}

void loop(){
  mic = analogRead(micInput);
  amplitude = abs(mic-baseline);

  Serial.println(amplitude);
}