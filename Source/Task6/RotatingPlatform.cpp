#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	// Tick 함수 활성화
 	PrimaryActorTick.bCanEverTick = true;

	// 메쉬 컴포넌트 생성 및 루트 컴포넌트로 설정
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	RotationSpeed = 50.0f;
	
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f); // yaw 회전
	AddActorLocalRotation(NewRotation);
}
