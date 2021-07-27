/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include <frc/Relay.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>
#include <frc/Spark.h>

//#include "subsystems/LazerSubsystem.h"

#include "commands/FireCommand.h"
#include "commands/QuadFireCommand.h"
#include "commands/DeployLandingGearCommand.h"
#include "commands/OpenWingCommand.h"
#include "commands/CloseWingCommand.h"
#include "commands/FlyCommand.h"
#include "commands/HyperspaceCommand.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  frc2::Command* GetTeleopCommand();

 private:

  //joystick
  frc::Joystick m_stick;

  //hardware
  frc::Relay m_centerLazerRelay;

  frc::Relay m_topLeftLazerRelay;
  frc::Relay m_topRightLazerRelay;
  frc::Relay m_bottomLeftLazerRelay;
  frc::Relay m_bottomRightLazerRelay;

  frc::DoubleSolenoid m_landingGearDoubleSolenoid;

  frc::Spark m_wingMotor;
  frc::DigitalInput m_wingOpenedDigitalInput;
  frc::DigitalInput m_wingClosedDigitalInput;

  //subsystems
  LazerSubsystem m_centerLazerSubsystem;

  LazerSubsystem m_topLeftLazerSubsystem;
  LazerSubsystem m_topRightLazerSubsystem;
  LazerSubsystem m_bottomLeftLazerSubsystem;
  LazerSubsystem m_bottomRightLazerSubsystem;

  LandingGearSubsystem m_landingGearSubsystem;

  WingSubsystem m_wingSubsystem;

  FlySubsystem m_flySubsystem;

  //comands
  FireCommand m_fireCenterCommand;
  QuadFireCommand m_quadFireCenterCommand;
  DeployLandingGearCommand m_deployLandingGearCommand;
  OpenWingCommand m_openWingCommand;
  CloseWingCommand m_closeWingCommand;
  FlyCommand m_flyCommand;
  HyperspaceCommand m_hyperspaceCommand;

  void ConfigureButtonBindings();
};
