// Traffic Light Simulation using millis() (non-blocking)
const int RED = 8, YELLOW = 9, GREEN = 10;

enum State { S_RED, S_RED_YELLOW, S_GREEN, S_YELLOW };
State state = S_RED;

unsigned long t0 = 0;
const unsigned long T_RED = 4000;
const unsigned long T_RED_YELLOW = 1000;
const unsigned long T_GREEN = 4000;
const unsigned long T_YELLOW = 1500;

void setLights(bool r, bool y, bool g) {
  digitalWrite(RED, r);
  digitalWrite(YELLOW, y);
  digitalWrite(GREEN, g);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  setLights(true, false, false);
  t0 = millis();
}

void loop() {
  unsigned long now = millis();
  switch(state) {
    case S_RED:
      if (now - t0 >= T_RED) {
        state = S_RED_YELLOW; t0 = now; setLights(true, true, false);
      }
      break;
    case S_RED_YELLOW:
      if (now - t0 >= T_RED_YELLOW) {
        state = S_GREEN; t0 = now; setLights(false, false, true);
      }
      break;
    case S_GREEN:
      if (now - t0 >= T_GREEN) {
        state = S_YELLOW; t0 = now; setLights(false, true, false);
      }
      break;
    case S_YELLOW:
      if (now - t0 >= T_YELLOW) {
        state = S_RED; t0 = now; setLights(true, false, false);
      }
      break;
  }
}
