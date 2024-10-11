// Copyright 2024 Devhyper

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "EditorSelectionVolume.generated.h"

/**
 *	Volume that allows for selection of objects within it.
 */
UCLASS()
class UNREALSELECTIONVOLUME_API AEditorSelectionVolume : public AVolume
{
	GENERATED_BODY()
	
public:
	AEditorSelectionVolume();

protected:
	UFUNCTION()
	void GetAllActorsInVolume(TArray<AActor*>& OutActors);

public:
	UFUNCTION(CallInEditor)
	void Select();
};
