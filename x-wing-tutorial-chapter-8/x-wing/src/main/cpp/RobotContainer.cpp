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
  m_wingMotor { kWingMotorChannel },
  m_wingOpenedDigitalInput { kWingOpenDigitalInputChannel },
  m_wingClosedDigitalInput { kWingCloseDigitalInputChannel },

  m_centerLazerSubsystem { &m_centerLazerRelay },
  m_topLeftLazerSubsystem { &m_topLeftLazerRelay },
  m_topRightLazerSubsystem { &m_topRightLazerRelay },
  m_bottomLeftLazerSubsystem { &m_bottomLeftLazerRelay },
  m_bottomRightLazerSubsystem { &m_bottomRightLazerRelay },
  m_landingGearSubsystem { &m_landingGearDoubleSolenoid },
  m_wingSubsystem { &m_wingMotor, &m_wingOpenedDigitalInput, &m_wingClosedDigitalInput },
  m_flySubsystem {  },

  m_fireCenterCommand { &m_stick, kButtonRight, &m_centerLazerSubsystem, "FireCommand" },
  m_quadFireCenterCommand { 
    &m_stick, 
    kButtonLeft, 
    &m_topLeftLazerSubsystem,
    &m_topRightLazerSubsystem,
    &m_bottomLeftLazerSubsystem,
    &m_bottomRightLazerSubsystem, 
    "QuadFireCommand" },
  m_deployLandingGearCommand { kButtonYellow, &m_landingGearSubsystem, "Deploy Landing Gear" },
  m_openWingCommand { kButtonBlue, &m_wingSubsystem, "Opening Wing" }, 
  m_closeWingCommand { kButtonGreen, &m_wingSubsystem, "Closing Wing" },
  m_flyCommand { &m_stick, &m_flySubsystem, "Flying" },
  m_hyperspaceCommand { &m_stick, kButtonRed, &m_flySubsystem, "Hold on to something" },
  m_stopCommand { &m_flySubsystem, "Stop" } {

  m_flySubsystem.SetDefaultCommand(m_flyCommand);

  m_landCommand = new frc2::SequentialCommandGroup {
    frc2::PrintCommand("Starting the landing command group"),
    frc2::PrintCommand("Fly for 3 sec"),
    FlyCommand(&m_stick, &m_flySubsystem, "Flying").WithTimeout(3.0_s),
    frc2::PrintCommand("Close wings press DI to stop"),
    m_closeWingCommand,
    frc2::PrintCommand("If landing is not deploy, then deploy"),
    frc2::ConditionalCommand(m_deployLandingGearCommand, frc2::PrintCommand("Landing gear already down"), [this] { return m_landingGearSubsystem.IsLandingGearUp(); }),
    frc2::PrintCommand("Wait 5 sec"),
    frc2::WaitCommand(5.0_s),
    frc2::WaitUntilCommand([this] { return m_wingOpenedDigitalInput.Get(); }).BeforeStarting([] { std::cout << "Wait until you press DI for Wings Open\n"; }),
    frc2::PrintCommand("Functional command"),
    frc2::FunctionalCommand(
      [this] { std::cout << "Functional init\n"; },//init
      [this] { std::cout << "Functional execute\n"; },//execute
      [this] (auto end) { std::cout << "Functional ended\n"; },//end
      [this] { 
        std::cout << "Functional finish\n";
        return true; 
      },//end condition
      { &m_flySubsystem }//required
    ),
    frc2::PrintCommand("Finishing the landing command group")
  };

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  
  wpi::outs() << "ConfigureButtonBindings()" << "\n";

  frc2::JoystickButton(&m_stick, m_fireCenterCommand.GetButton()).WhenPressed(m_fireCenterCommand);
  frc2::JoystickButton(&m_stick, m_quadFireCenterCommand.GetButton()).WhenPressed(m_quadFireCenterCommand);
  frc2::JoystickButton(&m_stick, m_deployLandingGearCommand.GetButton()).WhenPressed(m_deployLandingGearCommand);
  frc2::JoystickButton(&m_stick, m_openWingCommand.GetButton()).WhenPressed(m_openWingCommand);
  frc2::JoystickButton(&m_stick, m_closeWingCommand.GetButton()).WhenPressed(m_closeWingCommand);
  frc2::JoystickButton(&m_stick, m_hyperspaceCommand.GetButton()).WhenPressed(m_hyperspaceCommand);

  frc2::JoystickButton(&m_stick, kButtonStart).WhenPressed(m_landCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return NULL;
}

frc2::Command* RobotContainer::GetTeleopCommand() {
  
  return NULL;
}
