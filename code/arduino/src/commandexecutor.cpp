#include "commandexecutor.h"

void CommandExecutor::init(MiniKame* kame) {
  robot = kame;
  running = false;
  autonomous = false;
}

void CommandExecutor::parseCommand(String command) {
  switch (command.toInt()){

    case 1:
    robot->run(1,550);
    running = 1;
    break;

    case 2:
    robot->moonwalkL(4,2000);
    break;

    case 3:
    robot->turnL(1,550);
    running = 1;
    break;

    case 4:
    robot->turnR(1,550);
    running = 1;
    break;

    case 5:
    //STOP
    running = 0;
    autonomous = false;
    robot->home();
    delay(100);
    break;

    case 6: //heart
    robot->pushUp(4,1400);
    break;

    case 7: //fire
    robot->upDown(4,250);
    break;

    case 8: //skull
    robot->jump();
    break;

    case 9: //cross
    robot->hello();
    break;

    case 10: //punch
    
    robot->frontBack(4,200);
    break;

    case 11: //mask
    robot->dance(2,1000);
    break;

    case 13: //autonomous mode toggle
    robot->zero();
    break;
    case 14: //autonomous mode toggle
    robot->walk(2,500);
    break;
    default:
    robot->home();
    delay(100);
    break;


  }
}

boolean CommandExecutor::isAutonomous() {
    return autonomous;
}
