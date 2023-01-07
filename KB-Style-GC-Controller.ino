#include "src/GC_key.h"

uint8_t GC_DATA_PIN = 21; //A3

uint8_t GC_LEFT = 2;
uint8_t GC_DOWN = 3;
uint8_t GC_RIGHT = 4;
uint8_t GC_Y = 5;
uint8_t GC_B = 6;
uint8_t GC_A = 7;
uint8_t GC_X = 8;
uint8_t GC_START = 9;
uint8_t GC_Z = 18; //A0
uint8_t GC_UP = 19; //A1

uint8_t CURSOL_MODE = 0;
bool REVERSE_MODE = false;


CGamecubeConsole GamecubeConsole(GC_DATA_PIN);      //Defines a "Gamecube Console" sending data to the console on pin 8
Gamecube_Data_t d = defaultGamecubeData;   //Structure for data to be sent to console

void setup() {
  // put your setup code here, to run once:
  pinMode(GC_LEFT, INPUT_PULLUP);
  pinMode(GC_DOWN, INPUT_PULLUP);
  pinMode(GC_RIGHT, INPUT_PULLUP);
  pinMode(GC_Y, INPUT_PULLUP); 
  pinMode(GC_B, INPUT_PULLUP);
  pinMode(GC_A, INPUT_PULLUP);
  pinMode(GC_X, INPUT_PULLUP);
  pinMode(GC_START, INPUT_PULLUP);
  pinMode(GC_Z, INPUT_PULLUP);
  pinMode(GC_UP, INPUT_PULLUP);
  d.report.a = 0;
  d.report.b = 0;
  d.report.x = 0;
  d.report.y = 0;
  d.report.start = 0;
  d.report.dleft = 0;
  d.report.dright = 0;
  d.report.ddown = 0;
  d.report.dup = 0;
  d.report.z = 0;
  d.report.r = 0;
  d.report.l = 0;
  d.report.xAxis = 128;
  d.report.yAxis = 128;
  d.report.cxAxis = 128;
  d.report.cyAxis = 128;
  d.report.left = 0;
  d.report.right = 0;
  
  CURSOL_MODE = 0;
  bool REVERSE_MODE = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  GamecubeConsole.write(d);
}
