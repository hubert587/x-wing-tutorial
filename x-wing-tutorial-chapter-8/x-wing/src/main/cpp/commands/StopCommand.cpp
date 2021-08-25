/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>

#include "Constants.h"

#include "commands/StopCommand.h"

StopCommand::StopCommand(FlySubsystem *flySubsystem, std::string name) :
    m_flySubsystem(flySubsystem),
    m_name(name) {
        AddRequirements({ m_flySubsystem });
}

void StopCommand::Initialize() {
    m_flySubsystem->Hyperspace(false);
}

void StopCommand::Execute() {
    
}

bool StopCommand::IsFinished() {
    return false;
}
