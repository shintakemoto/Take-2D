// Fill out your copyright notice in the Description page of Project Settings.

#include "PeacefulEnemy.h"
#include "PaperSpriteComponent.h"
#include "Personagem.h"

void APeacefulEnemy::BeginPlay() {

	Super::BeginPlay();
	
	CurrentLocation = this->GetActorLocation();

	speed = 150.0f;
	TimeEnemy = 4.0f;
}

void APeacefulEnemy::OnOverlapBegin(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult & SweepResult)
{

	if (OtherActor != nullptr &&
		OtherActor->IsA(APersonagem::StaticClass())) {
		((APersonagem*)OtherActor)->Hurt();
		
	}

}

/*
void APeacefulEnemy::MoveLeft(float Value)
{
	FVector Movement = FVector(1.0f, 0.0f, 0.0f);
}

void APeacefulEnemy::MoveRight(float Value)
{
	//AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}
*/