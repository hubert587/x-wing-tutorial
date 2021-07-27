/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//#include <frc/Joystick.h>
//#include <frc/Relay.h>
#include <Constants.h>

#include "subsystems/LazerSubsystem.h"

LazerSubsystem::LazerSubsystem(frc::Relay *relay) :
  m_relay(relay) {
  // Implementation of subsystem constructor goes here.
}

void LazerSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void LazerSubsystem::RelayOn() {
  m_relay->Set(frc::Relay::kOn);
  wpi::outs() << "RelayOn\n";
}

void LazerSubsystem::RelayOff() {
  m_relay->Set(frc::Relay::kOff);
  wpi::outs() << "RelayOff\n";
}

