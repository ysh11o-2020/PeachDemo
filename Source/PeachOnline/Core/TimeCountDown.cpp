// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/TimeCountDown.h"

// Sets default values
ATimeCountDown::ATimeCountDown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeCountDown::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeCountDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

