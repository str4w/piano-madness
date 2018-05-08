
void setup() {
  //  Set MIDI baud rate:
  Serial1.begin(31250);
  for (int i=22;i<54;++i) {setit(i);}
}
void setit(int pinNo) {
    pinMode(pinNo,INPUT);
  digitalWrite(pinNo,HIGH);
}
//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(velocity);
}

void doit(int pinNo,int note) {
  if(digitalRead(pinNo)==0) {
    noteOn(0x90,note,127);
  }else{
    noteOn(0x90,note,0x00);
  }
}
  

void loop() {
  int basenote=0x1E;
  for (int i=22;i<54;++i) {doit(i,basenote-22+i);}
}


