// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Curves/CurveFloat.h"
#include "PlayerCharacterCamera.generated.h"

DECLARE_DYNAMIC_DELEGATE(FDelegateTransformComplete);

//相机跳转方式
UENUM(BlueprintType, Category = "CurrencyCamera|PlayerPawnCamera")
enum class ETransformType : uint8
{
	All,
	Rotate,
	Move,
	Zoom,
	RotateAndMove,
	RotateAndZoom,
	MoveAndZoom
};

//跳转参数
USTRUCT(BlueprintType, Category = "CurrencyCamera|PlayerPawnCamera")
struct FTargetTransform
{
	GENERATED_USTRUCT_BODY()
	//GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector TargetLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator TargetRotation = FRotator(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TargetArmLength = 0;

	//FTargetTransform();

	//UFUNCTION(BlueprintPure)
		//bool IsZero();

};

UCLASS()
class CURRENCYCAMERA_API APlayerCharacterCamera : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacterCamera();

	UPROPERTY()
		FDelegateTransformComplete DelegateRotationComplete;

	UPROPERTY()
		FDelegateTransformComplete DelegateMoveComplete;

	UPROPERTY()
		FDelegateTransformComplete DelegateZoomComplete;

	UPROPERTY()
		UCurveFloat* NullCurve = nullptr;

	UFUNCTION(BlueprintCallable, Category = "CurrencyCamera|PlayerPawnCamera")
		void SetCameraTransform(ETransformType TransformType, FTargetTransform TargetTransform, float TimelinePlayRate, UCurveFloat *NewCurveFloat, FDelegateTransformComplete Complete);

	//蓝图重写此方法
	UFUNCTION(BlueprintNativeEvent, Category = "CurrencyCamera|PlayerPawnCamera")
		void BlueprintSetCameraTransform(ETransformType TransformType, FTargetTransform TargetTransform, float TimelinePlayRate, UCurveFloat *NewCurveFloat);
		void BlueprintSetCameraTransform_Implementation(ETransformType TransformType, FTargetTransform TargetTransform, float TimelinePlayRate, UCurveFloat *NewCurveFloat);

	//蓝图调用下面三个方法触发委托
	UFUNCTION(BlueprintCallable, Category = "CurrencyCamera|PlayerPawnCamera")
		void RotationComplete();

	UFUNCTION(BlueprintCallable, Category = "CurrencyCamera|PlayerPawnCamera")
		void MoveComplete();

	UFUNCTION(BlueprintCallable, Category = "CurrencyCamera|PlayerPawnCamera")
		void ZoomComplete();

	UFUNCTION(BlueprintCallable, Category = "CurrencyCamera|PlayerPawnCamera")
		void ClearAllBind();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
