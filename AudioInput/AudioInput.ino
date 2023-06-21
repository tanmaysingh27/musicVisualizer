#include<fix_fft.h>

#define samples 12

int micInput = A1; // Audio Input
int baseline = 337;
int amplitude,mic;
// const int max_amplitude = 157;

char data[128],im[128];
char data_out[20];

void setup(){
Serial.begin(9600);
}

void loop(){
//Taking input of the microphone from the anlog input
for (int i = 0;i<128;i++){
mic = analogRead(micInput);  // Analog Input of the audio sample
amplitude = abs(mic-baseline); //Getitng the amplitude of the audio sample
data[i] = amplitude;
im[i] = 0; 
}

//Perform FFT to the sample
fix_fft(data, im, 7, 0);

for (int i = 0; i < 64; i++) {
  data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
}

//prints out the FFT in char forms in serial monitor
for (int i = 0; i < 20; i++){
  data_out[i] = (data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2])/3;
  Serial.print(data_out[i]);
}
}