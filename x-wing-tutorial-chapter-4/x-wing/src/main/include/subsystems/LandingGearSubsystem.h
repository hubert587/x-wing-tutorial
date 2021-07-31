/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>
#include <frc/Relay.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>

class LandingGearSubsystem : public frc2::SubsystemBase {
 public:
  LandingGearSubsystem(frc::DoubleSolenoid *landingGearDoubleSolenoid);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc::DoubleSolenoid* GetLandingGearDoubleSolenoid() { return m_landingGearDoubleSolenoid; };

  void LandingGearDown();
  bool IsLandingGearDown();
  void LandingGearUp();
  bool IsLandingGearUp();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::DoubleSolenoid *m_landingGearDoubleSolenoid;
  
};
