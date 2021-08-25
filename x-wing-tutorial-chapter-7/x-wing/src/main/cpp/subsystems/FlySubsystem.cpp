/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//#include <frc/Joystick.h>
//#include <frc/Relay.h>
#include <Constants.h>

#include "subsystems/FlySubsystem.h"

FlySubsystem::FlySubsystem() {
  // Implementation of subsystem constructor goes here.
  Hyperspace(false);
}

void FlySubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void FlySubsystem::Hyperspace(bool on) {
  if(on) {
    wpi::outs() << "Hyperspace Engaged\n";

  } else {
    wpi::outs() << "Hyperspace Disengaged\n";

  }
}

