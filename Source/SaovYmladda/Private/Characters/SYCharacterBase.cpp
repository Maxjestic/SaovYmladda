// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SYCharacterBase.h"

// Sets default values
ASYCharacterBase::ASYCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASYCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASYCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASYCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

