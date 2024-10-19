// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolRoute.h"

// Sets default values
APatrolRoute::APatrolRoute()
{
    SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline Component"));
}

void APatrolRoute::BeginPlay()
{
    if (SplineComponent) {
        patrolLength = SplineComponent->GetNumberOfSplinePoints();
        curPatrolPoint = 0;
    }
}

FVector APatrolRoute::GetNextPatrolLocation()
{
    FVector ret = FVector();
    if (SplineComponent) {
        ret = SplineComponent->GetLocationAtSplinePoint(curPatrolPoint++, ESplineCoordinateSpace::World);
        if (curPatrolPoint == patrolLength) {
            curPatrolPoint = 0;
        }
    }
    return ret;
}

