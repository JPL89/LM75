// @File		LM75.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		15/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
#ifndef LM75_H
#define LM75_H

#define LM75_SLA_W 0x90
#define LM75_SLA_R 0x91

#define LM75_TEMP 0x00
#define LM75_CONF 0x01
#define LM75_TOS 0x03
#define LM75_THYST 0x02

void LM75_Write(unsigned char reg, unsigned char data)
{
    Wire_Start();
    Wire_Write(LM75_SLA_W);
    Wire_Write(reg);
    Wire_Write(data);
    Wire_Stop();
}

unsigned char LM75_Read(unsigned char reg)
{
    unsigned char data = 0;
    
    Wire_Start();
    Wire_Write(LM75_SLA_W);
    Wire_Write(reg);
    Wire_Start();
    Wire_Write(LM75_SLA_R);
    data = Wire_Nack();
    Wire_Stop();
    
    return ((unsigned char)(data));
}

#endif 
