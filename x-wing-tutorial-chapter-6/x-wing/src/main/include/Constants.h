/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

//hardware ids for can bus
static constexpr int kCenterLazerRelayChannel = 0;

static constexpr int kTopLeftLazerRelayChannel = 1;
static constexpr int kTopRightLazerRelayChannel = 2;
static constexpr int kBottomLeftLazerRelayChannel = 3;
static constexpr int kBottomRightLazerRelayChannel = 4;

static constexpr int kLandingGearDoubleSolenoidChannelForward = 5;
static constexpr int kLandingGearDoubleSolenoidChannelReverse = 6;

static constexpr int kWingMotorChannel = 7;
static constexpr int kWingOpenDigitalInputChannel = 8;
static constexpr int kWingCloseDigitalInputChannel = 9;

//joystick
static constexpr int kJoystickPort = 0;

//joystick button mappings
static constexpr int kButtonGreen = 1;
static constexpr int kButtonRed = 2;
static constexpr int kButtonBlue = 3;
static constexpr int kButtonYellow = 4;
static constexpr int kButtonLeft = 5;
static constexpr int kButtonRight = 6;