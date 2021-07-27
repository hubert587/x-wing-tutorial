/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//#include <frc/Joystick.h>
//#include <frc/Relay.h>
#include <Constants.h>

#include "subsystems/LandingGearSubsystem.h"

LandingGearSubsystem::LandingGearSubsystem(frc::DoubleSolenoid *landingGearDoubleSolenoid) :
  m_landingGearDoubleSolenoid(landingGearDoubleSolenoid) {
  // Implementation of subsystem constructor goes here.
  LandingGearDown();
}

void LandingGearSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void LandingGearSubsystem::LandingGearDown() {
  m_landingGearDoubleSolenoid->Set(frc::DoubleSolenoid::kForward);
  wpi::outs() << "LandingGearSubsystem Down\n";
}

bool LandingGearSubsystem::IsLandingGearDown() {
  return m_landingGearDoubleSolenoid->Get() == frc::DoubleSolenoid::Value::kForward;
}

void LandingGearSubsystem::LandingGearUp() {
  m_landingGearDoubleSolenoid->Set(frc::DoubleSolenoid::kReverse);
  wpi::outs() << "LandingGearSubsystem Up\n";
}

bool LandingGearSubsystem::IsLandingGearUp() {
  return m_landingGearDoubleSolenoid->Get() == frc::DoubleSolenoid::Value::kReverse;
}

