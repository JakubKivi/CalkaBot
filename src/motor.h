//control motors
void goForward(){
  Ma1_OFF;
  Ma2_ON;
  Mb1_OFF;
  Mb2_ON;
}

void goBackward(){
  Ma1_ON;
  Ma2_OFF;
  Mb1_ON;
  Mb2_OFF;
}

void hardStop(){
  Ma1_ON;
  Ma2_ON;
  Mb1_ON;
  Mb2_ON;
}
//slow stop, cutting voltage supply for motors
void slowStop(){
  Ma1_OFF;
  Ma2_OFF;
  Mb1_OFF;
  Mb2_OFF;
}

bool go(int x){   //0 - full   1 - optimal 2 -  left 3 -right
  if(x==0){
        direction?goForward():goBackward();
  }else if(x==1){

        if(direction){

              goForward();
              if(floorSensors() && checkFloor) return 0;
              delayMicroseconds(p);
              slowStop();
              if(floorSensors() && checkFloor) return 0;
              delayMicroseconds(100-p);

        }else if(!direction){

              goBackward();
              if(floorSensors() && checkFloor) return 0;
              delayMicroseconds(p);
              slowStop();
              if(floorSensors() && checkFloor) return 0;
              delayMicroseconds(100-p);

        }else error(9);

  }else if(x==2){

        if(direction){
            goForward();
            Ma1_OFF;
            Ma2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else if(!direction){
            goBackward();
            Ma1_OFF;
            Ma2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else error(11);

  }else if (x==3){

        if(direction){
            goForward();
            Mb1_OFF;
            Mb2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else if(!direction){
            goBackward();
            Mb1_OFF;
            Mb2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else error(12);
    }
  else error(13);
  return 1;
}


//floor sensors


//turn one of side until you don't touch floor and you don't see enemy
bool toSeeFront(){

    //if(!disA || !disB) return 1;
  if(disA && disB && disAR && disAL && disBL && disBR) return 0;

  if(!disBL || !disBR || !disB) direction=0;
  else if(!disAL || !disAR || !disA) direction=1;

  if(!disAL||!disBR){
    while(disA && disB){
      if(!go(2)) return 0;
    }
    return 1;
  }

  else if(!disAR||!disBL){
    while(disA && disB){
      if(!go(3)) return 0;
    }
    return 1;
  }
}

//to spin
void spin(){
    Ma1_OFF;
    Ma2_ON;
    Mb1_ON;
    Mb2_OFF;
    delay(1);
    slowStop();
    delay(3);
}

//to slowly spin
void slowSpin(){
    Ma1_OFF;
    Ma2_ON;
    Mb1_ON;
    Mb2_OFF;
    delay(5);
    slowStop();
    delay(10);
}
