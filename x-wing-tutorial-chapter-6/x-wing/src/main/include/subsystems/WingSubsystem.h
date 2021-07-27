/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>
#include <frc/Relay.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Spark.h>
#include <frc/DigitalInput.h>

class WingSubsystem : public frc2::SubsystemBase {
 public:
  WingSubsystem(frc::Spark *wingMotor, frc::DigitalInput *wingOpenedDigitalInput, frc::DigitalInput *wingClosedDigitalInput);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc::Spark* GetWingMotor() { return m_wingMotor; }
  frc::DigitalInput* GetWingOpenedDigitalInput() { return m_wingOpenedDigitalInput; }
  frc::DigitalInput* GetWingClosedDigitalInput() { return m_wingClosedDigitalInput; }

  void OpenWing();
  bool IsWingOpened();
  void CloseWing();
  bool IsWingClosed();
  void StopWing();
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
  frc::Spark *m_wingMotor;
  frc::DigitalInput *m_wingOpenedDigitalInput;
  frc::DigitalInput *m_wingClosedDigitalInput;

};
