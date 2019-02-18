// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class EMPTYPROJECT_API ANPC : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	ANPC();
	ANPC(const FPostConstructInitializeProperties & PCIP);


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = NPCParams)
		FString Npc_Name;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = NPCParams)
		FString Npc_Message;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = NPCParams)
		TSubobjectPtrDeprecated<class USphereComponent> ProxSphere;
	UFUNCTION(BlueprintNativeEvent, Category = NPCParams)
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComponent, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
