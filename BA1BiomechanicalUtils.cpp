// Fill out your copyright notice in the Description page of Project Settings.


#include "BA1BiomechanicalUtils.h"

// Main function to calculate total muscle force using Hill's model
float UBA1BiomechanicalUtils::CalculateMuscleForce(const FBA1HillBoneParameters& JointParams)
{
    // Calculate the force components based on Hill's muscle model
    const float ForceLengthFactor = CalculateForceLengthFactor(JointParams.MuscleLength);
    const float ForceVelocityFactor = CalculateForceVelocityFactor(JointParams.ContractionVelocity, JointParams.MuscleMaxVelocity);
    const float ParallelElasticForce = CalculateParallelElasticForce(JointParams.MuscleLength, JointParams.PassiveElasticStiffness);
    const float SeriesElasticForce = CalculateSeriesElasticForce(JointParams.TendonLength, JointParams.TendonStiffness);

    // Return total muscle force
    return JointParams.Activation * ForceLengthFactor * ForceVelocityFactor + ParallelElasticForce + SeriesElasticForce;
}

// Force-Length relationship calculation
float UBA1BiomechanicalUtils::CalculateForceLengthFactor(float MuscleLength)
{
    // Gaussian curve representing muscle force-length relationship
    return FMath::Exp(-FMath::Pow((MuscleLength - 1.0f), 2.0f) / 0.45f);
}

// Force-Velocity relationship calculation
float UBA1BiomechanicalUtils::CalculateForceVelocityFactor(float ContractionVelocity, float MuscleMaxVelocity)
{
    // Linear relationship for muscle force-velocity
    return 1.0f - (ContractionVelocity / MuscleMaxVelocity);
}

// Passive Elastic Element (PEE) calculation
float UBA1BiomechanicalUtils::CalculateParallelElasticForce(float MuscleLength, float PassiveElasticStiffness)
{
    // Force exerted by the passive elastic component
    return PassiveElasticStiffness * (MuscleLength - 1.0f);
}

// Series Elastic Element (SEE) calculation
float UBA1BiomechanicalUtils::CalculateSeriesElasticForce(float TendonLength, float TendonStiffness)
{
    // Force exerted by the series elastic component
    return TendonStiffness * (TendonLength - 1.0f);
}

float UBA1BiomechanicalUtils::CalculateTorque(float MuscleForce, float MomentArmLength)
{
    return MuscleForce * MomentArmLength;
}

