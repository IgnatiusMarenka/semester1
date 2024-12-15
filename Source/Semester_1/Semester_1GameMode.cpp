// Copyright Epic Games, Inc. All Rights Reserved.

#include "Semester_1GameMode.h"
#include "Semester_1Character.h"
#include "UObject/ConstructorHelpers.h"

ASemester_1GameMode::ASemester_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
