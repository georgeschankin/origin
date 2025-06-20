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
	SpringArmComponent->SetUsingAbsoluteRotation(true); // ������ ������� �� �������� ����� ������
		//�������������� � ������ �������� ���������.� ����� Top - Down Shooter, ������ ������ ���������
		//�������� ��� �������.
	SpringArmComponent->TargetArmLength = ArmLength;
	SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f)); // ��������� FRotator ������ ���������
		//� ��������� ������������������ : Pitch, Yaw, Roll.��� ��� ��� ���������� ���������� �������� �� ��� Y, ��
		//������������� Pitch ��������.
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->bEnableCameraLag = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->SetFieldOfView(FOV);
	CameraComponent->bUsePawnControlRotation = false; // ������ ������� ��������� ������ ��������� 
	                                                  //������������ SpringArmComponent.

	//�������� ������ ��������� �������������� � ������� ������.��� ����� �
	//������������ ������ ����������� ��������� ��������� :
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void ALMADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	/*� ������ ������ �� ��������� ����� �� �������� ��� ������ ������� � ���� �� �����, ����� ��
	���������� �������, ������������� � ���������� GameplayStatics, ������� ����������
	SpawnDecalAtLocation.� �������� ���������� ��� ��������� ��������� �� ���, ��������, �������
	�������, � ����� ����� ������.� ��������� ����� �� ��������� ������ � ������� ����������
	����� ����.� ���������� ��� �� ����� ����� ��������, �� ��� �� ������� �� ��������� ����.*/
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
		FHitResult ResultHit; //��� ���������,
		//������������� � ���������� HitResult � �������� ���� � ����������� � ������������ �
		//���������� ���������, ���������, ����� ������ / ����� ������ � �.�.

		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, ResultHit); //��������� ��������� ����������, ������ � ��� �����
		//�����������, ECC_GameTraceChannel1, ��� ��� ����� ������� �� � ���� ������ � Project Settings >
		//Engine > Collision.����� ��������� ����� ���������� ������, ��������� � ���������� Config >
		//DefaultEngine.ini.��� � ��������� CollisionProfile � ��� ������ ���� ��������� ������ :
		//+DefaultChannelResponses = (Channel = ECC_GameTraceChannel1, DefaultResponse = ECR_Block, bTraceTyp
		//e = True, bStaticObject = False, Name = "Land")
		//������ �������� �������, ��� ����� �� ��������� ����������� ���������� ���� �����������.�
		//��������� �������� ��� ���������� ����������, ������� ������ ��������� �����������.

		float FindRotatorResultYaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),ResultHit.Location).Yaw; // ��������� ����������� ��������������
		//������ � ����� � ������� � ��� ���������� ������.��������� ����������� �� �������� �� ��� Z(Yaw)
		SetActorRotation(FQuat(FRotator(0.0f, FindRotatorResultYaw, 0.0f))); // ������������ ��������� �� ��� ������
		//� �������� ���������, ������� ��������� ��������� FQuat, ��� �� ���� ������������ ����� �������������� ������ - ����������
		if (CurrentCursor)
		{
			CurrentCursor->SetWorldLocation(ResultHit.Location); //������������ ���������� ����� ������ �������, ������������ �������� ���������.
			//� �������� ��������� ��������� ���� ����������, ��� ��� ����� ���������� � ������������
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
/*AddMovementInput � ��� ����������� �������, ������� � �������� ����������
����� ����������� �������� � ��������, �� ������� ����� �������� �����������.*/

// Called to bind functionality to input
void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*��� ����������� ����� �� ��������� ���� ������� ������������ ������� BindAxis,
		������� � �������� ������� ��������� ��������� �������� �������, ������� ��
		��������� � Project Settings > Engine > Input.
		������ �������� � ��� ������ � ������� ����� ������� �������.������ � ��� ������ ��
		�������, ������� ���������� ��� ��������� ������ � ����������.*/
	PlayerInputComponent->BindAxis("MoveForward", this, &ALMADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALMADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Zoom", this, &ALMADefaultCharacter::ZoomCamera);	
}

void ALMADefaultCharacter::ZoomCamera(float AxisValue)
{
	float NewZoom = CameraComponent->FieldOfView + AxisValue * ZoomSpeed * GetWorld()->DeltaTimeSeconds;
	CameraComponent->SetFieldOfView(FMath::Clamp(NewZoom, MinZoom, MaxZoom));
}

