// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "AsteroidMenuButton.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAsteroidButtonClicked, UAsteroidMenuButton*, Button);

/**
 * 
 */
UCLASS()
class ASTEROID_API UAsteroidMenuButton : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UAsteroidMenuButton(const FObjectInitializer& ObjectInitializer); 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button", meta = (ExposeOnSpawn = true))
	FText ButtonText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	int32 FontSize = 24;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	FMargin TextPadding;
	
	UPROPERTY(BlueprintAssignable, Category="Button")
	FOnAsteroidButtonClicked OnClicked;
	
protected:

	virtual void NativeOnInitialized() override;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Label;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Button;
	

	virtual void NativePreConstruct() override;
	
	
private:
	UFUNCTION()
	void HandleButtonClicked();
	
};
