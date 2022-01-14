int NUM_SENSORS = 4;

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
  int d[NUM_SENSORS] = {analogRead (0), analogRead (1), analogRead (2), analogRead (3)};
  const float w[NUM_SENSORS] = {-2, -1, 1, 2};

  float ch = 0;
  for (int i = 0; i < NUM_SENSORS; i++) {
    ch += d[i] * w[i];
  }

  float zn = 0;
  for (int i = 0; i < NUM_SENSORS; i++) {
    zn += d[i];
  }

  float error = ch / zn;

  Serial.println(error);
  Serial.print("-----");
  Serial.print(analogRead (A0) );
  Serial.print("-----");
  Serial.print(analogRead (A1) );
  Serial.print("-----");
  Serial.print(analogRead (A2) );
  Serial.print("-----");
  Serial.print(analogRead (A3) );
  Serial.print("----- ");
}
