// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppBaseActor.generated.h"
#include "GameFramework/Actor.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8 { Mobility, Static };

USTRUCT(BlueprintType)
struct FTransformStruct {
  GENERATED_USTRUCT_BODY()

  // местоположение
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector CurrentLocation = FVector::ZeroVector;

  // вращение
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FRotator CurrentRotator = FRotator::ZeroRotator;

  // размеры
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class BLUEPRINTS1_API ACppBaseActor : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ACppBaseActor();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  UPROPERTY(VisibleAnywhere)
  FString PlayerName = "George";

  UPROPERTY(EditAnywhere)
  int EnemyNum = 20;

  UPROPERTY(EditDefaultsOnly)
  float CurrentHealth = 57.7634;

  UPROPERTY(EditInstanceOnly)
  bool IsAlive = true;

  UPROPERTY(VisibleAnywhere)
  UStaticMeshComponent *Mesh; // визуальная оболочка класса

  UFUNCTION(BlueprintCallable)
  void ShowInformation();

  UFUNCTION(BlueprintCallable)
  void SinMovement();

   UPROPERTY(EditAnywhere)
  float Amplitude = 70.0f;

  UPROPERTY(EditAnywhere)
  float Frequency = 4.0f;

  FVector InitialLocation;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  /*private:
          void ShowInformation();*/
};
