/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>

#include "Constants.h"

#include "commands/QuadFireCommand.h"

QuadFireCommand::QuadFireCommand(
    frc::Joystick *stick, 
    int button, 
    LazerSubsystem* topLeft, 
    LazerSubsystem* topRight, 
    LazerSubsystem* bottomLeft, 
    LazerSubsystem* bottomRight, 
    std::string name) :
    m_stick(stick),
    m_button(button),
    m_topLeft{topLeft},
    m_topRight{topRight},
    m_bottomLeft{bottomLeft},
    m_bottomRight{bottomRight},
    m_name(name) {

    AddRequirements({ topLeft, topRight, bottomLeft, bottomRight });
}

void QuadFireCommand::Initialize() {
    wpi::outs() << "Initialize " << m_name << "\n";
    done = false;
    m_topLeft->RelayOn();
    m_topRight->RelayOn();
    m_bottomLeft->RelayOn();
    m_bottomRight->RelayOn();
}

void QuadFireCommand::Execute() {
    wpi::outs() << "Execute " << m_name << "\n";
    if(!done) {
        done = !m_stick->GetRawButton(GetButton());
    }
}

bool QuadFireCommand::IsFinished() {
    if(done) {
        wpi::outs() << "IsFinsihed " << m_name << "\n";
        m_topLeft->RelayOff();
        m_topRight->RelayOff();
        m_bottomLeft->RelayOff();
        m_bottomRight->RelayOff();
    }
    return done;
}
