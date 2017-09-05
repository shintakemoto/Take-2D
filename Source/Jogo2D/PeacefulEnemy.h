// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "PeacefulEnemy.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API APeacefulEnemy : public AEnemy
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	//void MoveLeft(float Value);
	//void MoveRight(float Value);

	float speed;
	FVector CurrentLocation;
	
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
