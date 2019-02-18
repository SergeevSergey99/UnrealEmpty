// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC.h"
ANPC::ANPC(const class FPostConstructInitializeProperties& PCIP):
Super(PCIP) 
{
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this,
		TEXT("Proximity Sphere"));
	ProxSphere->AttachTo(RootComponent);
	ProxSphere->SetSphereRadius(32.f);
	//  од дл€ запуска ANPC::Prox(), когда эта сфера приближени€
	// пересекаетс€ с другим актором.
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox)
}
// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANPC::Prox_Implementation(AActor * OtherActor, UPrimitiveComponent * OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

