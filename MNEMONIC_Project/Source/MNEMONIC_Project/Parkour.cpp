// Fill out your copyright notice in the Description page of Project Settings.

#include "Parkour.h"
#include "MNEMONIC_ProjectCharacter.h"

FParkour::FParkour()
{
}

void FParkour::SetCharacter(AMNEMONIC_ProjectCharacter* character)
{
	m_pCharacter = character;
}
