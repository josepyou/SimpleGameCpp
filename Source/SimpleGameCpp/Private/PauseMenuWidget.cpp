// Fill out your copyright notice in the Description page of Project Settings.

#include "PauseMenuWidget.h"

void UPauseMenuWidget::CloseMenu()
{
	if (IsInViewport())
	{
		RemoveFromParent();
	}
}