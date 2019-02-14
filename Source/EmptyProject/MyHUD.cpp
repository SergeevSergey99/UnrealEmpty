// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
	DrawLine(350, 170, 650, 170, FLinearColor::Blue);
	DrawText("Test text", FLinearColor::White, 400, 100,hudFont);
	
}
