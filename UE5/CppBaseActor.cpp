// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/Engine.h" //Чтобы вывести текст на экран игры, а не в консоль логов
#include "Engine/World.h"

// Sets default values
ACppBaseActor::ACppBaseActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
  SetRootComponent(Mesh); // делаем данную переменную корневой
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay() {
  Super::BeginPlay();
  // ShowInformation();
  InitialLocation = FVector::ZeroVector;
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ACppBaseActor::ShowInformation() {
  // логирование строковой информации
  UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);
  GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, PlayerName, true,
                                   FVector2D(2, 2)); // вывод на экран

  // логирование информации
  UE_LOG(LogTemp, Display, TEXT("CPP Base is here")); // просто инфа
  UE_LOG(LogTemp, Warning, TEXT("CPP Base warning")); // некритическая ошибка
  UE_LOG(LogTemp, Error, TEXT("CPP Base error")); // критическая ошибка

  // логирование числовой информации
  UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
  UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
  UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

void ACppBaseActor::SinMovement() {
  UWorld t;
  InitialLocation.Z = Amplitude * FMath::Sin(Frequency * t.GetTimeSeconds()) +
      InitialLocation.Z;
}
