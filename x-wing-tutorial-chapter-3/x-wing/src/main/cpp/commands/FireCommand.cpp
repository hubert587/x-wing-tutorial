/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>

#include "Constants.h"

#include "commands/FireCommand.h"

FireCommand::FireCommand(frc::Joystick *stick, int button, LazerSubsystem* subsystem, std::string name) :
    m_stick(stick),
    m_button(button),
    m_subsystem{subsystem},
    m_name(name) {

    AddRequirements({ subsystem });
}

void FireCommand::Initialize() {
    wpi::outs() << "Initialize " << m_name << "\n";
    done = false;
    m_subsystem->RelayOn();
}

void FireCommand::Execute() {
    wpi::outs() << "Execute " << m_name << "\n";
    if(!done) {
        done = !m_stick->GetRawButton(GetButton());
    }
}

bool FireCommand::IsFinished() {
    if(done) {
        wpi::outs() << "IsFinsihed " << m_name << "\n";
        m_subsystem->RelayOff();
    }
    return done;
}
