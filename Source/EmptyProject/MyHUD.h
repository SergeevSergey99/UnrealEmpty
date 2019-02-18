// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
struct Message 
{
	FString message;
	FColor color;
	float time;
	Message()
	{
		time = 5.f;
		color = FColor::White;
	}
	Message(FString myMessage, FColor myColor, float myTime)
	{
		message = myMessage;
		time = myTime;
		color = myColor;
	}
};

UCLASS()
class EMPTYPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = HUDFont)
		UFont* hudFont;
	
	TArray<Message> messages;
	void addMessage(Message msg);

	virtual void DrawHUD() override;
};
