/****************************************************************************
*                                                                           *
* Project64 - A Nintendo 64 emulator.                                      *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2012 Project64. All rights reserved.                        *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#include "stdafx.h"
#include "N64SystemSettings.h"

int32_t CN64SystemSettings::m_RefCount = 0;

bool CN64SystemSettings::m_bShowCPUPer;
bool CN64SystemSettings::m_bBasicMode;
bool CN64SystemSettings::m_bLimitFPS;
bool CN64SystemSettings::m_bShowDListAListCount;
bool CN64SystemSettings::m_bDisplayFrameRate;
bool CN64SystemSettings::m_bSDEnable;
std::string CN64SystemSettings::m_sSDPath;

CN64SystemSettings::CN64SystemSettings()
{
    m_RefCount += 1;
    if (m_RefCount == 1)
    {
        g_Settings->RegisterChangeCB(UserInterface_BasicMode, NULL, RefreshSettings);
        g_Settings->RegisterChangeCB(UserInterface_ShowCPUPer, NULL, RefreshSettings);
        g_Settings->RegisterChangeCB(UserInterface_DisplayFrameRate, NULL, RefreshSettings);
        g_Settings->RegisterChangeCB(Debugger_ShowDListAListCount, NULL, RefreshSettings);
        g_Settings->RegisterChangeCB(GameRunning_LimitFPS, NULL, RefreshSettings);
        g_Settings->RegisterChangeCB(SDCard_Enable, NULL, RefreshSettings);
        g_Settings->RegisterChangeCB(SDCard_Path, NULL, RefreshSettings);

        RefreshSettings(NULL);
    }
}

CN64SystemSettings::~CN64SystemSettings()
{
    m_RefCount -= 1;
    if (m_RefCount == 0)
    {
        g_Settings->UnregisterChangeCB(UserInterface_BasicMode, NULL, RefreshSettings);
        g_Settings->UnregisterChangeCB(UserInterface_DisplayFrameRate, NULL, RefreshSettings);
        g_Settings->UnregisterChangeCB(UserInterface_ShowCPUPer, NULL, RefreshSettings);
        g_Settings->UnregisterChangeCB(Debugger_ShowDListAListCount, NULL, RefreshSettings);
        g_Settings->UnregisterChangeCB(GameRunning_LimitFPS, NULL, RefreshSettings);
        g_Settings->UnregisterChangeCB(SDCard_Enable, NULL, RefreshSettings);
        g_Settings->UnregisterChangeCB(SDCard_Path, NULL, RefreshSettings);
    }
}

void CN64SystemSettings::RefreshSettings(void *)
{
    m_bBasicMode = g_Settings->LoadBool(UserInterface_BasicMode);
    m_bDisplayFrameRate = g_Settings->LoadBool(UserInterface_DisplayFrameRate);
    m_bShowCPUPer = g_Settings->LoadBool(UserInterface_ShowCPUPer);
    m_bShowDListAListCount = g_Settings->LoadBool(Debugger_ShowDListAListCount);
    m_bLimitFPS = g_Settings->LoadBool(GameRunning_LimitFPS);
    m_bSDEnable = g_Settings->LoadBool(SDCard_Enable);
    m_sSDPath = g_Settings->LoadStringVal(SDCard_Path);
}