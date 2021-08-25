/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>

#include "Constants.h"

#include "commands/DeployLandingGearCommand.h"

DeployLandingGearCommand::DeployLandingGearCommand(int button, LandingGearSubsystem *subsystem, std::string name) :
    m_button(button),
    m_subsystem{subsystem},
    m_name(name) {

    AddRequirements({ subsystem });
}

void DeployLandingGearCommand::Initialize() {
    wpi::outs() << "Initialize " << m_name << "\n";
    //done = false;
    if(m_subsystem->IsLandingGearDown()) {
        m_subsystem->LandingGearUp();
    } else {
        m_subsystem->LandingGearDown();
    }
    
}

void DeployLandingGearCommand::Execute() {
    wpi::outs() << "Execute " << m_name << "\n";
    //do nothing
}

bool DeployLandingGearCommand::IsFinished() {
    wpi::outs() << "IsFinsihed " << m_name << "\n";
    return true;
}
