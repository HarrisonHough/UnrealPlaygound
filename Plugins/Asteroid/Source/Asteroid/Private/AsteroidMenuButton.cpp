// Fill out your copyright notice in the Description page of Project Settings.
#include "AsteroidMenuButton.h"
#include "Components/ButtonSlot.h"


UAsteroidMenuButton::UAsteroidMenuButton(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	ButtonText = FText::FromString(TEXT("Button"));
}

void UAsteroidMenuButton::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (Button)
	{
		Button->OnClicked.AddDynamic(this, &UAsteroidMenuButton::HandleButtonClicked);
	}
}

void UAsteroidMenuButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (Label)
	{
		Label->SetText(ButtonText);
		Label->SetFontSize(FontSize);
		if (UButtonSlot* BtnSlot = Cast<UButtonSlot>(Label->Slot))
		{
			BtnSlot->SetPadding(FMargin(TextPadding)); // horizontal, vertical
		}
	}
	
}

void UAsteroidMenuButton::HandleButtonClicked()
{
	OnClicked.Broadcast(this);
}
