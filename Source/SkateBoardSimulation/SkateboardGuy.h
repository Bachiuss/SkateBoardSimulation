// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SkateboardGuy.generated.h"

UCLASS()
class SKATEBOARDSIMULATION_API ASkateboardGuy : public ACharacter
{
	GENERATED_BODY()

public:
	
	ASkateboardGuy();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Skate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Patienta;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Patienta1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Rueda0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Rueda1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Rueda2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Assets, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Rueda3;


public:
	// It returns the springarm's subobject
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	// It returns followcamera's subobject
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
