// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LMADefaultCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ALMADefaultCharacter::ALMADefaultCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());	
	SpringArmComponent->SetUsingAbsoluteRotation(true); // данное условие не позволит нашей камере
		//поворачиваться в момент поворота персонажа.В жанре Top - Down Shooter, камера обычно находится
		//статично над игроком.
	SpringArmComponent->TargetArmLength = ArmLength;
	SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f)); // структура FRotator хранит аргументы
		//в следующей последовательности : Pitch, Yaw, Roll.Так как нам необходимо определить значения по оси Y, мы
		//устанавливаем Pitch аргумент.
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->bEnableCameraLag = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->SetFieldOfView(FOV);
	CameraComponent->bUsePawnControlRotation = false; // данное условие запрещаем камере вращаться 
	                                                  //относительно SpringArmComponent.

	//запретим нашему персонажу поворачиваться в сторону камеры.Для этого в
	//конструкторе класса прописываем следующие настройки :
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void ALMADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	/*В данной логике мы проверяем задан ли материал для нашего курсора и если он задан, тогда мы
	используем функцию, реализованную в библиотеке GameplayStatics, которая называется
	SpawnDecalAtLocation.В качестве параметров она принимает указатель на мир, материал, размеры
	курсора, а также точку спауну.В настоящее время мы размещаем курсор в нулевой координате
	нашей игры.В дальнейшем это не будет иметь значение, но это вы поймете на следующем шаге.*/
	if (CursorMaterial)
	{
		CurrentCursor = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), CursorMaterial, CursorSize, FVector(0));
	}
}

// Called every frame
void ALMADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		FHitResult ResultHit; //это структура,
		//реализованная в директории HitResult и хранящая поля с информацией о столкновении с
		//различными объектами, дастанцию, место начала / конца трейса и т.д.

		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, ResultHit); //принимает несколько аргументов, первый – это канал
		//трассировки, ECC_GameTraceChannel1, это тот канал который мы с вами задали в Project Settings >
		//Engine > Collision.Чтобы проверить номер созданного канала, перейдите в директорию Config >
		//DefaultEngine.ini.Где в категории CollisionProfile у вас должна быть следующая запись :
		//+DefaultChannelResponses = (Channel = ECC_GameTraceChannel1, DefaultResponse = ECR_Block, bTraceTyp
		//e = True, bStaticObject = False, Name = "Land")
		//Второй аргумент функции, это будет ли результат трассировки отображать след трассировки.И
		//последний аргумент это собственно переменная, которая хранит результат трассировки.

		float FindRotatorResultYaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),ResultHit.Location).Yaw; // результат соотношения местоположения
		//игрока и точки с которой у нас столкнулся курсор.Результат соотношения мы передаем по оси Z(Yaw)
		SetActorRotation(FQuat(FRotator(0.0f, FindRotatorResultYaw, 0.0f))); // поворачиваем персонажа на наш курсор
		//В качестве аргумента, функция принимаем структуру FQuat, что по сути представляет собой алгебраический объект - кватернион
		if (CurrentCursor)
		{
			CurrentCursor->SetWorldLocation(ResultHit.Location); //присоединяем визуальную часть нашего курсора, относительно текущего положения.
			//в качестве аргумента передадим туда положением, где наш трейс столкнулся с препятствием
		}
	}
}

void ALMADefaultCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ALMADefaultCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}
/*AddMovementInput – это стандартная функция, которая в качестве параметров
берет направление движения и величину, на которую будет умножено направление.*/

// Called to bind functionality to input
void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*Для корректного бинда на созданные нами функции используется функция BindAxis,
		которая в качестве первого аргумента принимает названия события, которое мы
		объявляли в Project Settings > Engine > Input.
		Второй аргумент – это объект в котором будет вызвано событие.Третий – это ссылка на
		функцию, которая вызывается при получении данных с клавиатуры.*/
	PlayerInputComponent->BindAxis("MoveForward", this, &ALMADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALMADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Zoom", this, &ALMADefaultCharacter::ZoomCamera);	
}

void ALMADefaultCharacter::ZoomCamera(float AxisValue)
{
	float NewZoom = CameraComponent->FieldOfView + AxisValue * ZoomSpeed * GetWorld()->DeltaTimeSeconds;
	CameraComponent->SetFieldOfView(FMath::Clamp(NewZoom, MinZoom, MaxZoom));
}

