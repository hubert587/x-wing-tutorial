/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/FlySubsystem.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class HyperspaceCommand : public frc2::CommandHelper<frc2::CommandBase, HyperspaceCommand> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit HyperspaceCommand(frc::Joystick *stick, int button, FlySubsystem *flySubsystem, std::string name);

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;

  int GetButton() { return m_button; };

  void Disengage();

 private:
  bool done = false;
  frc::Joystick *m_stick;
  int m_button = -1;
  FlySubsystem *m_flySubsystem;
  std::string m_name;
};
