/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>

#include "Constants.h"

#include "commands/HyperspaceCommand.h"

HyperspaceCommand::HyperspaceCommand(frc::Joystick *stick, int button, FlySubsystem *flySubsystem, std::string name) :
    m_stick(stick),
    m_button(button),
    m_flySubsystem(flySubsystem),
    m_name(name) {
        AddRequirements({ m_flySubsystem });
}

void HyperspaceCommand::Initialize() {
    wpi::outs() << "Initialize " << m_name << "\n";
    m_flySubsystem->Hyperspace(true);
    done = false;
}

void HyperspaceCommand::Execute() {
    wpi::outs() << "Execute " << m_name << "\n";
    if(!done) {
        done = !m_stick->GetRawButton(GetButton());
    }
}

bool HyperspaceCommand::IsFinished() {
    if(done) {
        wpi::outs() << "IsFinished " << m_name << "\n";
        m_flySubsystem->Hyperspace(false);
    }
    return done;
}

