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
#include "SettingsType-RomDatabase.h"
#include "SettingsType-RDBRamSize.h"

// == 8 ? 0x800000 : 0x400000

CSettingTypeRDBRDRamSize::CSettingTypeRDBRDRamSize(const char * Name, SettingID DefaultSetting ) :
    CSettingTypeRomDatabase(Name,DefaultSetting)
{
}

CSettingTypeRDBRDRamSize::CSettingTypeRDBRDRamSize(const char * Name, uint32_t DefaultValue ) :
    CSettingTypeRomDatabase(Name,DefaultValue)
{
}

CSettingTypeRDBRDRamSize::~CSettingTypeRDBRDRamSize()
{
}

bool CSettingTypeRDBRDRamSize::Load (uint32_t /*Index*/, bool & /*Value*/ ) const
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
    return false;
}

bool CSettingTypeRDBRDRamSize::Load (uint32_t Index, uint32_t & Value ) const
{
    uint32_t ulValue;
    stdstr Default;
    bool existsInRdb = g_Settings->LoadStringVal(Rdb_GoodName,Default);
    bool bRes = m_SettingsIniFile->GetNumber(m_SectionIdent->c_str(),m_KeyName.c_str(),m_DefaultValue,ulValue);
    if (!bRes)
    {
        LoadDefault(Index,ulValue);
    }
    if (existsInRdb)
    {
        Value = ulValue << 20;
    }
    else
    {
        //default to 8MB if ROM is not in the RDB
        Value = 0x800000;
    }
    return bRes;
}

bool CSettingTypeRDBRDRamSize::Load (uint32_t /*Index*/, std::string & /*Value*/ ) const
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
    return false;
}

//return the default values
void CSettingTypeRDBRDRamSize::LoadDefault (uint32_t /*Index*/, bool & /*Value*/   ) const
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
}

void CSettingTypeRDBRDRamSize::LoadDefault (uint32_t /*Index*/, uint32_t & Value  ) const
{
    Value = m_DefaultSetting == Default_Constant ? m_DefaultValue : g_Settings->LoadDword(m_DefaultSetting);
}

void CSettingTypeRDBRDRamSize::LoadDefault (uint32_t /*Index*/, std::string & /*Value*/ ) const
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
}

//Update the settings
void CSettingTypeRDBRDRamSize::Save (uint32_t /*Index*/, bool /*Value*/ )
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
}

void CSettingTypeRDBRDRamSize::Save (uint32_t /*Index*/, uint32_t Value )
{
    m_SettingsIniFile->SaveNumber(m_SectionIdent->c_str(),m_KeyName.c_str(),Value >> 20);
}

void CSettingTypeRDBRDRamSize::Save (uint32_t /*Index*/, const std::string & /*Value*/ )
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
}

void CSettingTypeRDBRDRamSize::Save (uint32_t /*Index*/, const char * /*Value*/ )
{
    g_Notify->BreakPoint(__FILE__, __LINE__);
}

void CSettingTypeRDBRDRamSize::Delete(uint32_t /*Index*/ )
{
    m_SettingsIniFile->SaveString(m_SectionIdent->c_str(),m_KeyName.c_str(),NULL);
}
