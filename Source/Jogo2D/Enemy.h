// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class JOGO2D_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

public:
	virtual void Tick(float Delta) override;

	virtual void ChangeDirection();
	virtual void Turn();
	
	class UBoxComponent* GetCollisionComp();

	FVector CurrentLocation;
	float speed = 150;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float TimeEnemy;
	
private:
	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* CollisionComp;

	FTimerHandle Change;

	

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
