// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleMenuWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Styling/SlateColor.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/CanvasPanelSlot.h"

bool UTitleMenuWidget::Initialize()
{
	bool bRet = Super::Initialize();

	{
		// EASY text
		UTextBlock* EasyButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		EasyButtonTextBlock->SetText(FText::FromString(TEXT("EASY")));
		EasyButtonTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Black));

		// EASY button
		SelectEasyButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		SelectEasyButton->AddChild(EasyButtonTextBlock);

		// HARD text
		UTextBlock* HardButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		HardButtonTextBlock->SetText(FText::FromString(TEXT("HARD")));
		HardButtonTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Black));

		// HARD button
		SelectHardButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		SelectHardButton->AddChild(HardButtonTextBlock);
	}

	UVerticalBox* VerticalBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());

	{
		// Add EASY button
		UVerticalBoxSlot* VerticalBoxSlot = VerticalBox->AddChildToVerticalBox(SelectEasyButton);
		VerticalBoxSlot->SetPadding(FMargin(0.0, 40.0, 0.0, 40.0));
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

		// Add HARD button
		VerticalBoxSlot = VerticalBox->AddChildToVerticalBox(SelectHardButton);
		VerticalBoxSlot->SetPadding(FMargin(0.0, 40.0, 0.0, 40.0));
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	}

	UCanvasPanel* RootCanvasPanel = Cast<UCanvasPanel>(GetRootWidget());
	if (RootCanvasPanel != nullptr)
	{
		UCanvasPanelSlot* CanvasPanelSlot = RootCanvasPanel->AddChildToCanvas(VerticalBox);
		CanvasPanelSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
		CanvasPanelSlot->SetPosition(FVector2D(-7.0f, 1.45f));
		CanvasPanelSlot->SetSize(FVector2D(500.0f, 300.0f));
		CanvasPanelSlot->SetAlignment(FVector2D(0.5f, 0.5f));
	}

	return bRet;
}


