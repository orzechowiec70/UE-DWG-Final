// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "DWGFinal/Public/DF_Character.h"



void ADF_PlayerController::BindInput(UEnhancedInputComponent* InputComp, ADF_Character* TestCharacter)
{
	InputComp->BindAction(MoveAction, ETriggerEvent::Triggered, TestCharacter, &ADF_Character::MoveCharacterWithInput);
	InputComp->BindAction(LookAction, ETriggerEvent::Triggered, TestCharacter, &ADF_Character::LookInput);
	InputComp->BindAction(JumpAction, ETriggerEvent::Triggered, TestCharacter, &ADF_Character::JumpInput);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}