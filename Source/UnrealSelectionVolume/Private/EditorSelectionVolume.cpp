// Copyright 2024 Devhyper

#include "EditorSelectionVolume.h"
#include "Components/BrushComponent.h"
#include "Subsystems/EditorActorSubsystem.h"
#include "Kismet/KismetMathLibrary.h"

AEditorSelectionVolume::AEditorSelectionVolume()
{
	bIsEditorOnlyActor = true;
	GetBrushComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEditorSelectionVolume::GetAllActorsInVolume(TArray<AActor*>& OutActors)
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	TArray<AActor*> LevelActors = EditorActorSubsystem->GetAllLevelActors();
	for (AActor* Actor : LevelActors) {
		if (UKismetMathLibrary::IsPointInBox(Actor->GetActorLocation(), GetActorLocation(), GetBrushComponent()->GetCollisionShape().GetBox())) {
			OutActors.Add(Actor);
		}
	}
}

void AEditorSelectionVolume::Select()
{
	TArray<AActor*> ActorsToSelect;

	GetAllActorsInVolume(ActorsToSelect);

	for (AActor* Actor : ActorsToSelect) {
		GEditor->SelectActor(Actor, true, true);
	}
}
