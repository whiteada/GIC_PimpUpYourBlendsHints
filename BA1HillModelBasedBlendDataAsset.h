// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "BA1HillModelBasedBlendDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FBA1HillBoneParameters
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    FName JointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float Activation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float MuscleLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float ContractionVelocity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float MuscleMaxVelocity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float PassiveElasticStiffness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float TendonStiffness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float TendonLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float MomentArmLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    float TranslationalSensitivity;
};

UCLASS(BlueprintType)
class BIOMECHANICALANIMATION_API UBA1HillModelBasedBlendDataAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Hill Model")
    float GetMomentArmLength(const FName& JointName) const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HillModel")
    TArray<FBA1HillBoneParameters> JointParameters;

    const FBA1HillBoneParameters* GetJointParams(const FName& JointName) const
    {
        return JointParameters.FindByPredicate([&](const FBA1HillBoneParameters& Params)
            {
                return Params.JointName == JointName;
            });
    }
};
