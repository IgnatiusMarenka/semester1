// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADoor.h"
#include "GameFramework/Actor.h"
#include "AButton.generated.h"

UCLASS()
class SEMESTER_1_API AAButton : public AActor
{
	GENERATED_BODY()
	float _currentLocation = 5.0f;
	float _targetLocation = 1.0f;
	bool _isPressed = false;
	UPROPERTY(EditAnywhere)
	bool isToggling = false;
	
public:	
	// Sets default values for this actor's properties
	AAButton();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UArrowComponent> Arrow;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> ButtonMesh;

	bool GetIsToggling();
	void SetIsToggling();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleDoor();

};
