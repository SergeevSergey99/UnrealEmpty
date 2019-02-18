// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"


void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	for (int i = messages.Num() - 1; i >= 0; i--)
	{
		float outputWidht = 100.f, outputHeight = 100.f, pad = 10.f;
		float messageH = outputHeight + 2.f * pad;
		float messageW = outputWidht + 2.f * pad;
		float x = 0.f, y = i * messageH;
		GetTextSize(messages[i].message, outputWidht, outputHeight, hudFont, 1.f);

		DrawRect(FLinearColor::Black, x, y, messageW, messageH);
		DrawText(messages[i].message, messages[i].color, x + pad, y + pad, hudFont);

		messages[i].time -= GetWorld()->GetDeltaSeconds();

		if (messages[i].time < 0)
		{
			messages.RemoveAt(i);
		}
	}
//	DrawLine(350, 170, 650, 170, FLinearColor::Blue);
//	DrawText("Test text", FLinearColor::White, 400, 100,hudFont);
	
}

