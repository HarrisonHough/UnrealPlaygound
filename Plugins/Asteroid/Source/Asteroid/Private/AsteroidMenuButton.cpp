// Fill out your copyright notice in the Description page of Project Settings.
#include "AsteroidMenuButton.h"


UAsteroidMenuButton::UAsteroidMenuButton(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	ButtonText = FText::FromString(TEXT("Button"));
}

void UAsteroidMenuButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if (Label)
	{
		Label->SetText(ButtonText);
		Label->SetFontSize(FontSize);
	}
	
}
