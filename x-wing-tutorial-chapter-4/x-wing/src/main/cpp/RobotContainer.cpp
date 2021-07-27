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
#include <frc/DoubleSolenoid.h>

#include "Constants.h"
#include "RobotContainer.h"

RobotContainer::RobotContainer() : 
  m_stick{ kJoystickPort },

  m_centerLazerRelay { kCenterLazerRelayChannel },
  m_topLeftLazerRelay { kTopLeftLazerRelayChannel },
  m_topRightLazerRelay { kTopRightLazerRelayChannel },
  m_bottomLeftLazerRelay { kBottomLeftLazerRelayChannel },
  m_bottomRightLazerRelay { kBottomRightLazerRelayChannel },
  m_landingGearDoubleSolenoid { kLandingGearDoubleSolenoidChannelForward, kLandingGearDoubleSolenoidChannelReverse },

  m_centerLazerSubsystem { &m_centerLazerRelay },
  m_topLeftLazerSubsystem { &m_topLeftLazerRelay },
  m_topRightLazerSubsystem { &m_topRightLazerRelay },
  m_bottomLeftLazerSubsystem { &m_bottomLeftLazerRelay },
  m_bottomRightLazerSubsystem { &m_bottomRightLazerRelay },
  m_landingGearSubsystem { &m_landingGearDoubleSolenoid },

  m_fireCenterCommand { &m_stick, kButtonRight, &m_centerLazerSubsystem, "FireCommand" },
  m_quadFireCenterCommand { 
    &m_stick, 
    kButtonLeft, 
    &m_topLeftLazerSubsystem,
    &m_topRightLazerSubsystem,
    &m_bottomLeftLazerSubsystem,
    &m_bottomRightLazerSubsystem, 
    "QuadFireCommand" },
  m_deployLandingGearCommand { kButtonYellow, &m_landingGearSubsystem, "Deploy Landing Gear" } {

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  
  wpi::outs() << "ConfigureButtonBindings()" << "\n";

  frc2::JoystickButton(&m_stick, m_fireCenterCommand.GetButton()).WhenPressed(m_fireCenterCommand);
  frc2::JoystickButton(&m_stick, m_quadFireCenterCommand.GetButton()).WhenPressed(m_quadFireCenterCommand);
  frc2::JoystickButton(&m_stick, m_deployLandingGearCommand.GetButton()).WhenPressed(m_deployLandingGearCommand);

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return NULL;
}

frc2::Command* RobotContainer::GetTeleopCommand() {
  // An example command will be run in autonomous
  return NULL;
}
