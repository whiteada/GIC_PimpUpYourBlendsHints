// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BA1HillModelBasedBlendDataAsset.h"

#include "BA1BiomechanicalUtils.generated.h"

UCLASS()
class BIOMECHANICALANIMATION_API UBA1BiomechanicalUtils : public UObject
{
    GENERATED_BODY()

public:
    // High-level function to calculate muscle force
    UFUNCTION(BlueprintCallable, Category = "Biomechanics")
    static float CalculateMuscleForce(const FBA1HillBoneParameters& JointParams);

    // Force-Length relationship calculation
    UFUNCTION(BlueprintCallable, Category = "Biomechanics")
    static float CalculateForceLengthFactor(float MuscleLength);

    // Force-Velocity relationship calculation
    UFUNCTION(BlueprintCallable, Category = "Biomechanics")
    static float CalculateForceVelocityFactor(float ContractionVelocity, float MuscleMaxVelocity);

    // Passive Elastic Element (PEE) calculation
    UFUNCTION(BlueprintCallable, Category = "Biomechanics")
    static float CalculateParallelElasticForce(float MuscleLength, float PassiveElasticStiffness);

    // Series Elastic Element (SEE) calculation
    UFUNCTION(BlueprintCallable, Category = "Biomechanics")
    static float CalculateSeriesElasticForce(float TendonLength, float TendonStiffness);

    UFUNCTION(BlueprintCallable, Category = "Biomechanics")
    static float CalculateTorque(float MuscleForce, float MomentArmLength);
};
