// Fill out your copyright notice in the Description page of Project Settings.


#include "DF_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "DWGFinal/Public/DF_PlayerCharacter.h"



void ADF_PlayerController::BindInput(UEnhancedInputComponent* InputComp, ADF_PlayerCharacter* TestCharacter)
{
	InputComp->BindAction(MoveAction, ETriggerEvent::Triggered, TestCharacter, &ADF_PlayerCharacter::MoveCharacterWithInput);
	InputComp->BindAction(MoveAction, ETriggerEvent::Completed, TestCharacter, &ADF_PlayerCharacter::StopMoveInput);
	InputComp->BindAction(LookAction, ETriggerEvent::Triggered, TestCharacter, &ADF_PlayerCharacter::LookInput);
	InputComp->BindAction(JumpAction, ETriggerEvent::Triggered, TestCharacter, &ADF_PlayerCharacter::JumpInput);
	InputComp->BindAction(JumpAction, ETriggerEvent::Completed, TestCharacter, &ADF_PlayerCharacter::StopJumpInput);
	InputComp->BindAction(RunningAction, ETriggerEvent::Started, TestCharacter, &ADF_PlayerCharacter::RunningInput);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}