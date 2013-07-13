/*TrafficLight

Simulates controlling two traffic lights using two groups of three LEDs.

*/

const int westRed = A0;
const int westYellow = A1;
const int westGreen = A2;

const int eastRed = A3;
const int eastYellow = A4;
const int eastGreen = A5;

#define DIRECTION_WEST 0
#define DIRECTION_EAST 1

#define LIGHT_RED 0
#define LIGHT_YELLOW 1
#define LIGHT_GREEN 2

#define LENGTH_OF_TIME_PER_GREEN 10000 /*10 seconds of green per direction*/
#define LENGTH_OF_TIME_PER_YELLOW 4000 /*4 seconds of yellow per direction*/
#define LENGTH_OF_EXTRA_TIME 1500 /*1.5 seconds extra to have both lights red*/

void setLight(int direction, int light)
{
  if(direction == DIRECTION_WEST) {
    /*Reset all the lights to off*/
    digitalWrite(westRed, LOW);
    digitalWrite(westYellow, LOW);
    digitalWrite(westGreen, LOW);
    
    /*find the one we need and turn it on*/
    switch(light) {
      case LIGHT_RED: {
          digitalWrite(westRed, HIGH);
          break;
      }
      
      case LIGHT_YELLOW: {
          digitalWrite(westYellow, HIGH);
          break;
      }
      
      case LIGHT_GREEN: {
          digitalWrite(westGreen, HIGH);
          break;
      }
        
    }
  }
  
  if(direction == DIRECTION_EAST) {
    /*Reset all the lights to off*/
    digitalWrite(eastRed, LOW);
    digitalWrite(eastYellow, LOW);
    digitalWrite(eastGreen, LOW);
    
    /*find the one we need and turn it on*/
    switch(light) {
      case LIGHT_RED: {
          digitalWrite(eastRed, HIGH);
          break;
      }
      
      case LIGHT_YELLOW: {
          digitalWrite(eastYellow, HIGH);
          break;
      }
      
      case LIGHT_GREEN: {
          digitalWrite(eastGreen, HIGH);
          break;
      }
        
    }
  }
}

void setup()
{
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
}

/*This loop simulates one cycle of each side allowing 
cars to pass.

For the documentation diagrams in this method, 0 = light off and X = light on*/

void loop()
{
  /* East     West

      X        0
      0        0
      0        X
 */
 
  setLight(DIRECTION_EAST, LIGHT_RED);
  setLight(DIRECTION_WEST, LIGHT_GREEN);
  
  delay(LENGTH_OF_TIME_PER_GREEN);
  
   /* East     West

      X        0
      0        X
      0        0
 */
  
  setLight(DIRECTION_WEST, LIGHT_YELLOW);
  
  delay(LENGTH_OF_TIME_PER_YELLOW);
  
   /* East     West

      X        X
      0        0
      0        0
 */
  
  setLight(DIRECTION_WEST, LIGHT_RED);
  
  delay(LENGTH_OF_EXTRA_TIME);
  
   /* East     West

      0        X
      0        0
      X        0
 */
  
  setLight(DIRECTION_EAST, LIGHT_GREEN);
  setLight(DIRECTION_WEST, LIGHT_RED);
  
  delay(LENGTH_OF_TIME_PER_GREEN);
  
   /* East     West

      0        X
      X        0
      0        0
 */
  
  setLight(DIRECTION_EAST, LIGHT_YELLOW);
  
  delay(LENGTH_OF_TIME_PER_YELLOW);
  
   /* East     West

      X        X
      0        0
      0        0
 */
  
   setLight(DIRECTION_EAST, LIGHT_RED);
  
  delay(LENGTH_OF_EXTRA_TIME);
  
}
