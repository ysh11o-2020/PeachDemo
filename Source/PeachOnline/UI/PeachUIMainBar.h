// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PeachUIMainBar.generated.h"

/**
 * 
 */
class URichTextBlock;

UCLASS()
class PEACHONLINE_API UPeachUIMainBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* RichTxt_CountDown;
};
