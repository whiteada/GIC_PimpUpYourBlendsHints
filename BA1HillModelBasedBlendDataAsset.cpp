// Fill out your copyright notice in the Description page of Project Settings.


#include "BA1HillModelBasedBlendDataAsset.h"

float UBA1HillModelBasedBlendDataAsset::GetMomentArmLength(const FName& JointName) const
{
    const FBA1HillBoneParameters* JointParams = JointParameters.FindByPredicate([&](const FBA1HillBoneParameters& Params) {
        return Params.JointName == JointName;
        });

    return JointParams ? JointParams->MomentArmLength : 0.0f;
}
