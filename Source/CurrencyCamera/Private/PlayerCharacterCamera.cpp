// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterCamera.h"

// Sets default values
APlayerCharacterCamera::APlayerCharacterCamera()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerCharacterCamera::SetCameraTransform(ETransformType TransformType, FTargetTransform TargetTransform, float TimelinePlayRate, UCurveFloat *NewCurveFloat, FDelegateTransformComplete Complete)
{
	switch (TransformType)
	{
	case ETransformType::Rotate:
		DelegateRotationComplete = Complete;
		break;
	case ETransformType::Move:
		DelegateMoveComplete = Complete;
		break;
	case ETransformType::Zoom:
		DelegateZoomComplete = Complete;
		break;
	case ETransformType::RotateAndMove:
		DelegateRotationComplete = Complete;
		break;
	case ETransformType::RotateAndZoom:
		DelegateRotationComplete = Complete;
		break;
	case ETransformType::MoveAndZoom:
		DelegateMoveComplete = Complete;
		break;
	default:
		DelegateRotationComplete = Complete;
		break;
	}

	BlueprintSetCameraTransform(TransformType, TargetTransform, TimelinePlayRate, NewCurveFloat);
}

void APlayerCharacterCamera::BlueprintSetCameraTransform_Implementation(ETransformType TransformType, FTargetTransform TargetTransform, float TimelinePlayRate, UCurveFloat *NewCurveFloat)
{

}

void APlayerCharacterCamera::RotationComplete()
{
	DelegateRotationComplete.ExecuteIfBound();
}

void APlayerCharacterCamera::MoveComplete()
{
	DelegateMoveComplete.ExecuteIfBound();

}

void APlayerCharacterCamera::ZoomComplete()
{
	DelegateZoomComplete.ExecuteIfBound();

}

void APlayerCharacterCamera::ClearAllBind()
{
	DelegateMoveComplete.Clear();
	DelegateRotationComplete.Clear();
	DelegateZoomComplete.Clear();
}

// Called when the game starts or when spawned
void APlayerCharacterCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacterCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacterCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//FTargetTransform::FTargetTransform()
//{
//	TargetArmLength = 0;
//	TargetLocation = FVector(0, 0, 0);
//	TargetRotation = FRotator(0, 0, 0);
//}
