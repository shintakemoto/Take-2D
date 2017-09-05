// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "PaperSpriteComponent.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Components/BoxComponent.h"
#include "Personagem.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject
		<UPaperSpriteComponent>(TEXT("Sprite"));

	Sprite->SetupAttachment(RootComponent);
	CurrentLocation = this->GetActorLocation();

	speed = 150.0f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	Turn();
	
}

// Called every frame
void AEnemy::Tick(float Delta)
{
	Super::Tick(Delta);

	CurrentLocation.X += speed * Delta;
	SetActorLocation(CurrentLocation);
}

void AEnemy::ChangeDirection()
{
	GetWorldTimerManager().SetTimer(Change, this, &AEnemy::Turn, TimeEnemy, true);
	//Turn(); //trava a unreal
}

void AEnemy::Turn()
{
	speed = (speed) *(-1);
	ChangeDirection();
}


UBoxComponent * AEnemy::GetCollisionComp()
{
	return CollisionComp;
}

void AEnemy::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		//Personagem->method(this);
	}

}