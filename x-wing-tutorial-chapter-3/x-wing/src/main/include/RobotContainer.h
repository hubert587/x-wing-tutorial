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

#include "subsystems/LazerSubsystem.h"

#include "commands/FireCommand.h"
#include "commands/QuadFireCommand.h"

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

  //subsystems
  LazerSubsystem m_centerLazerSubsystem;
  LazerSubsystem m_topLeftLazerSubsystem;
  LazerSubsystem m_topRightLazerSubsystem;
  LazerSubsystem m_bottomLeftLazerSubsystem;
  LazerSubsystem m_bottomRightLazerSubsystem;

  //comands
  FireCommand m_fireCenterCommand;
  QuadFireCommand m_quadFireCenterCommand;

  void ConfigureButtonBindings();
};
