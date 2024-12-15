// Fill out your copyright notice in the Description page of Project Settings.


#include "AButton.h"

#include "ActorReferencesUtils.h"
#include "ADoor.h"
#include "MovieSceneTracksComponentTypes.h"
#include "ToolBuilderUtil.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAButton::AAButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Arrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetupAttachment(RootComponent);
	
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>("ButtonMesh");
	ButtonMesh->AttachToComponent(Arrow, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void AAButton::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_isPressed)
	{
		for (int i = 0; i < 2; i++)
		{
			auto newLocation = FMath::FInterpTo(_currentLocation, _targetLocation, DeltaTime, 5);

			//auto newAngle = FMath::Lerp(_currentAngle, _targetAngle, Deltatime);
			ButtonMesh->SetRelativeLocation(FVector(0, newLocation, 0));
			_currentLocation = newLocation;
			if (FMath::IsNearlyEqual(_currentLocation, _targetLocation, 0.1))
			{
				_isPressed = false;
				_targetLocation = 5.0f;
				_currentLocation = 1.0f;
			}
			if (i == 0)
			{
				_isPressed = true;
			}
		}
	}

}

void AAButton::ToggleDoor()
{
	_isPressed = true;
	isToggling = true;
	
}

bool AAButton::GetIsToggling()
{
	return isToggling;
}

