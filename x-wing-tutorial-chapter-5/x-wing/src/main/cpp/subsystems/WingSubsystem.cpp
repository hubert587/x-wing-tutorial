/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//#include <frc/Joystick.h>
//#include <frc/Relay.h>
#include <Constants.h>

#include "subsystems/WingSubsystem.h"

WingSubsystem::WingSubsystem(frc::Spark *wingMotor, frc::DigitalInput *wingOpenedDigitalInput, frc::DigitalInput *wingClosedDigitalInput) :
  m_wingMotor { wingMotor },
  m_wingOpenedDigitalInput { wingOpenedDigitalInput },
  m_wingClosedDigitalInput { wingClosedDigitalInput } {
  // Implementation of subsystem constructor goes here.
}

void WingSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void WingSubsystem::OpenWing() {
  m_wingMotor->Set(1);
}

bool WingSubsystem::IsWingOpened() {
  return !m_wingOpenedDigitalInput->Get();
}

void WingSubsystem::CloseWing() {
  m_wingMotor->Set(-1);
}

bool WingSubsystem::IsWingClosed() {
  return !m_wingClosedDigitalInput->Get();
}

void WingSubsystem::StopWing() {
  m_wingMotor->Set(0);
}

