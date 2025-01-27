#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
 	PrimaryActorTick.bCanEverTick = true;

	// 메시 컴포넌트 생성
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// 기본 값 설정
	MoveSpeed = 200.0f;
	MaxDistance = 1000.0f;
	Direction = 1;

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재 위치 계산
	FVector CurrentLocation = GetActorLocation();

	// 이동 거리 계산
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	// 최대 거리에 도달하면 방향 전환
	if (DistanceMoved >= MaxDistance)
	{
		Direction *= -1;
	}

	// 새로운 위치 계산
	FVector NewLocation = CurrentLocation + (MoveSpeed * DeltaTime * Direction * GetActorForwardVector());
	SetActorLocation(NewLocation);

}

