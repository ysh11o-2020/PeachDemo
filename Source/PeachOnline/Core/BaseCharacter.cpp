// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
#pragma region Component


	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	if(CameraSpringArm)
	{
		CameraSpringArm->SetupAttachment(RootComponent);
	}
	PlayerCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	if(PlayerCamera)
	{
		PlayerCamera->SetupAttachment(CameraSpringArm);
		PlayerCamera->bUsePawnControlRotation = false;
	}
	
	/*FPSArmsmesh=CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPSArmsmesh"));
	if(FPSArmsmesh)
	{
		FPSArmsmesh->SetupAttachment(PlayerCamera);
		FPSArmsmesh->SetOnlyOwnerSee(true);
	}
	Mesh->SetOwnerNoSee(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);*/
#pragma endregion 

}

void ABaseCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(),AxisValue,false);
}

void ABaseCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(),AxisValue,false);
}

void ABaseCharacter::JumpAction()
{
	Jump();
}

void ABaseCharacter::StopJumpAction()
{
	StopJumping();
}




// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis(TEXT("MoveRight"),this,&ABaseCharacter::MoveRight);
	InputComponent->BindAxis(TEXT("MoveForward"),this,&ABaseCharacter::MoveForward);

	InputComponent->BindAxis(TEXT("Turn"),this,&ABaseCharacter::AddControllerYawInput);
	InputComponent->BindAxis(TEXT("LookUp"),this,&ABaseCharacter::AddControllerPitchInput);
	
	InputComponent->BindAction(TEXT("Run"),IE_Pressed,this,&ABaseCharacter::HighSpeedRunAction);
	InputComponent->BindAction(TEXT("Run"),IE_Released,this,&ABaseCharacter::NormalSpeedWalkAction);

	InputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&ABaseCharacter::JumpAction);
	InputComponent->BindAction(TEXT("Jump"),IE_Released,this,&ABaseCharacter::StopJumpAction);

}

void ABaseCharacter::ServerHighSpeedRunAction_Implementation()
{
	CharacterMovement->MaxWalkSpeed=600;
}

bool ABaseCharacter::ServerHighSpeedRunAction_Validate()
{
	return  true;
}

void ABaseCharacter::ServerNormalSpeedWalkAction_Implementation()
{
	CharacterMovement->MaxWalkSpeed=300;
}

bool ABaseCharacter::ServerNormalSpeedWalkAction_Validate()
{
	return true;
}

void ABaseCharacter::HighSpeedRunAction()
{
	CharacterMovement->MaxWalkSpeed=600;
	ServerHighSpeedRunAction();
}

void ABaseCharacter::NormalSpeedWalkAction()
{
	CharacterMovement->MaxWalkSpeed=300;
	ServerNormalSpeedWalkAction();
}


