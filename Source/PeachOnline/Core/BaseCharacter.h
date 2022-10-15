// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PeachPlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class PEACHONLINE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();
private:
#pragma region Component
	UPROPERTY(Category=Character,VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"));
	UCameraComponent* PlayerCamera;

	UPROPERTY(Category=Character,VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"));
	USkeletalMeshComponent* Charamesh;

	UPROPERTY(Category=Character,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"));
	UAnimInstance* CLientArmsAnimBP;

	UPROPERTY(Category=Character,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"));
	UAnimInstance* ServerBodyAnimBP;
	
	UPROPERTY(BlueprintReadOnly,meta=(AllowPrivateAccess = "true"))
	APeachPlayerController* FPSPlayerController;
	
#pragma endregion

#pragma region Input
	
	void MoveRight(float AxisValue);
	void MoveForward(float AxisValue);
	
	void JumpAction();
	void StopJumpAction();

#pragma endregion 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
