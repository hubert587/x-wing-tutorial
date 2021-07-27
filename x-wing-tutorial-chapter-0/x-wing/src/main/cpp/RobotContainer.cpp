/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ProxyScheduleCommand.h>
#include <frc2/command/ConditionalCommand.h>
#include <frc2/command/SelectCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/PerpetualCommand.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "Constants.h"
#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  
  wpi::outs() << "ConfigureButtonBindings()" << "\n";

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return NULL;
}

frc2::Command* RobotContainer::GetTeleopCommand() {
  // An example command will be run in autonomous
  return NULL;
}
